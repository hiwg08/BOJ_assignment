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
                    for i in range(int(math.log2(B / A))):
                        V.append(0)
                    A = B
                else:
                    for i in range(int(math.log2(A / B))):
                        V.append(3)
                    B = A
                continue

            T1 = A
            T2 = B
            c1 = 0 
            c2 = 0

            while(T1 % 2 == 0):
                T1 >>= 1
                c1 += 1

            while(T2 % 2 == 0):
                T2 >>= 1
                c2 += 1

            if (c1 != c2):
                if (c1 < c2):
                    A <<= (c2 - c1)
                    for j in range(c2 - c1):
                        V.append(0)
                
                else:
                    B <<= (c1 - c2)
                    for j in range(c1 - c2):
                        V.append(3)

            if (T1 > T2):
                A += B
                V.append(1)

            else:
                B += A
                V.append(2)

        elif (A % 2 != 0 and B % 2 == 0):
            V.append(0)
            A *= 2

        elif (A % 2 == 0 and B % 2 != 0):
            V.append(3)
            B *= 2

        else:
            V.append(0)
            V.append(3)
            A *= 2
            B *= 2

A, B = map(int, input().split())

solve(A, B)

print(int(len(V)))

for it in V:
    print(sta[it])
