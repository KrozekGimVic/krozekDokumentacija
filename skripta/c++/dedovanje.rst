Dedovanje
---------

Dedovanje je način, da novi tipi obdržijo (podedujejo) atribute in metode
drugih tipov. Poleg tega lahko dodajo novo obnašanje, ali spremenijo starega.
Slednji koncept se imenuje *overriding*.

Osnove dedovanja
~~~~~~~~~~~~~~~~

Začnimo s preprostim primerom:

.. code-block:: cpp

  class Torta {
    public:
      void peci() { cout << "Torta se pece." << endl; }
  };

  class RojstnodnevnaTorta : public Torta {
    public:
      int st_sveck;
      RojstnodnevnaTorta() : st_sveck(0) {}
      void dodaj_svecke(int n) { st_sveck = n; }
  };

Tukaj razred ``RojstnodnevnaTorta`` deduje od razreda ``Torta``,
saj je rojstnostnodnevna torta posebna vrsta torte - relacija "je"
nakazuje, da je uporaba podrazreda primerna. Po drugi strani, rojstnodnevna
torta ima svečke, kjer relacija "ima" označuje da so svečke njen atribut (in ne
npr. da bi ``RojstnodnevnaTorta`` dedovala od svečke).

Sintaksa oblike  ``class B : public A`` označuje dedovanje, pri čemer ``B``
dobi vse atribute in metode, ki jih ima ``A``. Beseda pubic označuje, da
atributi ohranijo enak nivo dostopa (npr. ``public``, ``private`` ali
``protected``), kot so ga imeli v ``A``. Poleg tega lahko ``B`` doda
novo obnašanje in nove podatke, tako kot smo do zgoraj naredili za rojstnodnevno
torto.

Sedaj lahko uporabljamo v podrazredu tudi podedovane metode osnovnega razreda.

.. code-block:: cpp

  int main() {
      RojstnodnevnaTorta torta;
      torta.peci();  // podedovano od torte
      torta.dodaj_svecke(7);
  }


Konstruktorji in destruktorji
~~~~~~~~~~~~~

Dodajmo v naše razrede še konstruktorje. Razred ``Torta`` naj ima maso, razred ``RojstnodnevnaTorta``
pa še ime slavljenca. Oglejmo si definiciji:

.. code-block:: cpp

  class Torta {
      double masa_;
    public:
      Torta(double masa) : masa_(masa) {}
      void peci() { cout << "Torta se pece." << endl; }
  };

  class RojstnodnevnaTorta : public Torta {
    public:
      string slavljenec_;
      int st_sveck;
      RojstnodnevnaTorta(const string slavljenec, double masa) :
          Torta(masa), slavljenec_(slavljenec), st_sveck(0) {}
      void dodaj_svecke(int n) { st_sveck = n; }
  };

Razred ``Torta`` ima običajen konstruktor, razred ``RojstnodnevnaTorta``
pa mora v konstruktorju kot prvo stvar poklicati nek konstruktor razreda
``Torta``, ki mu v zgornjem primeru poda maso. To se je zgodilo tudi v prejšnjem
primeru, le da ni bilo eksplicitno napisano. Razred ``Torta`` je namreč imel
default konstruktor, ki ne sprejeme parametrov in se je samodejno poklical
pred klicem konstruktorja ``RojstnodnevnaTorta``. Če imamo verigo dedovanja
``D : C : B : A`` se ob konstruiranje objekta ``D`` začne s klicem izbranega
konstruktorja ``A``, nadaljuje z ``B``, ``C``, konstruktor ``D`` pa se pokliče
zadnji, ko so vsi starši že narejeni. Med drgim to pomeni, da so podedovani deli
objekta že konstruirani in lahko npr. kličemo podedovane metode ali uporabljamo
podedovane atribute. V drugih jezikih se tak klic pogosto naredi z uporabo
``super`` (npr. Python, Java).

Pri destruktorjih je zgodba podobna, a obrnjena okrog. Če na razredu tipa ``D``
pokličemo destruktor, se po koncu avtoamtsko pokličejo tudi konstruktorji
staršev, tako da so podedovani atributi od ``A`` uničeni zadnji.

Poglejmo si to še na primeru:

.. code-block:: cpp

  class A {
    public:
      A()  { cout << __func__ << endl; }
      ~A() { cout << __func__ << endl; }
  };

  class B : public A {
    public:
      B() { cout << __func__ << endl; }
      ~B() { cout << __func__ << endl; }
  };

  class C : public B {
    public:
      C() { cout << __func__ << endl; }
      ~C() { cout << __func__ << endl; }
  };

  class D : public C {
    public:
      D() { cout << __func__ << endl; }
      ~D() { cout << __func__ << endl; }
  };

  int main() {
      cout << "test konstruktorjev in destruktorjev:" << endl;
      { D d; }
      return 0;
  }

