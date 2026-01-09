names = []

while True:
    name = input("Nhap vao ho va ten: ")
    if name == "":
        break
    else:
        names.append(name)
for i in names:
    print(i)
print(f"{"Ho":<10} {"Ten"}")
for name in names:
    name = name.split()
    surname = name[0]
    forename = name[len(name) - 1]
    print(f"{surname:<10} {forename}")
