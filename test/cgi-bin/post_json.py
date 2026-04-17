#!/usr/bin/env python3
import os
import sys
import json

content_length = int(os.environ.get('CONTENT_LENGTH', 0))
body = sys.stdin.read(content_length) if content_length > 0 else ''

print("Content-Type: text/plain\r")
print("\r")
print(f"REQUEST_METHOD={os.environ.get('REQUEST_METHOD', '')}")
print(f"CONTENT_TYPE={os.environ.get('CONTENT_TYPE', '')}")
print(f"CONTENT_LENGTH={os.environ.get('CONTENT_LENGTH', '')}")
print(f"QUERY_STRING={os.environ.get('QUERY_STRING', '')}")
print(f"BODY_RAW={body}")

if body:
    try:
        data = json.loads(body)
        print(f"JSON_VALID=true")
        for key, value in data.items():
            print(f"JSON_{key}={value}")
    except json.JSONDecodeError as e:
        print(f"JSON_VALID=false")
        print(f"JSON_ERROR={e}")
else:
    print("BODY_EMPTY=true")
