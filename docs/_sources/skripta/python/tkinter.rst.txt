Tkinter
==============

Pythonovo knjižnico tkinter (stoji za tk interface) uporabljamo, če želimo prikazovati sistemska okna in narediti aplikacijo z grafičnim vmesnikom.

Če želimo uporabljati moramo izvesti ukaz import. Za lažje pisanje bomo tu uporabljali skrajšan zapis `tk`

.. code-block:: python

  import tkinter as tk

S tem je povsem lahko ustvariti prazno okno. Vse kar je potrebno storiti je narediti razred Tk::

  okno = tk.Tk()

Ampak sedaj bo okno izginilo takoj, ko se naš prgram zaključi. Da se ohrani, tudi po zaključku našega programa lahko na koncu zaženemo::

  okno.mainloop()

Da popestrimo prazno puščavo praznega okna lahko dodamo vanj t.i. widget ali gradnik. To so bodisi gumbi, tekst, slike, vnos, meni,... Spodaj je seznam gradnikov, ki jih lahko uporabljamo.

  * `Button <http://effbot.org/tkinterbook/button.htm>`_
  * `Canvas <http://effbot.org/tkinterbook/canvas.htm>`_
  * `Checkbutton <http://effbot.org/tkinterbook/checkbutton.htm>`_
  * `Entry <http://effbot.org/tkinterbook/entry.htm>`_
  * `Frame <http://effbot.org/tkinterbook/frame.htm>`_
  * `Label <http://effbot.org/tkinterbook/label.htm>`_
  * `LabelFrame <http://effbot.org/tkinterbook/labelframe.htm>`_
  * `Listbox <http://effbot.org/tkinterbook/listbox.htm>`_
  * `Menu <http://effbot.org/tkinterbook/menu.htm>`_
  * `Menubutton <http://effbot.org/tkinterbook/menubutton.htm>`_
  * `Message <http://effbot.org/tkinterbook/message.htm>`_
  * `OptionMenu <http://effbot.org/tkinterbook/optionmenu.htm>`_
  * `PanedWindow <http://effbot.org/tkinterbook/panedwindow.htm>`_
  * `Radiobutton <http://effbot.org/tkinterbook/radiobutton.htm>`_
  * `Scale <http://effbot.org/tkinterbook/scale.htm>`_
  * `Scrollbar <http://effbot.org/tkinterbook/scrollbar.htm>`_
  * `Spinbox <http://effbot.org/tkinterbook/spinbox.htm>`_
  * `Text <http://effbot.org/tkinterbook/text.htm>`_

Vstavljanje gradnikov
----------------------
Ko naredimo nov gradnik moramo povedati v katero okono ga želimo vstaviti. Ko pa ga želimo vstaviti v okno moramo povedati na katero mesto ali pa pustiti da ga sam postavi kamor želi. Spodaj je najenostavneši primer okna z nekaj besedila.

.. code-block:: python

  import tkinter as tk      # Uvozimo tkinter

  # Naredimo prazno okno
  okno = tk.Tk()
  # Damo mu ime 'Ime okna'
  okno.title("Ime okna")
  # Če želimo mu lahko na roko nastavimo velikost
  okno.geometry("600x400")

  # Naredimo nov besedilno etiketo
  besedilo = tk.Label(okno, text="Pozdravljen krožek!")

  # Besedilo samodejno zapakiramo v okno
  besedilo.pack()
  # Alternativno lahko uporabimo ključno besedo side
  besedilo.pack(side=tk.LEFT)

Če želimo naše gradnike lepo urediti lahko za to uporabimo okvirje (gradniki ``Frame``), ki nimajo druge funkcije kot vsebovanja drugih gradnikov. Lahko pa namesto metode ``pack`` uporabimo ``grid``, ki nam daje natančnejšo kontrolo nad pozicijo vstavljenega gradnika.

.. code-block:: python

  import tkinter as tk

  # Naredimo prazno okno in ga poimenujemo
  okno = tk.Tk()
  okno.title("Vpiši se")

  # Naredimo dve besedilni etiketi
  ime = tk.Label(okno, text="Uporabniško ime:")
  geslo = tk.Label(okno, text="Geslo:")

  # Naredimo dve vhodni okni za geslo in ime
  ime_in = tk.Entry(okno)
  geslo_in = tk.Entry(okno, show="*")

  # Naredimo funkcijo, ki bo izpisala uporabniško ime in geslo
  def izpisi():
      print(ime_in.get(), geslo_in.get())

  # Naredimo gumb, ki bo klical zgornjo funkcijo
  gumb = tk.Button(okno, text=u"Vpiši me!", command=izpisi)

  # Uporabimo grid, da vse postavimo v okno
  ime.grid(row=0, column=0, sticky=tk.E)
  geslo.grid(row=1, column=0, sticky=tk.E)
  ime_in.grid(row=0, column=1)
  geslo_in.grid(row=1, column=1)
  gumb.grid(row=2, column=0, columnspan=2)

