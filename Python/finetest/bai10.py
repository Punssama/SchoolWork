n = int(input("Nhap N: "))

strg = []
listA = []
listB = []
for i in range(0, n):
    k = input(f"Nhap gia tri thu {i + 1}: ")
    strg.append(k)

for i in strg:
    try:
        if "." in i:
            listA.append(float(i))
        else:
            listA.append(int(i))
    except ValueError:
        listB.append(i)

if len(listA) > 0:
    t = 0
    for i in listA:
        t += i
    print(f"TBC cua A = {t / len(listA)}")
print(f"B = {listB}")
