s = input("Nhap vao xau S: ")
D = {}
for ch in s:
    D[ch] = D.get(ch, 0) + 1

print(D)
