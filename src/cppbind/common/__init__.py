# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

import os

PROJECT_CONFIG_DIR = os.path.join(os.path.dirname(__file__), "../config/")
YAML_CONFIG_TEMPLATE_PATH = os.path.join(PROJECT_CONFIG_DIR, 'cppbind.yaml')
JINJA_UNIQUE_MARKER = '~!+marker#@~'
