D = {}

n = int(input("Nhap so luong key: "))


for i in range(n):
    D[i] = input(f"Nhap vao value cua tu dien thu {i}: ")
top_3_values = sorted(D.values(), reverse=True)[:3]
print(top_3_values)
