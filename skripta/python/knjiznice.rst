Nameščanje knjižnic
===================

Python ima veliko knjižnic. Nekaj jih je vključenih skupaj s Pythonom in jih
verjetno že poznate (npr. ``random``, ``tkinter``). Ostale knjižnice je potrebno
namestiti. Za to uporabimo ukaz ``pip`` (PIP Installs Python) ali ``pip3`` za
python3.

Če želimo namestiti npr. knjižnico ``numpy`` za python3, napišemo::

  sudo pip3 install numpy

S tem je knjižnica numpy dostopna vsem python programom, ki jih poganjamo na
računalniku. V program jo uvozimo z ukazom::

  import numpy

Virtualno okolje
----------------
Včasih je lepše, če knjižnice ne namestimo na cel računalnik, ampak zgolj
znotraj enega projekta.

Virtualno okolje lahko postavimo v kateri koli mapi z uporabo ukaza
`virtualenv`.::

  virtualenv <lokacija_za_okolje> -p <verzija_pythona>
  # Npr.:
  virtualenv venv -p /bin/python3

.. hint::

  Če dobite napako ``virtualenv: command not found``, si ga morate najprej
  namestiti::

    sudo apt-get install python3-virtualenv


S tem smo naredili mapo `venv`, v kateri imamo kup datotek, ki opisujejo
lokalno različico pythona (npr. verzijo, katere knjižnice ima na voljo).

Okolje lahko začnemo uporabljati, tako da ga aktiviramo z ukazom::

  source <lokacija_okolja>/bin/activate
  # Npr.:
  source venv/bin/activate

Ko smo znotraj okolja, bomo na začetku ukazne vrstice dobili ``(venv)``.
Vse knjižnice, ki jih namestimo v virtualnem okolju, bodo na voljo samo v tem
virtualnem okolju in nikjer drugje. Za namestitev pa ne rabimo pisati ukaza
``sudo``::

  pip install django

Virtualno okolje zapustimo z ukazom::

  deactivate


Zaganjanje Python 3 v Sublime Text
==================================

V ``/home/kirito/.config/sublime-text-3/Packages/User`` si naredite novo datoteko
z imenom ``Python3.sublime-build`` in vsebino::


  {
      "cmd": ["/usr/bin/python3", "-u", "$file"],
      "file_regex": "^[ ]*File \"(…*?)\", line ([0-9]*)",
      "selector": "source.python"
  }

Vse Python 3 programe lahko zaženete z uporabo bližnjice ``Ctrl+Shift+B`` in
izberete Python3.
