"""
Module for defining various error classes
"""

from traceback import extract_stack, format_list

from iegen import logging


class Error:
    """
    Class is used to call various types of errors
    """

    has_error = False

    @classmethod
    def error(cls, msg, file=None, line=None):
        """Simple error type"""
        cls.has_error = True
        logging.error(cls.get_message(msg, file, line, "error"))
        cls.log_traceback(extract_stack())

    @classmethod
    def critical(cls, msg, file=None, line=None):
        """Critical error: it's not possible to proceed after this type of error"""
        cls.log_traceback(extract_stack())
        raise IEGError(cls.get_message(msg, file, line, "critical"))

    @classmethod
    def warning(cls, msg, file=None, line=None):
        """Warning: execution of program is not stopped"""
        logging.warning(cls.get_message(msg, file, line, "warning"))

    @classmethod
    def get_message(cls, msg, file, line, err_type):
        """Get error message by its type"""
        err_msg = err_type.upper() + ': '
        if file:
            err_msg += f"file -> {file}, "
            if line:
                err_msg += f"line -> {line}, "
        err_msg += f"msg -> {msg}"

        return err_msg

    @classmethod
    def log_traceback(cls, traceback_stack):
        """Get exception traceback and log it in case of debug"""
        if logging.getLevelName(logging.root.level) == "DEBUG":
            traceback_list = format_list(traceback_stack)
            traceback_list.pop()
            logging.debug(''.join(traceback_list))


class IEGError(Exception):
    """
    Exception class to raise errors in case of critical iegen errors
    """
