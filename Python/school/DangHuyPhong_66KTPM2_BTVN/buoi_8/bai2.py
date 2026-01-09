a = input("Nhap vao canh a: ")
b = input("Nhap vao canh b: ")
c = input("Nhap vao canh c: ")

try:
    a = float(a)
    b = float(b)
    c = float(c)
    if a <= 0 or b <= 0 or c <= 0:
        raise ValueError("Mot trong nhung canh a,b,c nho hon bang 0")
    if a + b <= c or a + c <= b or b + c <= a:
        raise ValueError("a,b,c khong the la canh cua tam giac")
    print("a,b,c hop le")

except ValueError as ve:
    print(ve)
