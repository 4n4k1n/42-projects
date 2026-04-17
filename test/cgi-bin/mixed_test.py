#!/usr/bin/env python3
# Tests POST with both a query string AND a body (both should be accessible)
import os
import sys
from urllib.parse import parse_qs

query_string = os.environ.get('QUERY_STRING', '')
content_length = int(os.environ.get('CONTENT_LENGTH', 0))
body = sys.stdin.read(content_length) if content_length > 0 else ''

query_params = parse_qs(query_string) if query_string else {}
body_params  = parse_qs(body)         if body         else {}

print("Content-Type: text/plain\r")
print("\r")
print(f"REQUEST_METHOD={os.environ.get('REQUEST_METHOD', '')}")
print(f"QUERY_STRING={query_string}")
print(f"QUERY_PARAM_COUNT={len(query_params)}")
for key, values in sorted(query_params.items()):
    print(f"QUERY_{key}={','.join(values)}")
print(f"BODY_RAW={body}")
print(f"BODY_PARAM_COUNT={len(body_params)}")
for key, values in sorted(body_params.items()):
    print(f"BODY_{key}={','.join(values)}")
