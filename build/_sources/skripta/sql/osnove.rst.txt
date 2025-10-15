.. _osnovesql:

Osnove SQL
==========

Jezik SQL je namenjen delu z bazami podatkov. Bazo spreminjamo in iz nje
dobivamo podatke s pomočjo izvrševanja "queryev". Baze so shranjene kot tabele.
Vsi naši primeri bodo potekali na naslednjem primeru s tremi tabelami,
``ucenci``, ``ocene`` in ``predmeti``.

== ===== ======= ====== ======= =============
ID ime   priimek letnik oddelek rojstni_datum
== ===== ======= ====== ======= =============
0  Janez Novak   4      A       1996-12-23
1  Mojca Mavec   3      C       1997-09-31
2  Marko Kos     2      F       1998-06-18
3  Luka  Vrh     1      G       1999-03-03
4  Miha  Kovač   2      B       1998-01-04
5  Lara  Petek   4      E       1996-10-29
== ===== ======= ====== ======= =============

SELECT
------

Najbolj enostaven stavek s katerim izbiramo podatke is tabele. Sintaksa:

.. code-block:: sql

  SELECT polja FROM tabela WHERE pogoj ORDER BY polja;

Besede jezika se ponavadi piše z veliko začetnico, čeprav ni obvezno. Deli
stavka od ``WHERE`` naprej niso obvezni. Če želimo na primer dobiti vse podatke iz tabele
``ucenci``, napišemo:

.. code-block:: sql

  SELECT * FROM ucenci;

Če pa želimo priimke učencev 4. letnika urejene po njihovi starosti napišemo:

.. code-block:: sql

  SELECT priimek FROM ucenci WHERE letnik=4 ORDER BY rostni_datum;

V pogoju lahko uporabljamo logične veznike ``AND``, ``NOT`` in ``OR``, za
primerjanje stringov lahko uporabimo ``LIKE``, in vrstni red urejanja lahko
povemo z ``ASC`` ali ``DESC``. Obstaja tudi verzija ``SELECT DISTINCT``, ki
izbere samo ne ponavljajoče se vnose.


.. vim: spell spelllang=sl
