Add new language bindings generation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

IEGEN allows users to add a new supported language if user already has
code snippets and type converter snippets (look :doc:`here </04_advanced_features/03_snippets>` for more detailed information
about snippets usage). IEGEN deduces the list of supported languages from `rules` section info defined inside project config files.
Thus, to be able to add a new language to that list, user needs to make his own code snippets and type converter snippets and
define them under `rules` section. For adding a new language user doesn't need to do any changes to the IEGEN source code, it's possible
to do it only by project config files.

Here are the examples for snippets and config file for virtual `my_lang` language:

.. literalinclude:: /../examples/tests/my_lang_snippets/code_snippets.yaml
   :language: yaml

.. literalinclude:: /../examples/tests/my_lang_snippets/types.yaml
   :language: yaml

Above described snippet files have minimum content to be able to generate dummy bindings for class and function.

.. literalinclude:: /../examples/tests/my_lang_iegen.yaml
   :language: yaml

Here we include code snippets and type converter snippets, variable definitions and define some variables for root node.

After these preparations the tool is ready to be run for a new `my_lang` language. If the user wants to generate meaningful
bindings with the correct target language syntax, he/she needs to define correct code snippets for class, function and other cxx
entities, and also must define type converter snippets for all the types user wants to use.
