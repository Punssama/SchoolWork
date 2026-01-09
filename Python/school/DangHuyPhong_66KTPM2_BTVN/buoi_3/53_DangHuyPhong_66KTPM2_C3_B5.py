import math


def ucln(a, b):
    return math.gcd(a, b)


def bcnn(a, b):
    return abs(a * b) // ucln(a, b)


i = 1
strg = []
while True:
    n = int(input(f"Nhap vao so thu {i}: "))
    if n < 0 or n == 0:
        break
    i += 1
    strg.append(n)

ucln_all = strg[0]
bcnn_all = strg[0]

for num in strg[1:]:
    ucln_all = ucln(ucln_all, num)
    bcnn_all = bcnn(bcnn_all, num)

# In kết quả
print("UCLN: ", ucln_all)
print("BCNN: ", bcnn_all)
