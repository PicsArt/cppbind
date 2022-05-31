Installation
============

Required environment setup
^^^^^^^^^^^^^^^^^^^^^^^^^^

.. tab-set::

   .. tab-item:: Linux

        Update/upgrade the system\ :

        .. code-block:: bash

            sudo apt-get update
            sudo apt-get upgrade

        Install Clang\ :

        .. code-block:: bash

            sudo apt-get install -y libclang-9-dev

        If Python 3.7 or higher is already installed, then skip this step.

        Install Python\ :

        .. code-block:: bash

            sudo apt install software-properties-common
            sudo add-apt-repository ppa:deadsnakes/ppa
            sudo apt install python3.7
            sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.7 1
            sudo update-alternatives --config python3

   .. tab-item:: macOS

        Add libclang path to DYLD_LIBRARY_PATH.
        If you have Xcode installed then run the following command:

        .. code-block:: bash

            echo 'export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib"' >> ~/.profile

        If only CommandLineTools is installed, then:

        .. code-block:: bash

            echo 'export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/Library/Developer/CommandLineTools/usr/lib"' >> ~/.profile

        If your shell is Zsh instead of Bash, you need to replace **.profile** with **.zshrc** in the previous commands.

        If Python 3.7 or higher is already installed, then skip this step.

        Install Python\ :

        .. code-block:: bash

            brew install python@3.7
            echo 'export PATH="/usr/local/opt/python@3.7/lib:$PATH"' >> ~/.profile

   .. tab-item:: Windows

        CppBind requires Clang for parsing source files. Make sure you have Clang compiler installed on your Windows machine and it's added to the system path. Download <https://releases.llvm.org/download.html>`_ and install latest version of LLVM from official website.

        If Python 3.7 or higher is already installed then skip this step.

        Install Python\ :

        `Download <https://www.python.org/downloads/>`_ and install latest version of Python from official website.


User installation
^^^^^^^^^^^^^^^^^

``cppbind`` is built as a standard Python package and can be installed using ``pip`` with the following command.

.. code-block:: bash

    python3 -m pip install cppbind

If you use it as a standalone command-line application, we recommend using ``pipx`` instead.
``pipx`` creates an isolated environment for each application and its related packages and makes the application available from the shell.
Using ``pipx`` also prevents dependency conflicts between ``cppbind`` and other packages within the current environment.
To install cppbind with ``pipx``, use the following commands:

.. code-block:: bash

    python3 -m pip install pipx
    python3 -m pipx ensurepath
    python3 -m pipx install cppbind


To test the installation run the following command\ :

.. code-block:: bash

  cppbind -h

Contributor installation
^^^^^^^^^^^^^^^^^^^^^^

Clone the CppBind master branch into current directory\ :

.. code-block:: bash

    git clone https://github.com/PicsArt/cppbind.git
    cd cppbind

If the project is already cloned, pull the latest version:

.. code-block:: bash

    git fetch
    git pull

.. tab-set::

    .. tab-item:: Linux

        Install virtualenv\ :

        .. code-block:: bash

            python3 -m pip install virtualenv

        Create and activate virtualenv\ :

        .. code-block:: bash

            python3 -m venv venv
            source venv/bin/activate

    .. tab-item:: macOS

        Install virtualenv\ :

        .. code-block:: bash

            python3 -m pip install virtualenv

        Create and activate a virtualenv\ :

        .. code-block:: bash

            python3 -m venv venv
            source venv/bin/activate

    .. tab-item:: Windows

        Install virtualenv\ :

        .. code-block:: bash

            python -m pip install virtualenv

        Create and activate a virtualenv\ :

        .. code-block:: bash

            python -m venv venv
            ./venv/Scripts/activate

And finally, the package build step:

.. code-block:: bash

    python3 -m pip install -r src/requirements.txt
    python3 setup.py develop
