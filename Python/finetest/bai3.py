n = int(input("Nhap N: "))

floatList = []
intList = []
stringList = []
strg = []


for i in range(0, n):
    k = input(f"Nhap gia tri thu {i + 1}: ")
    strg.append(k)

for i in range(0, len(strg)):
    try:
        if "." in strg[i]:
            floatList.append(float(strg[i]))
        else:
            intList.append(int(strg[i]))
    except ValueError:
        stringList.append(strg[i])


intList.sort()
floatList.sort()
stringList.sort()
print(f"A = {intList}\nB = {floatList}\nC = {stringList}")
