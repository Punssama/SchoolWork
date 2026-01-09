def pascal(n):
    for i in range(n):
        row = [1]
        for j in range(1, i + 1):
            val = row[j - 1] * (i - j + 1) // j
            row.append(val)
        print(" " * (n - i), *row)


n = int(input("Nhập số dòng của tam giác Pascal: "))
pascal(n)
