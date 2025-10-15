Podatkovne baze
===============

Podatkovne baze so zanesljiv, skalabilen  in praktičen način, kako hraniti
podatke, ki jih nek program potrebuje. V praksi so datoteka ali več datotek na
disku (ali na več diskih), ki ni običajno berljiva, ampak jo lahko spreminjamo
s posebnimi programskimi paketi za določen jezik. Veliko baz podatkov je
zgrajeno na sistemih, ki podpirajo operacije v jezku SQL, to je jezik za delo s
podatki shranjenimi v relacijskih podatkovnih bazah.

Python ima za delo s podatkovnimi bazami modul `sqlite
<https://docs.python.org/3.4/library/sqlite3.html>`_, ki je eden izmed blj
razširjenih implementacij podatkovnih baz, druge znane so še MySQL, PostgreSql, ...

Več o jeziku SQL in impementaciji SQLite si lahko preberete v poglavju
:ref:`osnovesql`.

Za uporabo modula na začetek programa napišemo ``import sqlite3``.
Najprej se moramo vedno povezati z databazo, ki jo želimo uporabljati, to je
datoteka, kjer imamo bazo shranjeno. Če te baze še ni, potem jo ustvari.
Bazo lahko (za vajo) naredimo tudi kar v RAMu, tako da za datoteko damo
argument ``:memory:``.

Ko imamo enkrat povezavo vzpostvaljeno, si naredimo kazalec na našo bazo, in
prek njega pošiljamo poizvedbe (querye) in dobivamo podatke. Primer:

.. py:method:: connect(file)

  Povežemo se z bazo podatkov shranjeno v datoteki ``file``. Vrne
  ``Connection`` objekt.

.. py:class:: Connection

  .. py:method:: cursor()

    Vrne kazalec na bazo podatkov s katerim lahko izvršimo ukaze.

  .. py:method:: close()

    Zapre povezavo, po tem branje in pisanje v bazo ni več mogoče.

.. py:class:: Cursor

  .. py:method:: execute(query, vars)

    Izvede query ``query`` na bazi, kjer ``?`` v queryu zamena s spremenljivkami iz tupla ``vars``, v takem vrtnem redu.

  .. py:method:: executemany(query, vars_iterable)

    Izvede query ``query`` na bazi, kjer ``?`` v queryu zamena s
    spremenljivkami iz seznama tuplov ``vars``, v takem vrtnem redu, za vsak tuple
    svoj query.

  .. py:method:: execute(query)

    Izvede query ``query`` na bazi.

  .. py:method:: fetchone()

    Prebere in vrne en rezultat ``Row`` zadnjega querya.

  .. py:method:: fetchall()

    Prebere in vrne vse rezulate zadnjega querya. Pozor, lahko jih je veliko!

SQLite nam rezultate vrne v razredu ``Row``, ki se obnaša podobno kot ``dict``
ali ``tuple``, podpira iteracijo, indekse ipd ...

.. code-block:: python

  import sqlite3
  conn = sqlite3.connect('example.db')
  c = conn.cursor()
  c.execute('SELECT * FROM ucenci WHERE ime=?', ('Janez',))
  print(c.fetchone())

  # Vstavimo več reči na enkrat.
  novi_ucenci = [('1995-03-28', 'Janez', 'Novak', 1000, 5.00),
                 ('1995-04-05', 'Mojca', 'Kranjc', 1000, 2.47),
                 ('1995-09-06', 'Lara', 'Jazbec', 500, 3.97)]
  c.executemany('INSERT INTO ucenci VALUES (?,?,?,?,?)', novi_ucenci)

.. todo::
  Dodaj code injection warning.
