T = int(str(input()).strip().split()[0])

for _ in range(T):
    inp = str(input()).strip().split()
    A = int(inp[0])
    B = int(inp[1])

    N = input()

    left = A + 1
    right = B
    mid = (left + right) // 2

    while True :
        print(mid, flush = True)
        ans = str(input()).strip().split()[0]

        if ans == "CORRECT": break
        elif ans == "TOO_BIG": right = mid - 1
        elif ans == "TOO_SMALL": left = mid + 1

        mid = (left + right) // 2
