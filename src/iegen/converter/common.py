"""
Helper common codes for conversion
"""

class TypeConverterHelper:
    @staticmethod
    def validate_root_shared_ref_is_set(type_ctx):
        if not type_ctx.root.shared_ref:
            raise Exception("Root must have an attribute \"shared_ref: True\"")

    @staticmethod
    def validate_root_shared_ref_is_not_set(type_ctx):
        if type_ctx.root.shared_ref:
            raise Exception("Root has an invalid attribute \"shared_ref: True\"")
