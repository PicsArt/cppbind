Installation
============

System requirements
^^^^^^^^^^^^^^^^^^^

 Operating system: Linux, Mac

Dev environment setup
^^^^^^^^^^^^^^^^^^^^^


  Clone iegen master branch into current directory\ :

  .. code-block:: bash

     git clone  https://github.com/PicsArt/iegen.git

  If the project is already cloned, pull the latest version:

  .. code-block:: bash

     git fetch
     git pull

Linux
~~~~~


  Update/upgrade the system\ :

  .. code-block:: bash

     # Linux
     sudo apt-get update
     sudo apt-get upgrade

  Install Clang\ :

  .. code-block:: bash

     sudo apt-get install -y libclang-9-dev

  If python 3.7 or greater is already installed then skip the next step.

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

     cd /path/to/project/
     python3 -m venv venv
     source venv/bin/activate

Mac OS X
~~~~~~~~

  For MacOS version 10.14 or below\ :

  .. code-block::

     open /Library/Developer/CommandLineTools/Packages/macOS_SDK_headers_for_macOS_{version}.pkg
     echo 'export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:/Library/Developer/CommandLineTools/usr/lib"' >> ~/.profile

  For higher versions\ :


  If python 3.7 or greater is already installed then skip the next step.

  Install python\ :

  .. code-block:: bash

      brew install python@3.7
      echo 'export PATH="/usr/local/opt/python@3.7/lib:$PATH"' >> ~/.profile
      python3 -m pip install virtualenv


  Create and activate virtualenv\ :

  .. code-block:: bash

     cd /path/to/project/
     python3 -m venv venv
     source venv/bin/activate

iegen installation
^^^^^^^^^^^^^^^^^^

.. code-block:: bash

    pip3 install -r src/requirements.txt
    python3 setup.py install

Installation is complete to test run the command\ :

.. code-block:: bash

  iegen -h