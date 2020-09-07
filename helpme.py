white = 'KQRBNP'
black = 'kqrbnp'
bc = dict()
wc = dict()
for b in black:
    bc[b] = []
for w in white:
    wc[w] = []

for i in range(9):
    input()
    if i < 8:
        line = input()
        for j in range(8):
            c = line[2 + j * 4]
            if c in bc:
                bc[c].append((j, 7 - i))
            if c in wc:
                wc[c].append((j, 7 - i))
wl = []
bl = []
for w in wc:
    if len(wc[w]) == 0:
        continue
    wc[w].sort(key=lambda x: (x[1], x[0]))
    s = ','.join(map(lambda x: (w if w != 'P' else '') +
                     chr(ord('a') + x[0]) + str(x[1] + 1), wc[w]))
    wl.append(s)
for b in bc:
    if len(bc[b]) == 0:
        continue
    bc[b].sort(key=lambda x: (-x[1], x[0]))
    s = ','.join(map(lambda x: (chr(ord(b) - ord('a') + ord('A')) if b != 'p' else '') +
                     chr(ord('a') + x[0]) + str(x[1] + 1), bc[b]))
    bl.append(s)
print('White:', ','.join(wl))
print('Black:', ','.join(bl))
