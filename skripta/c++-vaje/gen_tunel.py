tip = ('car', 'motorbike', 'bus', 'truck')
weight = (0.60, 0.05, 0.03, 0.32)

d = 3.2
sl = 100
sll = 80

timestamp = 1543012004000

from random import expovariate, gauss, choice, choices, shuffle, random

mesta = ('LJ', 'KP', 'KK', 'KR', 'PO', 'MB', 'MS', 'SG', 'NM', 'GO', 'CE', 'P', 'SV', 'CD')
weight2 = [2] + [1]*10 + [0.05, 0.04, 0.02]
s = sum(weight2)
for i in range(len(weight2)):
    weight2[i] /= s

STR = 'ABCDEFGHLJKMNPRQSTUVXYZW0123456789'

def tablica():
    mesto = choices(mesta, weight2)
    zadaj = ''.join(choice(STR) for i in range(5))
    return mesto[0] + ' ' + zadaj[:2] + '-' + zadaj[2:]

T = 0
N = 1_000_000

cams1 = "CAM001 CAM002 CAM003 CAM007".split()
cams2 = "CAM043 CAM052 CAM016 CAM008 CAM010".split()

seen = set()
seenl = []
rows = []
for i in range(N):
    T += int(expovariate(1/2500))
    if i % 1223 == 0: continue

    if random() < 0.05 and seen:
        tab, vt = choice(seenl)
    else:
        vt = choices(tip, weight)[0]
        tab = tablica()
        seen.add((tab, vt))
        seenl.append((tab, vt))

    cf = choice([cams1, cams2])
    cs = cams2 if cf == cams1 else cams1

    DT = d/gauss(sl, 3) if vt in ['car', 'motorbike'] else d/gauss(sll, 3)
    DT *= 3600*1000


    data = [2*i, int(timestamp + T), vt, tab, choice(cf)]
    data2 = [2*i+1, int(timestamp + T+DT), vt, tab, choice(cs)]

    rows.append(",".join(map(str, data)))
    rows.append(",".join(map(str, data2)))

shuffle(rows)
print('\n'.join(rows))
