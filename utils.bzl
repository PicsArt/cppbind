def _untar_impl(ctx):
    tree = ctx.actions.declare_directory(ctx.attr.out)

    ctx.actions.run_shell(
        inputs = [ctx.file.src],
        outputs = [tree],
        command = "tar -C {out} -xf {src} ".format(src = ctx.file.src.path, out = tree.path),
    )
    return [
        DefaultInfo(
            runfiles = ctx.runfiles([tree]),
        ),
    ]

untar = rule(
    implementation = _untar_impl,
    attrs = {
        "src": attr.label(mandatory = True, allow_single_file = True),
        "out": attr.string(mandatory = True),
    },
)
