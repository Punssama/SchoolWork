n = int(input("N = "))

k = 0
result = 0
for i in range(1, n + 1):
    result += i
    k += pow(result, 0.5)
print(f"F({n}) = {k:.7f}")

