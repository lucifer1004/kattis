n = int(input())
k = int(input())
d = dict()
win = 0
for _ in range(k):
    a, b, pa, pb = input().split()
    a = int(a)
    b = int(b)
    if pa == pb:
        if pa in d:
            d.pop(pa)
        n -= 2
    else:
        if pa not in d:
            d[pa] = set()
        if pb not in d:
            d[pb] = set()
        d[pa].add(a)
        d[pb].add(b)
l = list(d)
for key in l:
    if len(d[key]) == 2:
        win += 1
        n -= 2
        d.pop(key)
if len(d) == n // 2:
    win += n // 2
if len(d) == 0 and n == 2:
    win += 1
print(win)
