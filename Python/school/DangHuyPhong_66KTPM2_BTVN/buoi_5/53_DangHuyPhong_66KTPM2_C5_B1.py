s = input("Nhap vao chuoi cac tu: ")

l = s.split()

k = sorted(l)

print("Cac tu theo thu tu tu dien la:", end="")
print(*k)
