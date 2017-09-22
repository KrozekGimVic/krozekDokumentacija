.. |nbsp| unicode:: 0xA0
   :trim:

Vislice
============

Pri tej nalogi bomo napisali igro vislice, ki jo bomo lahko igrali kar v ukazni vrstici::

  ╔════════════╗
  ║  _______   ║
  ║ |   |  \|  ║
  ║   (o_O) |  ║
  ║    \|   |  ║
  ║         |  ║
  ║         |  ║
  ║         |  ║
  ║         |  ║
  ║        --- ║
  ╚════════════╝
  s, u, c, p
  _ a _ v i _ _ _
  Ugibaj:

Datoteke
-----------
Pri poteku te naloge ti morda prav pridejo naslednje datoteke:

  * :download:`besede.txt<datoteke/besede.txt>` seznam vseh slovenskih besed, ki vsebujejo vsaj tri različne črke.
  * :download:`besede2.txt<datoteke/besede2.txt>` seznam najpogostejših slovenskih besed, ki vsebujejo vsaj tri različne črke.
  * :download:`slike.py<datoteke/slike.py>` seznam unicode slikic za igranje vislic.

Razred besed
---------------
Naredi razred, ki v konstruktorju prejme ime datoteke in iz nje prebere vse besede in jih naključno premeša. Razred naj ima metodo, ki vrne naslednjo besedo po vrsti.

Razred vislice
----------------
Razred vislice naj v konstruktorju prejme generator besed (razred iz prejšnjega poglavja) in seznam slik vislic. Razred naj ima metodo, ki

 * sprejme uporabnikovo črko in jo pravilno vstavi v igro
 * vrne pravilno sliko glede na stanje igre (število napak)
 * pove stanje igre (ali je igra izgubljena/zmagana/v teku)
 * vrne seznam ugotovljenih in neugotovljenih črk (_ a _ v i _ _ _)
 * ponastavi razred za začetek nove igre

Uporabniški vmesnik
--------------------
Uporabi zgornja razreda, da simuliraš igro vislic z uporabnikom. Dokler je igra v teku zahtevaj nov vnos črke in jo dodaj v igro. Ko uporabnik bodisi zmaga, bodisi izgubi naj se program ponovi, bodisi zaključi.

Razred za pomoč uporabniku
---------------------------
Napiši razred, ki igralcu pomaga, ko ta potrebuje ali prosi za pomoč. Naj daje namige oblike

  * Beseda vsebuje 5 različnih črk.
  * Manjka ti še en samoglasnik.
  * V besedi ni črke u.
  * Uganki ustreza še skupno 152 besed.

Izdelek
----------
Na tej povezavi si lahko prenesete delujoč program:
:download:`vislice.py<datoteke/vislice.py>`.

Grafični vmesnik
-----------------
Uporabi knjižnico tkinter, da narediš okno v katerem lahko uporabnik igra vislice. V pomoč so ti lahko te :download:`zbrane slike <datoteke/slike_vislice.zip>`.
