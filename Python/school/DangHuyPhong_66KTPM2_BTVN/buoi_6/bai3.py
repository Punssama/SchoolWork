nums = input("Nhap vao day so: ")
l = list(map(int, nums.split()))

maxNum = max(l)
minNum = min(l)
print("Tap so vua nhap la:", *l)
print(f"So phan tu cua tap la: {len(l)}")
print(f"Phan tu lon nhat la: {maxNum}")
print(f"Phan tu nho nhat la: {minNum}")
