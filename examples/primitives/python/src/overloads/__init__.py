"""
This file was generated by iegen on 05/31/2021-18:05.
Please do not change it manually.
"""
from .utils_pygen import Utils
import json
def pretty_print(json_str):
    parsed = json.loads(json_str)
    print(json.dumps(parsed, indent=4, sort_keys=True))
