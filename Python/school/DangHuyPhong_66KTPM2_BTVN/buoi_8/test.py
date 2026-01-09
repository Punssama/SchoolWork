def simNum(arr):
    prev = 0
    c = 0
    for i in range(1, len(arr)):
        prev = arr[i - 1]
        print(f"{arr[i]} == {prev}")
        if arr[i] == prev:
            c += 1
            if c == 3:
                return True
        else:
            c = 0


if simNum([1, 1, 1, 1, 2]):
    print("Ton tai 4 so lien tiep giong nhau")
else:
    print("Hop le")
