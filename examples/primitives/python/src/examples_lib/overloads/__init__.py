"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 07/28/2021-18:25.
Please do not change it manually.
"""
from .employee_pygen import Employee
from .utils_pygen import Utils

import json


def pretty_print(json_str):
    parsed = json.loads(json_str)
    print(json.dumps(parsed, indent=4, sort_keys=True))