n = int(input("So nguoi ngoi quanh ban: "))

table = []

for i in range(1, n + 1):
    table.append(i)

s = len(table)

index = 0
while len(table) > 1:
    # print(table)
    # print(f"{index+2} % {len(table)}")
    index = (index + 2) % len(table)
    table.pop(index)

print("Nguoi o lai cuoi cung la nguoi thu", *table)
