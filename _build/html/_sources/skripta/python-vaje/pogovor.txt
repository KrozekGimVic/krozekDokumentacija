
Zakodiran pogovor
==================

Naredili bomo program, ki zapisuje in bere zakodirana sporočila v lokalne
datoteke. Zakodiral jih bo z zamikom posameznih znakov npr.
    * zamik za 1 pomeni 'a'->'b', 'b'->'c',..., 'z'->'{'
    * zamik za 500 pomeni 'a'->'ɕ', 'b'->'ɖ',..., 'z'->'ɮ'

Delovanje programa
-------------------------

Program naj vpraša uporabnika za geslo. Geslo je pozitivno celo število, ki pove
za koliko znakov je so zamaknjeni znaki v datoteki.

Program naj nato izpiše odkodirano vsebino datoteke uporabniku. Nato naj
vpraša uporabnika po njegovem imenu, da zapiše v datoteko in nato zapiše še
vsa njegova sporočila.

Primer zakodirane datoteke:

.. code-block:: python

  ȱȱȔɁɕɟɧȔȱȱǾȺɝɦɧɨȕǾȱȱȔɂəɁɕɟɧȔȱȱǾȵȵɕɕɕȵȵȵǾȱȱȔɁȿȔȱȱǾɁɣɞəȔɧɤɣɦɣɗɝɠɣȔɞəȔɧɟɦɝɪɢɣɧɨȕǾɧɨɣɤǾ
  ȱȱȔȵȔȱȱǾɇɈɃɄǾȱȱȔɁɕɟɧȔȱȱǾȼəɞȠȔɨɣȔɞəȔɪəɠɝɟɕȔɧɟɦɝɪɢɣɧɨȕǾɂɝɟɣɠɝȔɢəȔɝɮɘɕɞȔɢɝɗəɧɕɦȢǾɧɨɣɤǾ

Z geslom `500`  jo lahko odkodiramo v

.. code-block:: python

  == Maks ==
  First!
  == NeMaks ==
  AAaaaAAA
  == MK ==
  Moje sporocilo je skrivnost!
  stop
  == A ==
  STOP
  == Maks ==
  Hej, to je velika skrivnost!
  Nikoli ne izdaj nicesar.
  stop



Končan program
----------------
Tukaj lahko :download:`preneseš končan program za kodiranje pogovora <datoteke/chat.py>`, da ga preučiš in si z njim pomagaš pri naslednjih nalogah.

