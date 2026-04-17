#!/bin/bash
# CGI GET and POST test suite
# Usage: ./test/run_cgi_tests.sh [host:port]
#   Default: localhost:8080
# Requires the server to already be running.

HOST="${1:-localhost:8080}"
BASE="http://$HOST"
PASS=0
FAIL=
0

# ─── helpers ───────────────────────────────────────────────────────────────────

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

pass() { echo -e "${GREEN}[PASS]${NC} $1"; ((PASS++)); }
fail() { echo -e "${RED}[FAIL]${NC} $1"; ((FAIL++)); }
section() { echo -e "\n${YELLOW}=== $1 ===${NC}"; }

# assert_contains <test_name> <response> <expected_substring>
assert_contains() {
    local name="$1" response="$2" expected="$3"
    if echo "$response" | grep -qF "$expected"; then
        pass "$name"
    else
        fail "$name — expected to find: '$expected'"
        echo "    Response was:"
        echo "$response" | head -20 | sed 's/^/    /'
    fi
}

# assert_status <test_name> <actual_status> <expected_status>
assert_status() {
    local name="$1" actual="$2" expected="$3"
    if [ "$actual" = "$expected" ]; then
        pass "$name (HTTP $actual)"
    else
        fail "$name — expected HTTP $expected, got HTTP $actual"
    fi
}

# ─── GET tests ──────────────────────────────────────────────────────────────────

section "GET — basic (no query string)"
R=$(curl -s "$BASE/cgi-bin/get_test.py")
assert_contains "REQUEST_METHOD=GET"      "$R" "REQUEST_METHOD=GET"
assert_contains "QUERY_STRING is empty"   "$R" "QUERY_STRING="
assert_contains "PARAM_COUNT=0"           "$R" "PARAM_COUNT=0"

section "GET — single query parameter"
R=$(curl -s "$BASE/cgi-bin/get_test.py?name=Alice")
assert_contains "QUERY_STRING=name=Alice"  "$R" "QUERY_STRING=name=Alice"
assert_contains "PARAM_COUNT=1"            "$R" "PARAM_COUNT=1"
assert_contains "PARAM_name=Alice"         "$R" "PARAM_name=Alice"

section "GET — multiple query parameters"
R=$(curl -s "$BASE/cgi-bin/get_test.py?a=1&b=2&c=3")
assert_contains "PARAM_COUNT=3"  "$R" "PARAM_COUNT=3"
assert_contains "PARAM_a=1"      "$R" "PARAM_a=1"
assert_contains "PARAM_b=2"      "$R" "PARAM_b=2"
assert_contains "PARAM_c=3"      "$R" "PARAM_c=3"

section "GET — URL-encoded special characters"
R=$(curl -s "$BASE/cgi-bin/get_test.py?msg=hello%20world&name=O%27Brien")
assert_contains "QUERY_STRING contains msg"   "$R" "msg=hello"
assert_contains "PARAM_msg decoded"           "$R" "PARAM_msg=hello world"
assert_contains "PARAM_name decoded"          "$R" "PARAM_name=O'Brien"

section "GET — CONTENT_LENGTH and CONTENT_TYPE should be absent"
R=$(curl -s "$BASE/cgi-bin/get_test.py")
assert_contains "CONTENT_LENGTH empty" "$R" "CONTENT_LENGTH="
assert_contains "CONTENT_TYPE empty"   "$R" "CONTENT_TYPE="

# ─── POST tests ─────────────────────────────────────────────────────────────────

section "POST — form-encoded body"
R=$(curl -s -X POST \
    -H "Content-Type: application/x-www-form-urlencoded" \
    -d "username=bob&password=secret" \
    "$BASE/cgi-bin/post_test.py")
assert_contains "REQUEST_METHOD=POST"               "$R" "Method: POST"
assert_contains "Body contains username"            "$R" "username=bob"
assert_contains "Content-Length set"                "$R" "Content-Length:"

section "POST — JSON body"
R=$(curl -s -X POST \
    -H "Content-Type: application/json" \
    -d '{"key":"value","number":42}' \
    "$BASE/cgi-bin/post_json.py")
assert_contains "REQUEST_METHOD=POST"     "$R" "REQUEST_METHOD=POST"
assert_contains "JSON valid"              "$R" "JSON_VALID=true"
assert_contains "JSON key=value"          "$R" "JSON_key=value"
assert_contains "JSON number=42"          "$R" "JSON_number=42"

section "POST — empty body (Content-Length: 0)"
R=$(curl -s -X POST \
    -H "Content-Type: application/x-www-form-urlencoded" \
    -H "Content-Length: 0" \
    "$BASE/cgi-bin/post_json.py")
assert_contains "REQUEST_METHOD=POST"   "$R" "REQUEST_METHOD=POST"
assert_contains "Body is empty"         "$R" "BODY_EMPTY=true"

section "POST — query string AND body (mixed)"
R=$(curl -s -X POST \
    -H "Content-Type: application/x-www-form-urlencoded" \
    -d "body_param=fromBody" \
    "$BASE/cgi-bin/mixed_test.py?url_param=fromURL")
assert_contains "REQUEST_METHOD=POST"           "$R" "REQUEST_METHOD=POST"
assert_contains "URL query param present"       "$R" "QUERY_url_param=fromURL"
assert_contains "Body param present"            "$R" "BODY_body_param=fromBody"

section "POST — QUERY_STRING empty when no URL params"
R=$(curl -s -X POST \
    -H "Content-Type: application/x-www-form-urlencoded" \
    -d "x=1" \
    "$BASE/cgi-bin/mixed_test.py")
assert_contains "QUERY_STRING empty"     "$R" "QUERY_STRING="
assert_contains "BODY_x=1"              "$R" "BODY_x=1"

# ─── HTTP status / error scenarios ──────────────────────────────────────────────

section "GET — 404 for non-existent CGI script"
STATUS=$(curl -s -o /dev/null -w "%{http_code}" "$BASE/cgi-bin/does_not_exist.py")
assert_status "404 for missing script" "$STATUS" "404"

section "GET — CGI runtime error returns 500"
STATUS=$(curl -s -o /dev/null -w "%{http_code}" "$BASE/cgi-bin/runtime_error.py")
assert_status "500 for runtime error" "$STATUS" "500"

section "GET — CGI syntax error returns 500"
STATUS=$(curl -s -o /dev/null -w "%{http_code}" "$BASE/cgi-bin/syntax_error.py")
assert_status "500 for syntax error" "$STATUS" "500"

# ─── Summary ─────────────────────────────────────────────────────────────────

echo ""
echo -e "Results: ${GREEN}$PASS passed${NC}, ${RED}$FAIL failed${NC}"
[ $FAIL -eq 0 ] && exit 0 || exit 1
