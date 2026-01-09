s = input("Nhập vào chuỗi: ")
s = "".join([ch for ch in s if not ch.isdigit()])
print(s)
