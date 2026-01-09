def simNum(arr):
    prev = 0
    c = 0
    for i in range(1, len(arr)):
        prev = arr[i - 1]
        if arr[i] == prev:
            c += 1
            if c == 3:
                return True
        else:
            c = 0


def simEvenNum(arr):
    prev = 0
    c = 0
    for i in range(1, len(arr)):
        prev = arr[i - 1]
        if arr[i] % 2 == 0 and prev % 2 == 0:
            c += 1
            if c == 4:
                return True
        else:
            c = 0


nums_arr = []
i = 1
while True:
    try:
        n = input(f"Nhap vao so thu {i}: ")
        if n == "0":
            break
        if not n.lstrip("-").isdigit():
            raise ValueError("Loi nhap so!!!")

        n = int(n)

        if n < 0:
            raise ValueError("Loi so am!!!")

        nums_arr.append(n)

        if simNum(nums_arr):
            i = 0
            nums_arr = []
            raise RuntimeError("Loi nhap lap")

        if simEvenNum(nums_arr):
            i = 0
            nums_arr = []
            raise RuntimeError("Loi nhap chan")
        i += 1

    except ValueError as ve:
        print(ve)
    except RuntimeError as re:
        print(re)
print(nums_arr)
