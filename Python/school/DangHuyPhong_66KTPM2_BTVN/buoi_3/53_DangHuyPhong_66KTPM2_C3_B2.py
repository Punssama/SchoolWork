from bai1 import isPrime

a = int(input("Nhap vao so A: "))
b = int(input("Nhap vao so B: "))


print(*[i for i in range(a, b) if isPrime(i)])
