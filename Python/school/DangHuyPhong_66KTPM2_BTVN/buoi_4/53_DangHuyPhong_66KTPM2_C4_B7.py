s = input("Nhap chuoi s: ")
n = int(input("Nhap so nguyen N: "))

stack = []
# 1234
for i in s:
    while n > 0 and stack and stack[-1] < i:
        stack.pop()
        n -= 1
    stack.append(i)


rs = "".join(stack)

print(rs)
