line = input().split(' ')
n = int(line[0])
target = int(line[1])
lookup = {}
bids = []
for i in range(n):
    line = input().split(' ')
    name = line[0]
    bid = int(line[1])
    lookup[bid] = name
    bids.append(bid)

bids.sort()
i = len(bids) - 1
curr = target
chosen = []
while i >= 0:
    if bids[i] <= curr:
        curr -= bids[i]
        chosen.append(bids[i])
        if curr == 0:
            break
    i -= 1

if curr != 0:
    print(0)
else:
    print(len(chosen))
    for bid in chosen:
        print(lookup[bid])
