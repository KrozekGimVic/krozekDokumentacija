.. |nbsp| unicode:: 0xA0
   :trim:

Projekti dijakov
================

Do zaključka leta lahko dijaki začnejo delati na svojih projektih. Idealno bi
bilo delo v parih. Tukaj je navedenih nekaj primerov, ki jih lahko dijaki
uporabijo kot inspiracijo pri zbiranju idej za svoje projekte.


Nadgradnja naše igre
--------------------

Na krožku smo naredili `igro <https://github.com/MKolman/pygame-test>`_, ki ima
še veliko možnosti za izboljšave. Nekdo jo lahko prevzame in doda kakšno novo
mehaniko ali polepša slike.

Bojevanje iz ptičje perspektive
--------------------------------

Igra pri kateri vodimo našega junaka (ali več junakov) iz ptičje perspektive.
Opremljen je z orožjem (strelno, hladno,...), da se lahko brani pred nasprotniki
in išče zaklad/cilj/princeso.

`Primere takih iger lahko vidite s klikom na to povezavo
<https://www.google.com/search?q=top+down+fighting&tbm=isch>`_.


Pobeg iz labirinta
------------------

Zgradite si labirint z enim izmed `znanih naključnih algoritmov
<https://en.wikipedia.org/wiki/Maze_generation_algorithm>`_ in nato pošljete
igralca, da najde pot od začetka do konca.

Če želite otežiti delo sebi in igralcem, naredite prvoosebno perspektivo
igranja, kjer igralec nikoli ne vidi celotnega labirinta.

Svojo kodo lahko povežete s prejšnjim primerom bojevanja, tako da postavite
labirint v katerem se odvija bitka.

Štiri v vrsto
-------------

Naredite igro `štiri v vrsto <https://www.google.com/search?q=connect+four&tbm=isch>`_,
kjer dva igralca izmenično mečeta žetone različnih barv v polje velikosti 7x6.
Kdor prvi zapolni štiri zaporedna kolinearna polja zmaga.

Če iščete izziv, je to popolna igra za implementacijo umetne inteligence, ki
igra igro proti nam. Najenostavnejši algoritem za to je  `minimax
<https://en.wikipedia.org/wiki/Minimax>`_.

Izboljšana igra tri v vrsto
---------------------

Običajna verzija `igre tri v vrsto
<https://www.google.com/search?q=tic+tac+toe&tbm=isch>`_ je točno rešljiva  (v
vsakem stanju igre poznamo `optimalno potezo <https://xkcd.com/832/>`_), zato ni
zanimiva za igranje ali programiranje.

Kompleksnejša igra tri v vrsto se igra na več 3x3 poljih hkrati, samo s simbolom
X (brez O) in igralec, ki prvi postavi tri X v vrsto zgubi, ne zmaga.
Podrobnejši opis `lahko vidite tukaj <https://youtu.be/ktPvjr1tiKk>`_.

Ponovno lahko poskusit implementirati algoritem  `minimax
<https://en.wikipedia.org/wiki/Minimax>`_. Preizkusite ali lahko naredite
dovolj dober program, da vas premaga.

Zakodiran zapisnik ali dnevnik
------------------------------

Grafično opremljen program v katerem lahko pišemo in shranimo besedilo.
Shranjenega besedila ne sme biti možno prebrati brez gesla.

Program lahko izboljšamo tako, da dodamo možnost kompleksenjšega urejanja
besedila: barvni tekst, krepke črke, poševne črke, spreminjanje velikosti
črk,...

Možna nadgradnja programa je pošiljanje zakodiranih sporočil preko interneta. To
lahko naredite sami, ali pa uporabite npr. Facebook chat.

Facebook messenger bot
----------------------

Nadgradnja `našega Facebook robotka <https://github.com/KrozekGimVic/chatbot>`_.
Najdi in napiši nove načine interakcije z `uradnim robotkom programerskega
krožka <https://www.facebook.com/profile.php?id=100014758833030>`_.

Npr. igranje vislic, igranje tri v vrsto, napoved vremena, postavljanje
ugank,...

Reševalec sudokuja
------------------

Vsi poznamo igro `sudoku <https://www.google.com/search?q=sudoku&tbm=isch>`_.
Računalniki so precej dobri v reševanju takšnih problemov.

Iz :download:`tukaj<datoteke/1000sudoku_plain.txt>` lahko prenesete 10000 sudokujev
in jih poskusite rešiti z vašim programom.
