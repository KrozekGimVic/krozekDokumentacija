
Psevdo besede
==============

Naredili bomo generator psevdo-slovenskih besed; to so besede, ki zvenijo slovenske, in se zdijo slovenske, a v resnici niso v Slovarju Slovenskega Knjižnega Jezika::

  nevkopiski črtolem naparemearnski ročevenka prebejeniščen
  obojčen kritavka kobavacija hročnomski

To bomo storili tako, da bomo analizirali vse slovenske :download:`besede<datoteke/besede.txt>` in na podlagi tega generirali nove besede.

Analiza slovenskih besed
-------------------------

Preglej vse besede in si shrani kako pogosto se za vsako črko pojavi kakšna druga črka. To najlažje narediš z uporabo imenikov v pythonu. Recimo, da imamo imenik z imenom ``analiza``, potem naj ``analiza['c']['l']`` pove kolikokrat se črka 'l' pojavi za črko 'c' v vseh besedah SSKJ.

Uporabi presledek ' ', kot poseben znak, ki označuje konec in začetek besed. Torej naj ``analiza[' ']['u']`` pove koliko besed se začne z 'u' in ``analiza['r'][' ']`` koliko besed se konča s črko 'r'.

Generator besed
-----------------
Iz imenika ``analiza`` naredi nove besede tako, da po vsaki črki naključno izbereš novo črko, ampak naj bodo večkrat pojavljeni pari črk bolj verjetni.

Posodobitev
------------
Izboljšaj :download:`prejšnji program za analizo besed <datoteke/psevdo_besede.py>` tako, da uporabiš daljšo zgodovino črk. Torej namesto da opazuješ samo prejšnjo črko opazuj prejšnji dve črki, ali prejšnje tri, ali kar v splošnem ``n`` črk.

Za ``n=2``, bi imel imenik vnos ``analiza['ri']['b']``, ki bi nam povedal kolikokrat se je za nizom 'ri' pojavila črka 'b'.

