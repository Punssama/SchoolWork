s = input("Nhap n: ")


def checkExclamation(s):
    c = 0
    for i in reversed(s):
        if i == "!":
            c += 1
        else:
            break
    return c


print(f"chuoi n sau khi them dau cham than:{s+(3-checkExclamation(s))*'!'}")
