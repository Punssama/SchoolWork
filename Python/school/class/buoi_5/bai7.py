import math 




def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True



tupgen = (i for i in range(1, 100001) if (isPrime(i)))
tup = tuple(tupgen)
print(tup)