Makro ``__func__`` je poseben ukaz v C++, ki se tekom prevajanja razširi v ime funkcije, kjer
smo ga uporabili. Če poženemo zgornji program, se izpiše

.. code-block::

  test konstruktorjev in destruktorjev:
  A
  B
  C
  D
  ~D
  ~C
  ~B
  ~A

kar se sklada z zgornjo razlago. Prav tako vidimo, da so vsi klici
konstruktorjev ali destruktorjev staršev avtomatski
in jih prevajalnik sam zgenerira namesto nas.

Slicing
~~~~~~~

Eno izmed osnovnih načel dedovanja je, da lahko spremenljivko bolj specifičnega
tipa shranimo kot manj speficičen tip. Z našim primerom od prej gre sklep tako:
ker je ``RojstnodnevnaTorta`` tudi ``Torta``, lahko spremenljivko tipa
``RojstnodnevnaTorta`` shranimo v spremenljivko tipa ``Torta``.

.. code-block:: cpp

  RojstnodnevnaTorta rt("Janez", 3.4);
  Torta t = rt;

Pri tem zgubimo vse informacije o tem, da je ``t`` kdaj bila
``RojstnodnevnaTorta`` in na spremenljivki ``t`` lahko kličemo le metode in
dostopamo do atributov, ki jih ima ``Torta``. Ta proces se imenuje *slicing*
ali *object slicing*, saj od podobjekta odrežemo stran vse metode in atribute,
ki jih osnovni objekt nima. To je z vidika alokacije prostora smiselno, za
spremenljivko tipa ``Torta`` imamo rezrvirano toliko prostora, kot ga
potrebujemo zanjo in dodatne informacije morajo preč.

Hiding
~~~~~~

Recimo, da sedaj spremenimo definicijo razreda ``RojstnodnevnaTorta``,
tako da ostranimo dodatne konstruktorje in dodamo lastno metodo ``peci``.

.. code-block:: cpp

  class RojstnodnevnaTorta : public Torta {
    public:
      int st_sveck;
      RojstnodnevnaTorta() : Torta(1.0), st_sveck(0) {}
      void dodaj_svecke(int n) { st_sveck = n; }
      void peci() { cout << "Pecem rojstnodnevno torto." << endl; }
  };

in sedaj poglejmo, kaj se zgodi, ko pokličemo

  .. code-block:: cpp

  RojstnodnevnaTorta rt;
  Torta t = rt;
  rt.peci();
  t.peci();

Izpiše se ``Pecem rojstnodnevno torto.``, čemur sledi še ``Torta se pece.``.
To je zato, ker je ``t`` tipa ``Torta``, ``rt`` pa tipa ``RojstnodnevnaTorta``
in metoda ``peci`` se na teh dveh razredih obnaša različno. v veliko programskih
jezikih, npr. v Javi, bi se obakrat izpisalo ``Pecem rojstnodnevno torto.``,
saj bi jezik se vedno vedel, da se, kljub temu, da je ``t`` tipa ``Torta``, v
njem skriva ``RojstnodnevnaTorta``. V C++ zaradi slicing-a temu ni tako.
Z zgornjim primerom smo dosegli le, da na objketu ``rt`` ne moremo več direktno
metode ``peci`` iz razreda ``Torta``, saj jo je skrila enako imenovana metoda
``peci`` iz razreda ``RojstnodnevnaTorta``.
Temu procesu se v angleščini reče *hiding*, saj metoda iz podrazreda
prepreči dedovanje (skrije) metode iz osnovnega razreda, ki imajo enako ime.
To bi se zgodilo tudi, če metoda
``peci`` ne bi imela poponoma enakih parametrov, kot metoda ``peci`` iz razreda
``Torta``. Primer:

.. code-block:: cpp

  class RojstnodnevnaTorta : public Torta {
    public:
      int st_sveck;
      RojstnodnevnaTorta() : Torta(1.0), st_sveck(0) {}
      void dodaj_svecke(int n) { st_sveck = n; }
      void peci(int m) { cout << "Pecem rojstnodnevno torto za " << m << "minut." << endl; }
  };

Tudi v tem primeru prek objekta ``rt`` ne bi morali poklicati ``rt.peci()`` brez
parametrov, saj se to sklicuje na skrito (in zato ne podedovano) metodo ``peci``
iz razreda ``Torta``.  Dobimo napako:

.. code-block::

  torta.cpp: In function ‘int main()’:
  torta.cpp:21:13: error: no matching function for call to ‘RojstnodnevnaTorta::peci()’
       rt.peci();
               ^
  torta.cpp:15:10: note: candidate: ‘void RojstnodnevnaTorta::peci(int)’
       void peci(int m) { cout << "Pecem rojstnodnevno torto za " << m << "minut." << endl; }
            ^~~~
  torta.cpp:15:10: note:   candidate expects 1 argument, 0 provided

