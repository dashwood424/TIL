n = int(input())
s = list(input())
ans = None
m = (n - 1) // 2 

for i in range(1<<m):
    ok = True
    for j in range(m - 1):
        if (i&(1<<j)) > 0 and (i&(1<<(j+1))) > 0:
            ok = False
    if not ok:
        continue

    a = s[:]

    for j in range(m):
        if (i&(1<<j)) > 0:
            k = 2 * j + 1
            a[k - 1]='(' + a[k - 1]
            a[k + 1]=a[k + 1] + ')'
            
    b=''.join(a)
    temp = eval(b)

    if ans is None or ans < temp:
        ans = temp
print(ans)