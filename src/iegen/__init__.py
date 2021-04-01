import os
import sys
import logging as logging
from logging import getLevelName
from iegen.common.config import config as default_config, PROJECT_CONFIG_DIR

logging_format = '%(asctime)s:(%(levelname)s) %(message)s'

log_kwargs = {}
if default_config.logging.log_file:
    log_kwargs['filename'] = os.path.expanduser(default_config.logging.log_file)
else:
    log_kwargs['stream'] = sys.stdout

logging.basicConfig(**log_kwargs,
                    format=logging_format,
                    level=getLevelName(default_config.logging.level))


def find_prj_dir(dirname):
    if not os.path.isabs(dirname):
        if not os.path.isdir(dirname):
            dirname = os.path.abspath(os.path.join(PROJECT_CONFIG_DIR, dirname))
    return dirname
