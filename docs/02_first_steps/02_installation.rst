Installation
============

System requirements
^^^^^^^^^^^^^^^^^^^

Operating system: Linux, Mac

Environment setup
^^^^^^^^^^^^^^^^^

Clone iegen master branch into current directory\ :

.. code-block:: bash

    git clone  https://github.com/PicsArt/iegen.git
    cd iegen

If the project is already cloned, pull the latest version:

.. code-block:: bash

    git fetch
    git pull

.. tabs::

   .. tab:: Linux

        Update/upgrade the system\ :

        .. code-block:: bash

            sudo apt-get update
            sudo apt-get upgrade

        Install Clang\ :

        .. code-block:: bash

            sudo apt-get install -y libclang-9-dev

        If python 3.7 or higher is already installed then skip this step.

        Install python\ :

        .. code-block:: bash

            sudo apt install software-properties-common
            sudo add-apt-repository ppa:deadsnakes/ppa
            sudo apt install python3.7
            sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.7 1
            sudo update-alternatives --config python3
            python3 -m pip install --upgrade pip
            python3 -m pip install virtualenv


        Create and activate virtualenv\ :

        .. code-block:: bash

            python3 -m venv venv
            source venv/bin/activate

   .. tab:: Mac OS X

        Add libclang path to DYLD_LIBRARY_PATH.
        If you have Xcode installed then run the following command:

        .. code-block:: bash

            echo 'export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib"' >> ~/.profile

        If only CommandLineTools is installed then:

        .. code-block:: bash

            echo 'export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/Library/Developer/CommandLineTools/usr/lib"' >> ~/.profile

        If python 3.7 or higher is already installed then skip this step.

        Install python\ :

        .. code-block:: bash

            brew install python@3.7
            echo 'export PATH="/usr/local/opt/python@3.7/lib:$PATH"' >> ~/.profile

        Install virtualenv\ :

        .. code-block:: bash

            python3 -m pip install virtualenv

        Create and activate a virtualenv\ :

        .. code-block:: bash

            python3 -m venv venv
            source venv/bin/activate


Dev installation
^^^^^^^^^^^^^^^^

.. code-block:: bash

    pip3 install -r src/requirements.txt
    python3 setup.py install develop

Installation is complete to test run the command\ :

.. code-block:: bash

  iegen -h