ki pove le, da smo metodo ``peci`` poklicali narobe. Prevjalnik ``clang++`` je
tukaj bolj uporabniku prijazen:

.. code-block::

  torta.cpp:21:8: error: too few arguments to function call, expected 1, have 0; did you mean 'Torta::peci'?
      rt.peci();
         ^~~~
         Torta::peci
  torta.cpp:6:10: note: 'Torta::peci' declared here
      void peci() { cout << "Torta se pece." << endl; }
           ^
  1 error generated.

in namigne, da smo morda želeli poklicati metodo iz osnovnega razreda.
Če želimo poleg metod v podrazredu tudi metode z enakim
imenom iz osnovnega razreda, moramo njihovo dedovanje eksplicitno zahtevati.
To lahko storimo z ukazom ``using``, kot v primeru spodaj.

.. code-block:: cpp

  class RojstnodnevnaTorta : public Torta {
    public:
      int st_sveck;
      RojstnodnevnaTorta() : Torta(1.0), st_sveck(0) {}
      void dodaj_svecke(int n) { st_sveck = n; }
      using Torta::peci;
      void peci(int m) { cout << "Pecem rojstnodnevno torto za " << m << "minut." << endl; }
  };

Sedaj imamo na voljo tako ``rt.peci()`` (eksplicitno podedovano iz razreda ``Torta``) in ``rt.peci(7)``
iz razreda ``RojstnodnevnaTorta``.
Če bi imeli obe metodi isto ime, ki morali (pa tudi sedaj lahko) metodo iz
osnovnega razreda klicati z polno kvalificiranim imenom kot ``rt.Torta::peci()``.
Zanekrat sicer še ne vemo, kaj so virtualne
metode, toda princip skrivanja je zanje enak kot za običajne metode (kadar ne
pride v igro overriding).

Polimorfizem
~~~~~~~~~~~~
TODO

Primer:
.. code-block:: cpp

  #include <string>
  #include <iostream>
  #include <vector>
  #include <memory>

  using namespace std;

  struct Being {
    virtual string zadnje_besede() const = 0;
    void die() {
      cout << zadnje_besede() << endl;
    }
    virtual ostream& print(ostream& os) const {
      return os << "bitje";
    }
    virtual ~Being() {}
  };
  ostream& operator<<(ostream& os, const Being& b) {
    return b.print(os);
  }

  struct Plant : public Being {
    string zadnje_besede() const override {
        return "Screw vegans.";
    }
  };

  struct Animal : public Being {
    virtual string oglasanje() const = 0;
    string zadnje_besede() const override {
      return "Ouch.";
    }
    ostream& print(ostream& os) const override {
      Being::print(os);
      return os << " animal:";
    }
  };

  struct Dog : public Animal {
    string name;
    Dog(string name) : name(name) {}
    string oglasanje() const override {
      return "Hov " + name;
    }
    string zadnje_besede() const override {
      return "Wasn't I a good boy?";
    }
    ostream& print(ostream& os) const override {
      Animal::print(os);
      return os << " Dog: " << name;
    }
  };

  struct Cat : public Animal {
    string oglasanje() const override {
      return "Nyaa";
    }
  };

  struct Duck : public Animal {
    string oglasanje() const override {
      return "Quack";
    }
  };

  int main() {
    // Animal a;

    vector<unique_ptr<Animal>> v;
    v.push_back(make_unique<Dog>("Piki"));
    v.push_back(make_unique<Cat>());
    v.push_back(make_unique<Dog>("Fido"));
    v.push_back(make_unique<Duck>());
    v.push_back(make_unique<Dog>("Jakob"));
    v.push_back(make_unique<Cat>());

    /*
    for (const auto& p : v) {
      cout << p->oglasanje() << endl;
    }*/

    vector<unique_ptr<Being>> b;
    b.push_back(make_unique<Dog>("Piki"));
    b.push_back(make_unique<Cat>());
    b.push_back(make_unique<Duck>());
    b.push_back(make_unique<Plant>());
    for (const auto& p : b) {
      p->die();
      try {
        // cout << typeid(p.get()).name() << endl;
        Animal* a = dynamic_cast<Animal*>(p.get());
        if (a == nullptr) {
          cout << "a is null" << endl;
        } else {
          // cout << "here" << endl;
          cout << a->oglasanje() << endl;
          // cout << "here" << endl;
        }

      } catch (std::bad_cast& bc) {
        cout << "to ni Animal" << endl;
      }
    }

    cout << "------------------" << endl;
    for (const auto& p : b) {
      cout << *p << endl;
    }


    Dog d("Fifi");
    cout << d << endl;

    return 0;
  }
