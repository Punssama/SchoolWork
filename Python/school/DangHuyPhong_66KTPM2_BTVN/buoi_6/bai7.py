n = input("Nhap day so nguyen: ")
try:
    l = list(map(int, n.split(";")))
    print(f"day co {len(set(l))} so khac nhau")
except ValueError:
    print("Du lieu dau vao khong hop le")
