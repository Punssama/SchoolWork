s = input("Nhap S: ")


def remove(xau):
    i = 0
    s1 = list(xau)
    while i < len(s1):
        if s1[i] == "!":
            s1.pop(i)
        else:
            i += 1
    xau = "".join(s1)
    return xau


print(f"Chuoi S sau khi loai bo dau cham than: {remove(s)}")
