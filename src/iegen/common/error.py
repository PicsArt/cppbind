"""
Module for defining various error classes
"""

from traceback import extract_stack, format_list

from iegen import logging


class Error:
    """
    Class is used to call various types of errors
    """

    __has_error = False
    __error_limit = -1

    @classmethod
    def set_error_limit(cls, error_limit):
        """Method to set error limit"""
        cls.__error_limit = error_limit

    @classmethod
    def has_error(cls):
        """method to check whether error has ever occurred"""
        return cls.__has_error

    @classmethod
    def error(cls, msg, file=None, line=None):
        """Simple error type"""
        cls.__has_error = True

        if cls.__error_limit == 0:
            Error.critical(msg, file, line)
        else:
            cls.__error_limit -= 1
            logging.error(cls.get_message(msg, file, line, "error"))
            cls.log_traceback(extract_stack())

    @classmethod
    def critical(cls, msg, file=None, line=None):
        """Critical error: it's not possible to proceed after this type of error"""
        error_msg = cls.get_message(msg, file, line, "critical")
        logging.critical(error_msg)
        cls.log_traceback(extract_stack())
        raise IEGError(error_msg)

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
