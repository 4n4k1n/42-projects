#!/usr/bin/env python3
import os
import sys
from urllib.parse import parse_qs, unquote_plus

query_string = os.environ.get('QUERY_STRING', '')
params = parse_qs(query_string) if query_string else {}

print("Content-Type: text/plain\r")
print("\r")
print(f"REQUEST_METHOD={os.environ.get('REQUEST_METHOD', '')}")
print(f"QUERY_STRING={query_string}")
print(f"CONTENT_LENGTH={os.environ.get('CONTENT_LENGTH', '')}")
print(f"CONTENT_TYPE={os.environ.get('CONTENT_TYPE', '')}")
print(f"SCRIPT_FILENAME={os.environ.get('SCRIPT_FILENAME', '')}")
print(f"PARAM_COUNT={len(params)}")
for key, values in sorted(params.items()):
    print(f"PARAM_{key}={','.join(values)}")
