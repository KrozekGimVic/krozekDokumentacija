.. |nbsp| unicode:: 0xA0
   :trim:

Osnovne vaje
============

Štetje limon
------------
Napiši program, ki prebere število in v pravilni slovenšini izpiše, koliko ima limon. Pozor pri številih kot so na primer 101 ipd.
Primer::

  Uporabnik vnese 2.

Program izpiše::

  Imam 2 limoni.

Smrečice
--------
Napiši program, ki od uporabnika dobi naravno število :math:`n`, nato pa nariše
"smrekico" iz zvezdic. Smerkica naj ima :math:`n` vrstic, izgleda pa naj takole
(če je :math:`n` enak 5)::

  5-smrečica:
  *
  **
  ***
  ****
  *****

Isto, le da naj bo smrekica poravnana na desno::

  5-smrečica:
      *
     **
    ***
   ****
  *****

Isto, le da je smrekica "na oba konca"::

  5-smrečica:
      *
     ***
    *****
   *******
  *********

Kombiniranje števil
-------------------
Napiši program, ki od uporabnika po vrsti prebere tri števila :math:`x`, :math:`y`,
:math:`z`. Program naj preveri, če se da tretje število (:math:`z`) napisati kot
kombinacijo prvih dveh z eno od osnovnih operacij ``(+, -, *, /)``. Če je možno,
naj to izpiše, drugače pa naj izpiše, da se tega ne da narediti.
Primer::

  Uporabnik vpiše 2, 3 in 5.

Program izpiše::

  2 + 3 = 5

Balls are touching
------------------
Sestavi program, ki bo prebral središči in polmera dveh krogov ter preveril, ali
sta kroga ločena, se dotikata, ali pa imata skupno več kot eno točko.

Kvadrati
--------
Napiši program, ki od uporabnika prebere število :math:`n`, nato pa izpiše po vrsti vse
kvadrate naravnih števil do (vključno z) :math:`n`.  Primer::

  Uporabnik vpiše 20.

Program izpiše::

  1, 4, 9, 16.

Malo aritmetike
---------------
Napiši program, ki od uporabnika prebere število :math:`n`, in izpiše vsoto vseh
naravnih števil do vključno :math:`n`, ter produkt vseh naravnih števil do vključno
:math:`n`.

Primer::

  Uporabnik vpiše 100.

Program izpiše::

  1 + 2 + ... + 50 = 1275
  1 * 2 * ... * 50 = 30414093201713378043612608166064768844377641568960512000000000000

Delitelji
---------
Sestavi program, ki dobi število n in izpiše vse njegove delitelje, vsakega samo enkrat, urejene po velikosti.

Trikotnišna neenakost
---------------------
Sestavi program, ki bo prebral tri realna števila, nato pa preveril, ali obstaja trikotnik s takimi dolžinami
stranic. Če obstaja, naj program izračuna njegovo ploščino in obseg.

Šahovnica
---------
Uporabnik vpiše dve polji po koordinatah :math:`(x, y)`, kjer :math:`1 \leq x, y \leq 8`.
Ugotovi, ali sta polji enake ali različne barve.

Obračanje števil
----------------
Sestavi program, ki prebere naravno število in ga izpiše v obratnem vrstnem redu.
Primer::

  Uporabnik vpiše 726.

Program izpiše::

  Obrat stevila 726 je 627.

Števke
------
Sestavi program, ki prebere naravno število in sešteje njegove števkein si to zapomni. Nato sešteje števke
tega števila, in tako naprej, dokler ne pridemo do enomestnega števila. Program naj izpisuje vse vmesne rezultate.
Primer::

  Uporabnik vnese število 1234567891234567891234567891.

Program izpiše::

  1234567891234567891234567891
  136
  10
  1

Maraton
-------
Sestavi program, ki prebere časa teka dveh krogov (pri maratonu recimo) in izpiše skupen čas.
Primer::

  1. krog:
      ure: 2
      minute: 23
      sekunde: 45
  2. krog:
      ure: 1
      minute: 48
      sekunde: 59

Program izpiše::

  Skupen čas: 4 ur 12 minut in 44 sekund.

Statistika
----------
Napiši program, ki od uporabnika bere števila, dokler uporabnik ne vpiše števila 0. Program naj sproti izpisuje
največje, najmanjše in povprečje števil, vpisanih do sedaj.

Fibonacci
---------
Sestavi program, ki izpiše prvih n členov Fibonaccijevega zaporedja.
To je zaporedje, podano s predpisom :math:`f_1 = 1, f_2 = 1, f_n = f_{n-1} + f_{n-2}`.

Primer::
  Vnesi število šlenov: 10

Program izpiše::

  Členi zaporedja so: 1 1 2 3 5 8 13 21 34 55


Lastnosti števil
----------------
Sestavi program, ki izpiše lastnosti števila, ki ga je vpisal uporabnik. Preveri naj, če je sodo, če je praštevilo,
če je popolno število  (je vsota svojih pravih deliteljev), ali je morda trikotniško, ali je popolni kvadrat,
Primer::

  Uporabnik vnese število 28

Program izpiše::

  Število JE sodo.
  Število NI praštevilo.
  Število JE popolno.
  Število JE trikotniško.
  Število NI popoln kvadrat.

Prafaktorji
-----------
Sestavi program, ki prebere število in izpiše njegov razcep na prafaktorje.
Primer::

  Uporabnik vnese število 2250.

Program izpiše::

  "2250 =  2^3 * 3^2 * 5 * 7"

Decimalke
---------
Sestavi program, ki prebere naravna števila :math:`a`, :math:`b` in n ter izpiše celi deli in še :math:`n`
decimalk kvocienta :math:`a / b`.

Primer::

    Vnesi a: 771
    Vnesi b: 761
    Vnesi n: 40

Prigram izpiše::

    771 / 761 = 1.0131406044678055190538764783180026281208

Evklidov algoritem
------------------
Sestavi program, ki izračuna največji skupni delitelj števil :math:`a` in
:math:`b` in izpiše vse vmesne rezultate `evklidovega algoritma
<http://sl.wikipedia.org/wiki/Evklidov_algoritem>`_.
Primer::

    Vnesi a: 3672
    Vnesi b: 624

Program izpiše::

    3672 =  5 * 624 + 552
    624 = 1 * 552 + 72
    552 = 7 * 72 + 48
    72 = 1 * 48 + 24
    48 = 2 * 24 + 0
    Najvecji skupni delitelj stevil 3672 in 624 je 24.

Uganka
-------

Sestavi program, s katerim se igraš "Ugani število". Program si zmisli naključno število med 1 in 100
in ti pove ali si uganil preveč ali premalo ali točno.
Primer::

  Ugibaj: 50
  Premalo!
  Ugibaj: 70
  Preveč!
  Ugibaj: 62
  Premalo!
  Ugibaj: 66
  Premalo:
  Ugibaj: 68
  Premalo!
  Ugibaj: 69
  Čestitam, iskano število je 69!

.. hint::

  Naključno število med vklučno a in b se dobi s funkcijo randint(a, b), iz modula random.
  V vaši kodi naredite::

    from random import randint
    nakljucno = randint(0, 100)

