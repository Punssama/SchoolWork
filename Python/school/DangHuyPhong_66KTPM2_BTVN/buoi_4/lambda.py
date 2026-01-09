# bool va def


def isPrime(n):
    ketqua = True
    for i in range(2, n):
        if n % i == 0:
            ketqua = False
            break
    return ketqua


n = int(input("Nhap so n: "))

if isPrime(n):
    print("N la so nguyen to")
else:
    print("N khong phai so nguyen to")
