# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
CppBind is a tool to generate c++ bindings for various languages.
"""
import datetime
import logging
import os
import sys
from logging import getLevelName

from cppbind.common.config import config as default_config, PROJECT_CONFIG_DIR
from cppbind.common.error import Error

BANNER_LOGO = """
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
"""

LOGGING_FORMAT = '%(asctime)s:(%(levelname)s) %(message)s'
DATETIME_FORMAT = '%m/%d/%Y-%H:%M'
DATETIME_REGEX = r'^(0[1-9]|1[0-2])/([012][0-9]|3[0-1])/(20[0-9][0-9])-([01][0-9]|2[0-4]):([012345][0-9])'
LOG_LEVELS = ['DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL']


def init_logger(log_level=None):
    log_level = log_level or default_config.logging.level
    log_kwargs = {}
    if default_config.logging.log_file:
        log_kwargs['filename'] = os.path.expanduser(default_config.logging.log_file)
    else:
        log_kwargs['stream'] = sys.stdout

    logging.basicConfig(**log_kwargs,
                        format=LOGGING_FORMAT,
                        level=getLevelName(log_level))


def find_prj_dir(dirname):
    if not os.path.isabs(dirname):
        if not os.path.isdir(dirname):
            dirname = os.path.abspath(os.path.join(PROJECT_CONFIG_DIR, dirname))
    return dirname


def current_datetime():
    """
    Returns formatted current date time in utc.
    Returns:
        str: Formatted result.
    """
    return datetime.date.strftime(datetime.datetime.utcnow(), DATETIME_FORMAT)
