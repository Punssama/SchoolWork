s = input("Nhap chuoi: ")
d = 0


def checkExclamation(s):
    if len(s) == 0:
        return 0
    else:
        for i in range(len(s) - 1, 0, -1):
            if s[i] != "!":
                return i


k = checkExclamation(s)
for i in range(k, len(s)):
    if s[i] == "!":
        d += 1
if d < 3:
    s += (3 - d) * "!"
print(
    f"Chuoi sau khi bo sung dau cham than: '{s}'",
)
# O(n^2)
