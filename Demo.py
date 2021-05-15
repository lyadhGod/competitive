inp = list(str(input()).strip().split())

t = int(inp[0]) 
b = int(inp[1])

for _ in range(t):
    arr = " " + str(input()).strip()
    
    mid = b // 2 + 1

    k = -1
    for i in range(1, mid + 1):
        if arr[i] != arr[b - i + 1]:
            k = i
            break
    p = -1
    for j in range(1, mid + 1):
        if arr[j] == arr[b - j + 1]:
            p = j
            break
    if p != -1 and k != -1:
        state = "rev_com"
    else:
        state = "only_com"

    if p != -1: 
        pval = arr[p]
    if k != -1:
        kval = arr[k]

    rev = False
    com = False
    for i in range(1, 150 + 1):
        if i % 10 == 1:
            if state == "only_com":
                if p != -1:
                    print(p, flush = True)
                    inp = str(input())

                    if inp != pval:
                        com = not com

                    pval = inp
                else:
                    print(k, flush = True)
                    inp = str(input())

                    if inp != kval:
                        com = not com

                    kval = inp
            else:
                print(p, flush = True)
                pinp = str(input())

                i += 1
                kout = print(k, flush = True)
                kinp = str(input())

                if pinp != pval:
                    com = not com
                    if kinp == kval:
                        rev = not rev
                elif kinp != kval:
                    rev = not rev

    arr = arr.strip()
    if rev == True:
        ans = ""
        for g in arr:
            ans = g + ans
        arr = ans
    if com == True:
        ans = ""
        for g in arr:
            if g == "0":
                ans += "1"
            else:
                ans += "0"
    if com == False and rev == False:
        ans = arr

    print(ans, flush = True)

    if str(input()).strip() == "N":
        break
