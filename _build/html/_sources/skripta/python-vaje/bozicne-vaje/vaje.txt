.. |nbsp| unicode:: 0xA0
   :trim:

Božične vaje
============

.. warning::
  Datoteke so lahko velike, tako da jih ne poskušaj celih spraviti v spomin,
  ampak jih glej raje vrstico po vrstico!

Božičkova hitrost
-----------------

Božiček mora za obdarovanje vseh otrok v enem dnevu potovati zelo hitro. Ampak
kako hitro je "zelo hitro"?

Dano imaš datoteko :download:`razdalje_his.txt <datoteke/razdalje_his.txt>`
polno števil, vsako v svoji vrsti. Vsaka številka pomeni razdaljo do naslednje
hiše (v km).

Napiši program, ki prebere to datoteko in izračuna hitrost, s katero mora
božiček potovati, da lahko obdaruje vse otroke. Upoštevaj še, da se mora
božiček pri vsaki hiši ustaviti za ``0.0042`` sekunde, da lahko odda darila.

Rešitev naj bo v ``km/h``.

Božičkov seznam
---------------

Preden lahko božiček obdaruje otroke, mora ugotoviti, kateri so ``pridni`` in
kateri so ``poredni``. Ker je že star, otrok pa je vsako leto več, vas je
prosil, da mu napišete program, ki bo pri tem pomagal.

Dani imaš dve datoteki:

* :download:`ocene.txt <datoteke/ocene.txt>`, ki vsebuje opis (npr. ``Pomagal
  staršem``) in oceno (npr. ``5``) za vsako od dejanj. Opis in ocena sta ločena
  z vejico.
* :download:`otroci.txt <datoteke/otroci.txt>`, ki vsebuje najprej ime otroka in
  seznam vsej dejanj, ki jih je skozi leto počel. Ime ter vsako dejanje so
  ločeni z vejico. Dejanj je lahko več (med 1 in 4).

V novo datoteko ``preverjeni_otroci.txt`` za vsakega otroka izpiši njegovo ime,
``'priden otrok'`` če ima nenegativno oceno ali ``'poreden otrok'``, če ima
negativno oceno ter oceno. Ločene naj bodo z vejicami, vsak otrok pa naj bo v
svoji vrsti.

Primer::

  Peter, poreden otrok, -3
  Marija, priden otrok, 101

Božičkova darila
----------------

Božiček mora za svoje škratke pripraviti seznam vseh daril, ki jih je potrebno
izdelati.

Dano imaš datoteko :download:`darila.txt <datoteke/darila.txt>`, v kateri je v
vsaki vrsti napisano ``ime``, ``seznam želja`` (med 2 in 6) ter ``'priden
otrok'`` ali ``'poreden otrok'``. Ločene so z vejicami.

Če je otrok priden, mu bomo prinesli vsa darila. Če je otrok poreden, bo za
vsako darilo, ki si ga želi, dobil en kos oglja.

Program naj ustvari seznam vseh igrač (in oglja), ki ga je treba izdelati, ter
ga lepo izpiše.

Primer::

  Oglje: 42
  Bonboni: 33
  Punčka iz cunj: 15

Bonus naloga
~~~~~~~~~~~~

Seznam naj bo urejen po velikosti padajoče.
