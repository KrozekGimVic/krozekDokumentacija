# Programerski krožek na Gimnaziji Vič

V tem repozitoriju se nahaja dokumentacija za programerski krožek na Gimnaziji
Vič.

# Namestitev

Za namestitev potrebujete nameščen `python3` in za njega pakete `pip` in
`virtualenv`. Nato le zaženete:

    make install

kar ustvari virtualenv in namesti vse potrebne pakete (ti se nahajajo v
`requirements.txt`).

# Pisanje

Za dodajanje vsebin samo uredite primeren `.rst` file ali pa naredite novega in ga dodajte v kazalo.
Da iz `.rst` datotek dobite html (ali karkoli drugega), samo poženite:

    make html

# Git submoduli

Ta repozitorij vsebuje dodatni subrepozitorij. Da dobite vse potrebne datoteke,
morate namesto 'navadnega' `git clone` zagnati `git clone --recursive`. Če ste
to pozabili in ste repozitorij že prenesli, pojdite v njega in zaženite:

    git submodule update --init --recursive

Natan Žabkar, Jure Slak

# Prenova
by Klemen Bajec 7. 10. 2025

Ker je bilo vse staro in ni bilo kompatibilno z novm pythonom sem malo popravil:
V rerequirements.txt sem odstranil vse ==verzije, tako da namesti tazadnjo.
Popravil nekaj kode ker imajo novejši paketi drugačne funkcije.

---

## Navodila

Potegnete dol z  `git clone`.


Pred namestitvijo paketov vedno ustvarite čisto virtualno okolje (venv), da izolirate projektne odvisnosti.

Ustvari novo virtualno okolje z imenom 'venv'

	python -m venv venv

Aktivacija okolja (za Windows PowerShell)

	.\venv\Scripts\Activate.ps1
	
V rerequirements.txt sem odstranil vse ==verzije, tako da namesti tazadnjo.

	pip install --upgrade -r requirements.txt

Opravi popravke: Uredi in popravi datoteke, ki so problematične (npr. conf.py, .rst datoteke).
Počisti in zgradi: 

	sphinx-build -b html . docs

Mapa docs je zato, da lahko github streže stran iz veje in ne iz `/root`

Če je gradnja uspešna (build succeeded), se bo končna dokumentacija nahajala v mapi docs. Odprite docs/index.html in preverite rezultat.
