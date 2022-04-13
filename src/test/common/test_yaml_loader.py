import os
import pytest

from iegen.common.error import IEGError
from iegen.common.yaml_process import load_yaml

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


def test_yaml_concat_constructor_negative_input_types():
    with pytest.raises(IEGError, match="`concat` yaml constructor can operate only on sequence node"):
        load_yaml(os.path.join(SCRIPT_DIR, 'test_examples/yaml_load_negative/with_wrong_concat_input_types.yaml'))


def test_yaml_concat_constructor_negative_input_values():
    with pytest.raises(IEGError, match="Items of `concat` yaml constructor must be strings"):
        load_yaml(os.path.join(SCRIPT_DIR, 'test_examples/yaml_load_negative/with_wrong_concat_input_values.yaml'))
