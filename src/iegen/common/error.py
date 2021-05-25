from iegen import logging
from traceback import extract_stack, format_list

class Error:
    has_error = False

    @classmethod
    def error(cls, msg, file=None, line=None):
        cls.has_error = True
        logging.error(cls.get_message(msg, file, line, "error"))
        cls.log_traceback(extract_stack())

    @classmethod
    def critical(cls, msg, file=None, line=None):
        cls.log_traceback(extract_stack())
        raise Exception(cls.get_message(msg, file, line, "critical"))

    @classmethod
    def warning(cls, msg, file=None, line=None):
        logging.warning(cls.get_message(msg, file, line, "warning"))

    @classmethod
    def get_message(cls, msg, file, line, err_type):
        err_msg = err_type.upper() + ': '
        if file:
            err_msg += f"file -> {file}"
            if line:
                err_msg += f", line -> {line}, "
        err_msg += f"msg -> {msg}"

        return err_msg

    @classmethod
    def log_traceback(cls, traceback_stack):
        traceback_list = format_list(traceback_stack)
        traceback_list.pop()
        for frame in traceback_list:
            logging.debug(frame.strip())
