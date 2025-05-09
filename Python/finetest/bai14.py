n = int(input("N = "))

k = str(int(pow(2, n)))

rs = 0
for i in k:
    rs += int(i)
print(f"Tong = {rs}")
