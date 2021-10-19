NEW_LINE = '\n'


def make_doxygen_comment(pure_comment):
    if isinstance(pure_comment, str):
        pure_comment = pure_comment.split(NEW_LINE)
    nl = f'{NEW_LINE} * '
    if not pure_comment or all((not line or line.isspace() for line in pure_comment)):
        return ''
    start = '' if not pure_comment[0] or pure_comment[0].isspace() else nl
    return f"""/**{start}{nl.join(pure_comment)}
*/"""
