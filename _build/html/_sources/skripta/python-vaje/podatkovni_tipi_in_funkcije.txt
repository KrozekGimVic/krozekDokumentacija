Vaje iz podatkovnih tipov in funkcij
====================================

Palindromi
----------
Uporabnik vpiše niz znakov, program pa pove, ali je vpisan niz palindrom ali
ne. Palindrom je niz znakov, ki se enako prebere z leve in z desne.

Primer::

  "abba"
  "keks"

Program izpiše::

  NI palindrom
  JE palindrom

Palindromi 2.0
--------------
Isto kot prva naloga, le da program ignorira presledke.
Primer::

  "perica reže raci rep"
  "ali se bo gordana na drog obesila"
  "danes je lep dan"
  "edo suče meč usode"

Program izpiše::

  JE palindrom
  JE palindrom
  NI palindrom
  JE palindrom

Kompresija
----------
Napiši funkcijo, ki gre skozi seznam, in pobriše vse enake sosede (če je v
seznamu zaporedoma več enakih elementov, jih spremeni v en sam element).
Primer::

  >>> pobrisi_sosede([1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 6, 6, 7, 8, 2])
  [1, 2, 3, 4, 5, 6, 7, 8, 2]

Zlivanje
--------
Napiši funkcijo, ki združi 2 po velikosti naraščajoča urejena seznama v nov
urejeni seznam. To naj počne tako, da vsak element pregleda le enkrat.

Primer::

  >>> zdruzi([1, 2, 5], [0, 3, 8, 12])
  [0, 1, 2, 5, 8, 12]

Krožna praštevila
-----------------
Praštevilu rečemo krožno, če so tudi vse rotacije praštevila. Primer je
število 197, saj so vse rotacije (197, 971, 719) tudi praštevila. Napiši
funkcijo krozna(:math:`n`), ki najde vsa krožna praštevila do :math:`n`.

.. hint::

  Če je :math:`n=1000000` je krožnih praštevil 55.

Primer::

  >>> krozna(100)
  2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97

Politično orientirana praštevila
--------------------------------
Praštevilo je LEVO, če ostane praštevilo, ko brišemo števke z leve.  Praštevilo
je DESNO, če ostane praštevilo, ko brišemo števke z desne. Napiši program, kjer
uporabnik vpiše število, program pa pove, če je to praštevilo, če je levo
praštevilo in če je desno praštevilo. Primer levega in desnega praštevila je
3797, saj so vse leve (3797, 797, 97, 7) in vse desne (3797, 379, 37, 3)
iteracije praštevila.  61 je primer praštevila, ki je levo (61, 1), ni pa desno
(61, 6).

Primer::

  3797
  61

Program izpiše::

  Število JE praštevilo.
  Število JE levo praštevilo.
  Število JE desno praštevilo.
  -----
  Število JE praštevilo.
  Število JE levo praštevilo.
  Število NI desno praštevilo.

.. vim: spell spelllang=sl
