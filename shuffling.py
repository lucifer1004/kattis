n, s = input().split()
n = int(n)
a = [i for i in range(n)]
b = [i for i in range(n)]


def shuffle(arr, s):
    half = len(arr) // 2
    if s == 'out':
        if (len(arr) % 2 == 1):
            half += 1
        res = [arr[i // 2] if i % 2 == 0 else arr[half + i // 2]
               for i in range(len(arr))]
    else:
        res = [arr[half + i // 2] if i % 2 == 0 else arr[i // 2]
               for i in range(len(arr))]
    return res


b = shuffle(b, s)
turn = 1
while b != a:
    b = shuffle(b, s)
    turn += 1
print(turn)
