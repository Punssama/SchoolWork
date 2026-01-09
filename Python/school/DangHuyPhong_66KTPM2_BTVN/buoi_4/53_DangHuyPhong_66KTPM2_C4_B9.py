s = input("nhap s: ")

flag = True
for i in range(len(s)):
    if s[i] != s[len(s) - i - 1]:
        flag = False
        break
if flag:
    print("S la chuoi doi xung")
