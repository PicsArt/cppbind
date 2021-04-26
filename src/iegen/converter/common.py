"""
Helper common codes for conversion
"""

class Validator:
    @staticmethod
    def shared_ref_set(type_ctx):
        if not type_ctx.root.shared_ref:
            raise Exception("Root must have an attribute \"shared_ref: True\"")

    @staticmethod
    def shared_ref_unset(type_ctx):
        if type_ctx.root.shared_ref:
            raise Exception("Root has an invalid attribute \"shared_ref: True\"")
