import math as m

n = int(input("N = "))

rs = 0
inSqrt = 0
for i in range(1, n + 1):
    inSqrt += i
    rs += m.pow(inSqrt, 1 / i)

print(f"F({n}) = {rs:.7f}")
