from random import randint


def analiziraj_besede():
    imenik = dict()
    with open("besede.txt", encoding='utf-8') as f:
        for beseda in f:
            beseda = beseda.strip().lower() + " "
            prejsnja = " "
            for crka in beseda:
                if prejsnja not in imenik:
                    imenik[prejsnja] = dict()
                if crka not in imenik[prejsnja]:
                    imenik[prejsnja][crka] = 0
                imenik[prejsnja][crka] += 1
                prejsnja = prejsnja[1:] + crka

    return imenik


def izberi_naslednjo_crko(pojavitve):
    nmax = sum(pojavitve.values())
    n = randint(1, nmax)
    for kljuc, vrednost in pojavitve.items():
        n -= vrednost
        if n <= 0:
            return kljuc

analiza = analiziraj_besede()
niz = " "
for i in range(500):
    razdelitev = analiza[niz[-1]]
    niz += izberi_naslednjo_crko(razdelitev)
print(" ".join(set(niz.split()[:-1])))
