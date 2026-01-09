i = 1
strg = []
while True:
    n = int(input(f"Nhap vao so thu {i}: "))
    if n < 0:
        break
    i += 1
    strg.append(n)
print(*strg)
