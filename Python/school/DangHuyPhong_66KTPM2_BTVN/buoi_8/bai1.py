try:
    a = int(input("Nhap vao so nguyen a: "))
    b = int(input("Nhap vao so nguyen b: "))
    try:
        rs = a / b
        print(f"Ket qua la: {a/b}")
    except ZeroDivisionError as ze:
        print(ze)

except ValueError:
    print("So a hoac b khong phai so nguyen")
