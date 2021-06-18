import re
import uuid

from iegen import DATETIME_REGEX

OUTPUT_MODIFICATION_KEY = str(uuid.uuid1())


def is_output_changed(old, new):
    """
    Compares iegen generated old code with new one.
    It's assumed that to each occurrence of OUTPUT_MODIFICATION_KEY in new code corresponds a datetime in old one.
    Args:
        old(str): Iegen generated old code.
        new(str): Iegen generated new code.
    Returns:
        bool: Returns true if old and new do not match and false otherwise.
    """
    keyword_len = len(OUTPUT_MODIFICATION_KEY)
    idx = new.find(OUTPUT_MODIFICATION_KEY)
    while idx != -1:
        new_to = new[:idx]
        old_to = new[:idx]
        if new_to != old_to:
            # compare until keyword occurrence
            return True
        # drop compared part with keyword
        new = new[idx + keyword_len:]
        old = old[idx:]
        # check old starts with datetime
        match = re.match(DATETIME_REGEX, old)
        if match is None:
            return True

        # drop datetime from old
        old = old[match.span()[1]:]
        idx = new.find(OUTPUT_MODIFICATION_KEY)
    # compare remaining part
    return old != new
