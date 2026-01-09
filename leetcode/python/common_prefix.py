haystack = input("1: ")
needle = input("2: ")
count = 0
parent = 0
flag = False
try:
    while parent < len(haystack):
        arr = ""
        child = 0
        count = parent
        while child < len(needle):
            arr += haystack[count]
            count += 1
            child += 1
        if arr == needle:
            flag = True
            break
        parent += 1
    if flag:
        print(f"tim thay {needle} o vi tri thu {parent}")
    else:
        print(-1)
except IndexError:
    print(-1)
