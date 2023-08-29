dp = {}

def dev_con(params, pows):
    if (pows == 0):
        return 1
    
    if ((pows & 1) == 1):
        return params * dev_con(params, pows - 1)
    
    T1 = dev_con(params, pows >> 1)

    return T1 * T1

def mina(params, k, flag):
    lo = 1
    hi = 1000000000000000000

    while (lo + 1 < hi):
        mid = (lo + hi) >> 1

        chk = dev_con(mid, k)

        if (chk <= params): lo = mid
        else: hi = mid

    if (flag): return lo
    return hi


def solve(Idx):

    if (Idx == 1):
        return 0

    flag = Idx in dp

    if (flag):
        return dp[Idx]
    
    dp[Idx] = Idx - 1
    
    for i in range(1, 62):
        T1 = mina(Idx, i, True)
        d1 = dev_con(T1, i)
        T2 = mina(Idx, i, False)
        d2 = dev_con(T2, i)

        if (T1 >= Idx or T2 >= Idx):
            continue

        dp[Idx] = min(dp[Idx], solve(T1) + (Idx - d1) + 1, solve(T2) + (d2 - Idx) + 1)

    return dp[Idx]

N = int(input())

print(solve(N))