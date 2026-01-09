strg_dict = {}

s = input("nhap vao cac tu: ")


for i in s.lower():
    if i.isalpha():
        strg_dict[i] = strg_dict.get(i, 0) + 1

print(f"{'Chu cai':<10} {'So lan xuat hien':<20}")
for key, value in strg_dict.items():
    print(f"{key:<10} {value:<20}")
