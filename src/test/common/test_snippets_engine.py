import pytest

from cppbind.cxx_exposed import CXXExposedType


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
        ),
        (
            'a::b::B<c::C>::G<d::D, e::E<f::F>>',
            ['d::D', 'e::E<f::F>']
        ),
        (
            'a::b::B<c::C>::G::H::<d::D, e::E<f::F, x::X>>',
            ['d::D', 'e::E<f::F, x::X>']
        ),
        (
            'a::b::B<c::C>::D',
            []
        ),
        (
            'a::b::B',
            []
        )
    ]
)
def test_get_template_arguments(spelling, arguments):
    cxx_type = CXXExposedType(spelling)
    result = [t.type._cxx_type for t in cxx_type.template_arguments]
    assert result == arguments
