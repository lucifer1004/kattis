s = input()
n = len(s) // 3
d = dict()
for i in range(n):
    c = s[3 * i]
    if c not in d:
        d[c] = set()
    num = s[3 * i + 1: 3 * i + 3]
    if num in d[c]:
        print('GRESKA')
        exit(0)
    d[c].add(num)
ans = []
for c in 'PKHT':
    if c in d:
        ans.append(13 - len(d[c]))
    else:
        ans.append(13)
print(' '.join(map(str, ans)))
