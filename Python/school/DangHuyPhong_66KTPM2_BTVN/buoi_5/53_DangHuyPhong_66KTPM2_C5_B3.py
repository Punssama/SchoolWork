import math as m


def uoc_so(n):
    rs = 0
    n2 = int(m.sqrt(n))
    for i in range(1, n2 + 1):
        if n % i == 0:
            rs += i
        if n // i != i:
            rs += n // i
    return rs


n = int(input("Nhap so n: "))

print("Cac so la: ", end="")
for i in range(1, n):
    if uoc_so(i) > i:
        print(i, end=" ")
