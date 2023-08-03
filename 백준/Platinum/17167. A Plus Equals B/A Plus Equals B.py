import math

V = []

sta = ["A+=A", "A+=B", "B+=A", "B+=B"]

A = 0
B = 0

def solve(A, B):

    while(A != B):
        if (A % 2 == 0 and B % 2 == 0):
            if ((A & (A - 1)) == 0 and (B & (B - 1)) == 0):
                if (A < B):
                    V.append([(int(math.log2(B / A))), 0])
                    A = B
                else:
                    V.append([(int(math.log2(A / B))), 3])
                    B = A
                continue

            T1 = A & (-A)
            T2 = B & (-B)
            c1 = 0 
            c2 = 0

            if (T1 > T2):
                B *= int(T1 / T2)
                V.append([int(math.log2(int(T1 / T2))), 3])
            
            elif (T1 < T2):
                A *= int(T2 / T1)
                V.append([int(math.log2(int(T2 / T1))), 0])

            c1 = int(A / max(T1, T2))
            c2 = int(B / max(T1, T2))

            if (c1 > c2):
                A += B
                V.append([1, 1])

            else:
                B += A
                V.append([1, 2])

        elif (A % 2 != 0 and B % 2 == 0):
            V.append([1, 0])
            A *= 2

        elif (A % 2 == 0 and B % 2 != 0):
            V.append([1, 3])
            B *= 2

        else:
            V.append([1, 0])
            V.append([1, 3])
            A *= 2
            B *= 2

A, B = map(int, input().split())

total = 0

solve(A, B)

for x, y in V:
    total += x

print(total)

for x, y in V:
    for j in range(x):
        print(sta[y])
