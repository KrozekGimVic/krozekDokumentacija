.. _pointers:

Kazalci in reference
====================

Kazalci so malo podobni iteratorjem,
ki smo jih srečali že v poglavju :ref:`podatkovnitipi` / :ref:`iteratorjiuvod`,
reference pa smo že srečali v poglavju :ref:`funkcijecpp` / :ref:`referenceuvod`.

Reference
---------

Reference so spremenljivke, ki predstavljajo drugo ime za isto spremenljivko.
Če imamo spremenljivko tipa ``T``, ima referenca nanjo tip ``T&``.

.. code-block:: cpp

  int a = 7;
  int& b = a;
  a = 8;
  cout << a << " " << b << endl;
  b = 9;
  cout << a << " " << b << endl;

V zgornjem primeru je ``b`` referenca na ``a``, tako da ko spremenimo ``a``, se
spremeni tudi ``b`` in obratno. Tako se izpiše ``8 8`` in ``9 9``.

Lahko imamo tudi konstantne reference, to so reference, ki dovolijo spreminjanja
svoje vrednosti. Če imamo konstantno spremenljivko, lahko nanjo naredimo le
konstantno referenco, lahko pa konstantno referenco naredimo tudi na običajno
spremenljivko. O taki referenci razmišljamo kot o *pogledu* na spremenljivko,
saj lahko prek nje samo opazujemo, kaj se dogaja, ničesar pa ne moremo
spreminjati.

Referenca ne more biti prazna in vedno kaže na neko spremenljivko. Še vedno pa ne
na programerju, da pazi, da referenca kaže na veljavno spremenljivko, ki še ni
bila uničena. Tako npr. ne smemo iz funkcije vračati referenc na lokalne
spremenljivke. Primer reference na neveljavno spremenljivko:

.. code-block:: cpp

  int a = 7;
  int& b = a;
  { int c = 8; b = c; }
  cout << b << endl;

Spremenljivka ``b`` je referenca na ``c``, ki je že izbrisana. Program sicer v
veliko primerih pravilno izpiše 8, toda to ni zagotovljeno, se  splošnem ne
zgodi in se na tako obnašanje ne moremo zanašati. Zgornji program je preprosto
neveljaven, četudi občasno deluje.

.. note::

  Če definiramo več referenc na isti vrstici, moramo znak ``&`` ponoviti.

  .. code-block:: cpp

    int& r1 = v1, &r2 = v2, &r3 = v3;

  Zgornja koda ustvari tri reference ``r1, r2, r3`` na spremenljivke ``v1, v2,
  v3``.


Naslovi spremenljivk
--------------------
C++ programerju omogoča, da pogleda, na katerem naslovu v spominu je shranjena
določena spremenljivka. O strukturi spomina bomo govorili kasneje, sedaj povejmo
le, da si program predstavlja, kot da je spomnim dolga enodimenzionalna
tabela, razdeljena na celice po 1 bajt. Vrednost spremenljivke ``int a`` je
shranjena nekje v tej tabeli; ker je ``int`` ponavadi velik 4 bajte zavzema 4
bajte. S pomočjo *operatorja* ``&``, ki se mu reče operator "naslov od"
(*address of*) lahko dobimo naslov spremenljivke. Če spremenljivka zavzema več
kot eno celico, dobimo naslov prve celice, ki jo zavzema. Primer:

.. code-block:: cpp

  int a = 7;
  cout << &a << endl;

Zgornja koda izpiše naslov spremenljivke, nekaj podobnega ``0x7ffe78a6f354``,
kar je zaporedna številka (v šestnajstiškem sistemu) celice, kjer se ``a`` nahaja.
Naslov je vedno številka znane velikosti, praviloma 32 bitov na 32 bitnih
računalnikih in 64 bitov na 64 bitnih.

.. warning::

  Za ustvarjenje referenc uporabljamo enak znak ``&`` kot za pridobivanje
  naslovov spremeljivk, toda enkrat je ta sestavni del tipa spremenljivke,
  drugič pa nastopa kot operator, tako da je vedno možno iz konteksta ugotoviti,
  za katerega gre.


Kazalci
-------

Kazalci (*pointers*) izvirajo iz jezika C, predhodnika C++, in so v C-ju edini način, da
spremenimo vrednost parametra znotraj funkcije.
Kazalec na spremenljivko ``a`` tipa ``T`` je spremenljivka, katere tip se označi z
``T*`` in njena vrednost pa je naslov spremenljivke ``a``.
Primer definicije:

.. code-block:: cpp

  int a = 7;
  int* p = &a;
  cout << p << endl;

Zgornja koda izpiše nekaj podobnega  ``0x7ffe78a6f354``, saj je vrednost
spremenljivke ``p`` naslov spremenljivke ``a``. Pravimo, da je spremenljivka ``p``
kazalec na ``a``. Tip ``int*`` pomeni, da je vrednost, ki je na naslovu, ki je
shranjen v ``p``, v spominu shranjeno celo število. Ta tip nima direktne
povezave s tem, da je naslov sam po sebi tudi celo število, to je tako ali tako
vedno.

Najosnovnejša operacija na kazalcih je operacija, ki dobi vrednost na nekem naslovu.
Operacija se imenuje *value of* oz. dereferenca in se ga označi z ``*``.
Z njegovo pomočjo dobimo ali nastavimo vrednost na nekem mestu v spominu.
Primer:

.. code-block:: cpp

  double a = 7.5;
  double* p = &a;  // npr. 0x7ffe78a6f354
  cout << *p << endl;
  *p = 8.5;
  cout << a << endl;

