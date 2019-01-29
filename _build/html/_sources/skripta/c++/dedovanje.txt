Dedovanje
---------

Dedovanje je način, da novi tipi obdržijo (podedujejo) atribute in metode
drugih tipov. Poleg tega lahko dodajo novo obnašanje, ali spremenijo starega.
Slednji koncept se imenuje *overriding*.

Začnimo s preprostim primerom:

.. code-block:: cpp

  class Torta {
    public:
      void peci() { cout << "Torta se peče" << endl; }
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

Sintaksa oblike  ``class B : public A`` označuje dedovanje, pri čemer ``A``
dobi vse atribute in metode, ki jih ima ``A``. Beseda pubic označuje, da
atributi ohranijo enak nivo dostopa (npr. ``public``, ``private`` ali
``protected``), kot so ga imeli v ``A``. Poleg tega lahko ``B`` doda
novo obnašanje in nove podatke, tako kot smo do zgoraj naredili za rojstnodnevno
torto.

Sedaj lahko uporabimo podrazred tako kot bi uporabjali osnovnega:

.. code-block:: cpp

  int main() {
      RojstnodnevnaTorta torta;
      torta.peci();  // podedovano od torte
      torta.dodaj_svecke(7);
  }

TODO: sicing, hiding, virtual functions, dynamic_cast

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
