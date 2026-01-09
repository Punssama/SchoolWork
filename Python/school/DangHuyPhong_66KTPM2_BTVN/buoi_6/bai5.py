from math import sqrt


n = int(input("N: "))


def uocsoduong(n):
    rs = []
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            rs.append(i)
            if n // i != i:
                rs.append(n // i)
    return rs


print(f"Tap hop cac so duong la uoc so cua {n} la:", *uocsoduong(n))
