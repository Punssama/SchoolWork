from math import sqrt


def perfectNum(n):
    flag = 0
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            flag += i
            if i != n // i and n != n // i:
                flag += n // i
    return n == flag


def isSquare(n):
    Sqrt = int(sqrt(n))
    return n == Sqrt**2


arr = []
squared_num = []
perfectNum_list = []
i = 0
while True:
    n = int(input("Nhap vao so phan tu: "))
    if 0 < n and n < 100:
        break

for i in range(n):
    num = int(input(f"Nhap vao so thu {i+1}: "))
    arr.append(num)
    i += 1

for i in arr:
    if perfectNum(i):
        perfectNum_list.append(i)
    if isSquare(i):
        squared_num.append(i)


def lis(arr):
    n = len(arr)
    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)


print("Cac so hoan hao la:", *perfectNum_list)
print(f"Co {len(perfectNum_list)} so hoan hao ")
print(f"{max(squared_num)} la so chinh phuong lon nhat trong day")
print(f"{min(squared_num)} la so chinh phuong nho nhat trong day")
print("Day con tang dai nhat la:", lis(arr))
