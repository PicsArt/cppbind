"""
Helper common codes for conversion
"""

class Validator:
    @staticmethod
    def validate_root_shared_ref(type_ctx, expected_value):
        is_root_shared_ref = type_ctx.root.shared_ref

        if is_root_shared_ref != expected_value:
            if is_root_shared_ref:
                exc_msg = "Root has an invalid attribute \"shared_ref: True\""
            else:
                exc_msg = "Root must have an attribute \"shared_ref: True\""

            raise Exception(exc_msg)
