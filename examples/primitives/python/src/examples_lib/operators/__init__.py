"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 12/07/2021-12:30.
Please do not change it manually.
"""
from .counter_pygen import Counter

import json


def pretty_print(json_str):
    parsed = json.loads(json_str)
    print(json.dumps(parsed, indent=4, sort_keys=True))