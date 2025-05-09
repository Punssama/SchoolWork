n = int(input("N = "))

rs = 0
mau = 0
for i in range(1, n + 1):
    rs += n / (mau + i * i)
    mau += i * i

print(f"F({n}) = {rs:.7f}")
