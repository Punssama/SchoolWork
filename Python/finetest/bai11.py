def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a


n = int(input("N = "))

if fibonacci(n) % 2 != 0:
    print("N khong phai la so fibonacci chan")
else:
    print("N la so fibonacci chan")
