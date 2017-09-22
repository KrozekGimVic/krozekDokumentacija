# Ustvarimo opis razreda, ki ga bomo  uporabljali za zapis pogovora
class Chat:
    # Metoda, ki jo potrebuje vsak razred
    # ime_d: ime datoteke v katero zapisujemo
    # passsword: za koliko znakov naj zamaknemo znake, ko pisemo in beremo
    def __init__(self, ime_d, password=0):
        # Vse kar naredimo je, da si shranimo podatke za prihodnjo rabo
        self.ime_d = ime_d
        self.password = password

    # Metoda, ki napise dano sporocilo v datoteko
    def napisi(self, sporocilo):
        # Na koncu sporocila dodajmo novo vrstico
        sporocilo = sporocilo + "\n"
        # Zakodiraj sporocilo znak po znak
        zakodirano_sporocilo = ""
        for znak in sporocilo:
            # Ugotovi stevilsko vrednost znaka
            st = ord(znak)
            # Zamakni znak in ga pretvori nazaj v znak
            nov = chr(st + self.password)
            zakodirano_sporocilo = zakodirano_sporocilo + nov
        # Zapisi sporocilo v datoteko
        dat = open(self.ime_d, "a")
        dat.write(zakodirano_sporocilo)
        dat.close()

    # Metoda, ki prebere vsebino datoteke (in jo odkodira)
    def preberi(self):
        # Preberi datoteko
        dat = open(self.ime_d, "r")
        vsebina = dat.read()
        dat.close()

        # Odkodiraj vsebino datoteke
        nova_vs = ""
        for znak in vsebina:
            st = ord(znak)
            nov = chr(st - self.password)
            nova_vs = nova_vs + nov

        # Vrni odkodirano vsebino
        return nova_vs


# Odpremo in zapremo datoteko, da jo ustvarimo,ce se ne obstaja
d = open("krozek.txt", "a")
d.close()

# Preberi stevilo od uporabnika, ki jo bomo uporabili za zamik znakov
password = int(input("Napisi stevilko za password: "))

# Ustvari chat
moj_chat = Chat("krozek.txt", password)

# Izpisi zgodovino chata
print(moj_chat.preberi())

# Povprasaj uporabnika po imenu in ga zapisi v datoteko
ime = input("Kako ti je ime? ")
moj_chat.napisi("== {} ==".format(ime))

# Nenehno sprasuj za nova sporocila
while True:
    # Zahtevaj novo sporocilo od uporabnika
    novo_sporocilo = input("Napisi sporocilo ('stop' za konec): ")
    # Zapisi sporocilo v datoteko
    moj_chat.napisi(novo_sporocilo)
    # Ce je bilo sporocilo 'stop' prekini izvajanje programa
    if novo_sporocilo.lower() == "stop":
        break
