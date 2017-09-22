Funkcije
--------

Zakaj potrebujemo funkcije si preberite v :ref:`funkcijepython` za python.

Pri c++ moramo za vsako funkcijo vedeti,katere tipe sprejme in kakšen tip vrne.
Pravzaprav smo vedno morali napisati definicijo funkcije ``main`` in za ostale
funkcije je sintaska enaka.

Sintaksa
~~~~~~~~

Definicija funkcije v C++ ima nastednjo sintakso (posplošimo na poljubno število
parametrov):

.. code-block:: cpp

  return_type ime_funkcije(tip1 parameter1, tip2 parameter2) {
      // koda
  }

Funkcija, ki nič ne vrne, ima return_type ``void``. Funkcijo moramo vedno
definirati preden jo uporabimo, to je ponavadi nad funkcijo ``main``.

Vračanje rezultatov
~~~~~~~~~~~~~~~~~~~

Če hočemo, da funkcija kaj vrne, to povemo z ukazom ``return``. Tip
spremenljivke ki jo vračamo se mora ujemati s tipom, ki smo ga napisali v
funkciji.

Primer funkcije, ki preveri, ali je dano število popolno.

.. code-block:: cpp

  bool popolno(int n) {
      int vsota_deliteljev = 0;
      for (int i = 1; i < n; ++i) {
          if (n % i == 0) {
              vsota_deliteljev += i
          }
      }
      return vsota_deliteljev == n;
  }

Klicanje funkcij
~~~~~~~~~~~~~~~~

Ko izvedemo program, ki vsebuje samo definicije funkcij, se ne zgodi nič.
Funkcijo je treba namreč še poklicati. Naše funkcije kličemo popolnoma enako kot
že vdelane funkcije (npr. sin(), sort()).

.. code-block:: cpp

  // definicija bool popolno(int n);

  int main() {
      int n;
      cin >> n;
      if (popolno(n)) {
          cout << "Stevilo " << n << " je popolno!" << endl;
      } else {
          cout << "Stevilo " << n << " ni popolno!" << endl;
      }
      return 0;
  }

Overloading
~~~~~~~~~~~

Ker so v C++ funkcije odvisne od tipov, imamo lahko več funkcij z istim imenom
-- dokler se le razlikujejo po tipu ali številu parametrov.

Primer:

.. code-block:: cpp

  int sestej(vector<int> v) {
      int vsota = 0;
      for (const auto& x : v) {
          vsota += x;
      }
      return vsota;
  }

  string sestej(string s, string t) {
      return s + t;
  }

Funkcije brez težav živijo druga z drugo, saj je povsem jasno, katero želi
uporabnik poklicati -- ``sestej(vector<int>({1, 2, 3}))`` poklice prvo,
``sestej("abc", "def")`` pa drugo.

Scoping
~~~~~~~

V C++ funkcij vedno dobi kopijo vrednosti, ki jo podamo. Tako znotraj funkcij,
kot smo jih definirali sedaj, vrednosti ne moremo spreminjati. Primer:

.. code-block:: cpp

  void spremeni(double x) {
      x = 3.5;
  }

  int main() {
      int x = 4.5;
      cout << x << endl;
      spremeni(x);
      cout << x << endl;
  }

Zgornji program dvakrat izpiše ``4.5``, saj je ``x`` v funkciji drugi kot v
``main``. Res, to lahko še bolj poudarimo, če funkcij spremeni pokličemo kar
takole: ``spremeni(5.6)``. Kaj bi se sedaj zgodilo, če bi funkcija vrednost res
spremenila? Bi 5.6 postalo 3.5? Jasno je, da mora funkcija sprejeti *kopijo*
parametra.

Reference in konstantne reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Seveda je uporabno imeti tudi funkcije, ki spreminjajo parametre, na primer
funkcij swap, ki zamenja vrednosti dveh spremenljivk.

Tej funkciji namesto običajnih tipov podamo reference -- to pomeni da je
spremenljivka znotraj funkcije enaka kot zunaj. Referenco označimo tako, da na
konec tipa dodamo znak ``&``.

Reference je popolnoma veljaven tip tudi kar tako, brez funkcij. Poglejmo si
primer, ki najbolje opiše njeno delovanje.

.. code-block:: cpp

  int a = 9;
  int b = a;
  b = 7;
  cot << a << ' ' << b << endl;
  // 9 7

  int c = 9;
  int& d = a;
  d = 7;
  cout << c << ' ' << d << endl;
  // 7 7

V zgornjem primeru je ``d`` samo drugo ime za ``c``, če spremenimo ``d`` se
spremeni tudi ``c`` in obratno.

Podobno naredimo tudi v funkcijah.

.. code-block:: cpp

  void swap(int& a, int& b) {
      int t = a;
      a = b;
      b = t;
  }

Zgornjo funkcijo pokličemo kot ``swap(a, b)``, kjer sta ``a`` in ``b``
spremenljivki, funkcija pa bo njuni vrednosti zamenjala. Kaj pa se sedaj zgodi
če funkcijo pokličemo s konstantami? Ali ``swap(1, 3)`` zamenja vrednosti 1 in
3? Seveda ne, tak klic je neveljaven in dobimo compiler error:


::

  program.cpp:14:14: error: invalid initialization of non-const reference of type
                                              ‘int&’ from an rvalue of type ‘int’
      swap(1, 3);
               ^

Res, če nekaj podamo kot referenco, mora to biti tudi dejanska spremenljivka, ki
ji lahko spremenimo vrednost.

Kaj pa če objekta nimamo namena spreminjati, vendar njegove vrednosti ne bi
radi kopirali, saj je velik (npr. vector)?

Ena možnost je, da podamo referenco in objekta ne spreminjamo, vendar to ni
najbolj higienično, pa še omejitve ima, saj ne moramo funkcije klicati s
konstantami. Druga možnost je, da funkcija sprejme konstantno referenco --
torej dejansko isto spremenljivko kot jo podamo, a njene vrednosti nam ni
dovoljeno spreminjati. Konstantna referenca je pravzaprav neke vrste readonly
kopija naše spremenljivke. Za velike tipe je to privzet način sprejemanja
parametrov. Oglejmo si razliko na primeru funkcije ``append`` za vektorje, ki
bo en vektor dodala na konec drugega in funkcije join, ki združi dva vektorja.

.. code-block:: cpp

  void append(vector<int>& a, const vector<int>& b) {
      for (int x : b) {
          a.push_back(x);
      }
  }

  vector<int> join(const vector<int>& a, const vector<int>& b) {
      vector<int> result;
      append(result, a);
      append(result, b);
      return result;
  }

Veljavna (in sicer nepotrebna) uporaba funkcije ``join`` je tudi
``vector<int> a = join(vector<int({1, 2, 3, 4}), vector<int>({5, 6, 7, 8}));``.
Funkcijo smo klicali z dvema "temporary objektoma" in smo vzeli referenco, vendar
to ni težava, saj je ne moremo spreminjati.

Ena izmed težav referenc je, da ob klicu funkcije ``f(a)`` ne vemo, ali bo ta
funkcija  ``a`` spremenila ali ne -- pogledati moramo v definicijo.
