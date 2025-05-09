a = int(input("A = "))
b = int(input("B = "))
c = int(input("C = "))


if (a + b > c) and (a + c > b) and (b + c > a):
    print("Dung la tam giac")
else:
    print("Khong phai tam giac")
