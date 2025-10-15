class TicTacToe:
    def __init__(self):
        self.plosca = [[0]*3 for _ in range(3)]
        self.poteze = []
        self.igralec = 1

    def vse_poteze(self):
        # vrni seznam vseh možnih potez
        vse = []
        for x in range(3):
            for y in range(3):
                if self.plosca[y][x] == 0:
                    vse.append((x, y))
        return vse

    def poteza(self, x, y):
        # Trenutni igralec igra na mesto x, y
        if self.plosca[y][x] == 0:
            self.plosca[y][x] = self.igralec
            self.igralec *= -1
            self.poteze.append([x, y])
        else:
            print("Neveljavna poteza!")

    def nazaj(self):
        # Prekliči zadnjo potezo
        if self.poteze:
            zadnja = self.poteze.pop()
            self.plosca[zadnja[1]][zadnja[0]] = 0
            self.igralec *= -1
        else:
            print("Ni poteze, ki bi jo lahko preklical")

    def zmaga(self):
        # Vrni zmagovalca:
        #   1  - prvi igralec,
        #  -1 - drugi igralec
        #   0  - ni zmagovalca
        pl = self.plosca
        if pl[0][0] == pl[1][1] == pl[2][2] != 0:
            return pl[1][1]
        if pl[0][2] == pl[1][1] == pl[2][0] != 0:
            return pl[1][1]
        for i in range(3):
            if pl[i][0] == pl[i][1] == pl[i][2] != 0:
                return pl[i][0]
            if pl[0][i] == pl[1][i] == pl[2][i] != 0:
                return pl[0][i]
        return 0

    def print(self):
        # nariši trenutno polje igre
        for y in range(3):
            if y != 0:
                print("-+-+-")
            for x in range(3):
                if x != 0:
                    print("|", end="")
                print("o x"[self.plosca[y][x] + 1], end="")
            print()


ttt = TicTacToe()

for i in range(9):
    ttt.print()
    x, y = map(int, input().split())
    if x < 0:
        ttt.nazaj()
    else:
        ttt.poteza(x, y)
        if ttt.zmaga():
            print("ZMAGA")
            ttt.print()
            break
