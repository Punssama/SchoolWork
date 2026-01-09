import math

if __name__ == "__main__":
    a = int(input("A: "))
    b = int(input("B: "))

    ucln = math.gcd(a, b)

    bcnn = abs(a * b) // ucln

    print("UCLN:", ucln)
    print("BCNN:", bcnn)
