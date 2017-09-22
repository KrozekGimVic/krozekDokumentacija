Želvja grafika
==============

Želvja grafika je enostaven načina risanja in zelo dobra za učenje
programiranja, sal lahko hitro pogledamo in vidimo, ali pogram deluje pravilno
ali ne. Začne se tako, da imamo želvo (puščico) na koordinatah (0, 0) v xy
ravnini.

Na voljo imamo veliko ukazov:

.. py:function:: forward(x)

  Premakne želvo naprej za ``x`` pikslov. Skrajšano ``fd``.

.. py:function:: backward()

  Premakne želvo nazaj za ``x`` pikslov. Skrajšano ``bk`` ali
  ``back``.

.. py:function:: right(kot)

  Zavrti želvo v desno za ``kot`` stopinj. Skrajšano ``rt``.

.. py:function:: left(kot)

  Zavrti želvo v levo za ``kot`` stopinj. Skrajšano ``lt``.

.. py:function:: goto(x[, y])

  Postavi želvo na (``x``, ``y``). Če ``y`` ni podan, potem se pričakuje, da je
  ``x`` seznam dveh števil, ki predstavljata koordinati. Lahko tudi ``setpos``
  ali ``setposition``.

.. py:function:: setheading(kot)

  Nastavi želvo, da gleda pod kotom ``kot`` glede na x os. Skrajšano ``seth``.

.. py:function:: circle(r)

  Nariče krog s polmerom ``r`` okrog želvice.

.. py:function:: speed(n)

  Nastavi hitrost želvice od 1 do 10 (počasneje do najhitreje). Če je ``n`` 0,
  pa to ne pomeni najpočaneje, ampak najhitreje.

.. py:function:: pendown()

  Položi želvico na tla, ko se želvica premika, pušča sled. Krajše tudi ``pd``
  ali ``down``.

.. py:function:: penup()

  Dvigne želvico iz tal, ko se želvica premika ne pušča sledi. Krajše tudi
  ``pu`` ali ``up``.

Več metod za delo dobite `tukaj
<https://docs.python.org/3.4/library/turtle.html#turtle-methods>`_.

Za delo z želvjo grafiko je potrebno dobiti funkcije iz modula ``turtle``, kar
naredimo tako, da na začetek programa napišemo ``import turtle``, nato pa
uporabljamo funkcije iz tega module kot ``turtle.funkcija()``.

Za primer narišimo kvadrat.

.. code-block:: python
  :linenos:

  # -*- coding: utf-8 -*-

  import turtle

  # Ustvarimo okno
  okno = turtle.Screen()
  # Ustvarimo želvico
  leonardo = turtle.Turtle()

  # Izrišemo kvadrat s premikanjem naprej in zavijanjem v levo
  leonardo.forward(100)
  leonardo.right(90)
  leonardo.forward(100)
  leonardo.right(90)
  leonardo.forward(100)
  leonardo.right(90)
  leonardo.forward(100)

  turtle.done()

Funkcija ``turtle.done()`` nam okno obdrži na zaslonu, tudi po tem ko se
program konča. Namesto tega bi lahko uporabili ``turtle.exitonclick()`` ki
naredi isto kot done, le da nam program zapre ob kliku z miško (uporabno na
šolskih Windows računalnikih, saj se okna drugače občasno ne da zapreti).

.. vim: spell spelllang=sl
