.. |nbsp| unicode:: 0xA0
   :trim:

Pygame
============

Knjižnica ``pygame`` je skupek orodij primarno namenjen pisanju iger. Optimiziran je za hitro delovanje, saj ima nekatere dele napisane v strojnem jeziku in v C-ju.

Namestitev
-----------
Windows
^^^^^^^^^

Iz http://www.lfd.uci.edu/~gohlke/pythonlibs/#pygame si prenesi ustrezno verzijo ``pygame`` knjižnice. Za 32-bitno verzijo Pythona 3.4 bo to ``pygame-1.9.2a0-cp34-none-win32.whl``. Ko jo preneseš, datoteko prestavi v ``C:\Python34\Scripts`` in tam odpri ukazno vrstico. To lahko storiš tako, da držiš tipko Shift in pritisneš desno miškino tipko kjer koli znotraj mape. Prikazal se ti bo meni v katerem izberi možnost, da odpreš ukazno vrstico znotraj trenutne mape.

Za namestitev v orodno vrstico zapiši ukaz:
``pip install pygame-1.9.2a0-cp34-none-win32.whl``

Linux
^^^^^^

Za verzije 2.x ni problema, saj ima verjetno vsak urejevalnik paketkov paket s pygame za python. Npr. Debian in Ubuntu nudita naslednje

``sudo apt-get install python-pygame``

Za verzije 3.x, pa si moraš sam prevesti knjižnico. Najprej prenesi vse datoteke

.. code-block:: bash

    sudo apt-get install mercurial
    hg clone https://bitbucket.org/pygame/pygame

Temu sledi namestitev vseh paketov, ki jih pygame potrebuje:

.. code-block:: bash

    sudo apt-get install python3-dev libsdl-image1.2-dev libsdl-mixer1.2-dev \
    libsdl-ttf2.0-dev libsdl1.2-dev libsmpeg-dev python3-numpy subversion \
    libportmidi-dev ffmpeg libswscale-dev libavformat-dev libavcodec-dev

Sedaj preglej nastavitve paketa

.. code-block:: bash

    cd pygame
    python3 config.py

in ga zgradi in namesti

.. code-block:: bash

    python3 setup.py build
    sudo python3 setup.py install


Samodejna namestitev
""""""""""""""""""""

Vse zgornje korake lahko združimo v eno datoteko. To datoteko lahko preneseš :download:`tukaj <datoteke/install_pygame.sh>` in jo zaženeš z ukazom

.. code-block:: bash

    bash install_pygame.sh



Preverjanje namestitve
----------------------

Odpri Python orodno vrstico, IDLE. Prvi test, ki ga lahko izvedeš je samo

.. code-block:: python

   import pygame

Sedaj pa lahko preizkusiš pygame z njihovimi primeri

.. code-block:: python

    import pygame.examples.aliens
    pygame.examples.aliens.main()

Namesto aliens lahko pogledaš tudi `druge primere <http://www.pygame.org/docs/ref/examples.html>`_.

Koda 2017
-------------
Koda do igre, ki smo jo naredili v letu 2017 je dostopna na
`GitHubu <https://github.com/MKolman/pygame-test>`_.
