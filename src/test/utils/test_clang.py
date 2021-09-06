import pytest

from iegen.utils.clang import get_template_arguments


@pytest.mark.parametrize(
    "spelling, arguments",
    [
        (
                'ptr<ptr<ptr<first, second>, test>, test, ptr<ptr<second>, third>, test>',
                ['ptr<ptr<first, second>, test>', 'test', 'ptr<ptr<second>, third>', 'test']
        ),
        (
                'std::pair<std::string, std::vector<int>>',
                ['std::string', 'std::vector<int>']
        ),
        (
                'ptr<ptr<first>, ptr<ptr<second>, third>>',
                ['ptr<first>', 'ptr<ptr<second>, third>']
        ),
        (
                'std::pair<first, second>',
                ['first', 'second']
        )
    ]
)
def test_get_template_arguments(spelling, arguments):
    result = get_template_arguments(spelling)
    assert result == arguments
