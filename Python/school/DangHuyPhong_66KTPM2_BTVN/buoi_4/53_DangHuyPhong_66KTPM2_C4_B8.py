s = input("Nhap chuoi s: ")

for ch in s:
    if ch.isdigit():
        s = s.replace(ch, "?")

print(s)
