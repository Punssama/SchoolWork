s = input("Nhap cac tu: ")

l = list(s.split())
word = ""

max = len(l[0])
for ch in l:
    if len(ch) >= max:
        max = len(ch)
        word = ch
if word != "":
    for lw in l:
        if len(lw) == max:
            print(lw)
