a = int(input("A = "))
b = int(input("B = "))
c = int(input("C = "))

arr = [a, b, c]

arr = sorted(set(arr))

# ham set: loai bo cac phan tu giong nhau trong danh sach
# toan tu *: toan tu giai nen, in cac phan tu trong danh sach ma khong in dau [] va dau ,
print("Xep tang dan:", *arr)
