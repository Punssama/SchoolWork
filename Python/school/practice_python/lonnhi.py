import math as m


# cau 1
def findMaxSubArray(l):
    strg = []
    current_sum = max_sum = l[0]
    for i in l:
        current_sum = max(current_sum + i, i)
        max_sum = max(max_sum, current_sum)
    return max_sum


# cau 2
def findX(x, arr):
    count = 0
    for i in arr:
        if i == x:
            count += 1
    return count


# cau 3
def isPrime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


def findPosOfPrime(l):
    arr = []
    for i in range(len(l)):
        if isPrime(l[i]):
            arr.append(i)
    return arr


# cau 4
def insertLastAndFront(l, m):
    l.insert(0, m)
    l.append(m)
    return l


# cau 5
def findSecondMaxNum(arr):
    max_sum = current_sum = arr[0]
    start = end = temp_start = 0
    for i in range(1, len(arr)):
        if current_sum + arr[i] < arr[i]:
            current_sum = arr[i]
            temp_start = i
        else:
            current_sum += arr[i]

        if current_sum > max_sum:
            max_sum = current_sum
            start = temp_start
            end = i

    return max_sum, arr[start : end + 1]


# cau 6
def movePositiveNumToHead(l):
    positives = [x for x in l if x > 0]
    non_positives = [x for x in l if x < 0]
    return positives + non_positives


while True:
    a = input("Nhap vao n so: ")
    if len(list(map(int, a.split()))) <= 1:
        continue
    else:
        l = list(map(int, a.split()))
        break

# print("So lon nhi trong day la:", findSecondMaxNum(l))
print(f"Vi tri cua cac so nguyen to la:", *findPosOfPrime(l))
# print(f"day sau khi them dau va cuoi la:", *insertLastAndFront(l, m))
# print(f"day sau khi sap xep tang dan la:", *sorted(l))
print(*movePositiveNumToHead(l))
