t = int(input())
for i in range(t):
    n, z = input().split()
    n = int(n)
    z = int(z)
    ans_x = 1
    ans_y = 2
    ans_e = -1
    for j in range(2, z):
        want = pow(z, n) - pow(j, n)
        x = int(pow(want, 1 / n))
        if x >= j:
            continue
        error = abs(pow(x, n) + pow(j, n) - pow(z, n))
        error_p = abs(pow(x + 1, n) + pow(j, n) - pow(z, n))
        mn_e = min(error, error_p)
        if error_p < error:
            x += 1
        if ans_e == -1 or mn_e < ans_e:
            ans_e = mn_e
            ans_x = x
            ans_y = j
    print('{} {} {}'.format(ans_x, ans_y, ans_e))