Zgornji primer izpiše  ``7.5`` in ``8.5``, saj izraz ``*p = 8.5`` na mesto
``0x7ffe78a6f354`` (kjer je spremenljivka ``a``) shrani vrednosti ``8.5``.
Tukaj tudi vidimo, zakaj je dobro vedeti tip, na katerega kazalec kaže. Sama
vrednost ``0x7ffe78a6f354`` se namreč nanaša na prvi bajt spomina in
zaradi tipa ``double`` vemo, da moramo prebrati še naslednjih 7 in jih
interpretirati kot decimalno število.

.. note::

  Če definiramo več kazalcev na isti vrstici, moramo podobno kot pri referencah znak ``*`` ponoviti.

  .. code-block:: cpp

    int* p1 = &v1, *r2 = &v2, *r3 = &v3;

  Zgornja koda ustvari tri reference ``r1, r2, r3`` na spremenljivke ``v1, v2,
  v3``.

.. warning::

  Za ustvarjenje kazalcev uporabljamo enak znak ``*`` kot za dobivanje vrednosti
  na danem naslovu. Toda podobno kot pri referencah je enkrat ``*`` sestavni del
  tipa spremenljivke, drugič pa nastopa kot operator, tako da je vedno možno iz
  konteksta ugotoviti, za katerega gre.

vrednosti kazalcev so vedno naslovi, ki smo jih dobili iz obstoječe
spremenljivke ali sistema. Ne moremo npr. narediti kar

.. code-block:: cpp

  char* p = 20;
  *p = 'h';

da bi na mesto `20`` v spominu napisali znak ``h``. Že preajalnik se bo
pritožil

.. code-block:: none

  a.cpp:2:15: error: invalid conversion from ‘int’ to ‘char*’ [-fpermissive]
     char* p = 20;
               ^~

Če pa z eksplicitno pretvorbo to vseeno nastavimo, se program sesuje, saj
najverjetneje do celice 20 nimamo dostopa in dobimo napako ``[1]    24346
segmentation fault (core dumped)``.

Null pointer
~~~~~~~~~~~~

Z razliko od referenc kazalci lahko ne kažejo nikamor. To povemo tako, da jim
damo vrednost 0, ki predstavlja naslov ``0x000000000``, za kar imamo direktno
besedo ``nullptr``. Tako lahko naredimo

.. code-block:: cpp

  int* p = nullptr;

Če je ``p`` ničelni kazalec, je neveljavno pogledati rednost na tem mestu --
zagotovljeno je, da to vedno povzroči napako.

.. note::

  Nastaviti ``p`` na ``nullptr`` je drugače, kot pustiti nenastavljenega; v tem
  primeru bi bila njegova vrednost nenastavljena in bi bila karkoli je ostalo v
  spominu, kjer je bil ``p`` ustvarjen.


Delo s spominom
---------------

Spomin za spremenljivke v programih lahko dobimo na več načinov: pravimo da so
spremenljivke lahko na skladu (*stack*), ali pa na kopici (*heap*).
Obstajajo tudi drugi predeli, za npr. statične ali globalne spremenljivke, konstantne
podatke, itd..., s katerimi se zdaj ne bomo ukvarjali. Tako sklad kot
kopica sta dela RAMa, kjer lahko naredimo spremenljivke. Za običajne lokalne
spremenljivke je prostor rezerviran na skladu že med prevajanjem programa
in dostop do njih je ponavadi hitrejši. Če kličemo funkcijo, ki kliče funkcijo,
ki imajo vsaka svoje lokalne spremenljivke, se te nalagajo v spomin po vrsti
ko gremo globlje v klicih in sprostijo, ki se z njih vračajo. velikost sklada je
tudi omejena, na Linuxu jo lahko dobimo z ukazom ``ulimit -a``.

Z razliko od sklada se alokacija na kopici dogaja med tekom programa,
spremenljivke na kopici so nepovezane med seboj, dostop do nje je ponavadi
počasnejši, ima pa mnogo več prostora, ki je omejen le z velikostjo virtualnega
spomina, ki je na voljo programu (beri: z velikostjo RAMa).
Spomin na kopici lahko zahtevamo od operacijskega sistema, ga poljubno
uporabljamo in lepo je, da ga na koncu tudi vrnemo.
V C-ju imamo za alokacijo in dealokacijo para funkcij ``malloc`` (*memory
allocation*) in ``free``, v C++-u pa sta nadomeščeni z operatorji
``new``, ``new[]``, ``delete`` in ``delete[]``.
Verziji z ``[]`` sta namenjeni alokaciji tabel in se bomo z njimi ukvarjali
pozneje. Alokaciji spomina na kopici se pogosto reče tudi *dinamična alokacija*.

Alokacija spomina vrne kazalec na mesto v RAMu, kjer nam je bi dodeljen prostor
za spremenljivko. Če je bila alokacija neuspešna (npr. zmanjkalo nam je
spomina), C++ vrže izjemo tipa ``std::bad_alloc``. Obstaja več verzij operatorja
``new``, ki spomin alocirajo na različne načine, npr. brez metanja izjem,
na že določeno mesto, ali pa brez konstrukcije alociranega objekta, toda tudi v
to se ne bomo spuščali.

Primer običaje alokacije decimalnega števila:

.. code-block:: cpp

  int main() {
      double* p = new double(2.3);  // p ima vrednost 2.3
      double* q = new double();     // q ima vrednost 0.0
      double* r = new double;       // r ima nedefinirano vrednost
      // uporabljamo p, q, r
      delete p;  // vrnemo spomin sistemu
      delete q;
      delete r;
  }



.. vim: spell spelllang=sl
