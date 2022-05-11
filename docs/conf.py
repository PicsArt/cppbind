# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import platform
import sys

sys.path.insert(0, os.path.abspath('../src/'))

# set LD_LIBRARY_PATH for autodoc
if platform.system() == 'Darwin':
    paths = ['/Library/Developer/CommandLineTools/usr/lib/',
             '/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib']
    for p in paths:
        if os.path.exists(p):
            os.environ['DYLD_LIBRARY_PATH'] = f'$DYLD_LIBRARY_PATH:{p}'
            break

# -- Project information -----------------------------------------------------

project = 'IEGEN'
copyright = '2022, Picsart'
author = 'Picsart'

# The full version, including alpha/beta/rc tags
release = '0.0.1'

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx_copybutton',
    'sphinx.ext.autosectionlabel',
    'sphinx.ext.napoleon',
    'sphinx.ext.autosummary',
    'myst_parser',
    'sphinx_toolbox.collapse',
    'sphinx_design',
]

myst_enable_extensions = ["colon_fence"]

autosummary_generate = True
autosummary_generate_overwrite = False
napoleon_include_init_with_doc = True

# Make sure the target is unique
autosectionlabel_prefix_document = True

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store', 'test*.rst']

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_material'
html_show_sourcelink = False

html_theme_options = {

    # Set the name of the project to appear in the navigation.
    'nav_title': 'IEGEN',

    # Set you GA account ID to enable tracking
    'google_analytics_account': 'UA-XXXXX',

    # Specify a base_url used to generate sitemap.xml. If not
    # specified, then no sitemap will be built.
    'base_url': 'https://github.com/PicsArt/iegen',

    # Set the color and the accent color
    'theme_color': '#3849aa',
    'color_primary': '#3849aa',
    'color_accent': '#6e74dc',

    # Set the repo location to get a badge with stats
    'repo_url': 'https://github.com/PicsArt/iegen',
    'repo_name': 'GitHub',
    'repo_type': 'github',

    # Visible levels of the global TOC; -1 means unlimited
    'globaltoc_depth': -1,
    # If False, expand all TOC entries
    'globaltoc_collapse': True,
    # If True, show hidden TOC entries
    'globaltoc_includehidden': True,
}

html_sidebars = {
    "**": ["logo-text.html", "globaltoc.html", "localtoc.html", "searchbox.html"]
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
