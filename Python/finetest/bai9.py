s = input("Nhap S: ")
d = 0


def checkExclamation(s):
    k = 0
    if len(s) == 0:
        return k
    else:
        for i in range(len(s) - 1, 0, -1):
            if s[i] != "!":
                k = i
                break
    return k


k = checkExclamation(s)
for i in range(k, len(s)):
    if s[i] == "!":
        d += 1
if d < 3:
    s += (3 - d) * "!"
print("Chuoi S sau khi xu ly:", s)
