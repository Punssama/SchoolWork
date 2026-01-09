D = {}
new_dict = {}

n = int(input("Nhap vao so luong key cua tu dien: "))
for i in range(n):
    D[i] = input(f"Nhap vao value cua tu dien thu {i}: ")


new_dict = set(D.values())

print(new_dict)
