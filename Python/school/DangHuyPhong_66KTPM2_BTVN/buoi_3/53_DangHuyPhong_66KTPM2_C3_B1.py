def isPrime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


if __name__ == "__main__":
    n = int(input("Nhap vao so n: "))
    if isPrime(n):
        print("this number is prime number")
    else:
        print("this number ain't prime number")
