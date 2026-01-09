def snt(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


try:
    arr = []
    a = input("A=")
    b = input("B=")

    if not a.strip("-").isdigit() or not b.strip("-").isdigit():
        raise ValueError("A va B phai la so.")
    a = int(a)
    b = int(b)
    if a < 0 or b < 0:
        raise ValueError("A va B phai la so nguyen duong")
    else:
        for i in range(a + 1, b):
            if snt(i) == True:
                arr.append(i)
        tup = tuple(sorted(arr))
        print(tup)
except ValueError as ve:
    print(ve)
