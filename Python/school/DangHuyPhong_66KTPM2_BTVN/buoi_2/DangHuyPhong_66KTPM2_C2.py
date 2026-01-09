import math as m


# Bài 1: Trung bình cộng
def average():
    total = 0
    for i in range(5):
        num = int(input(f"Nhập vào số thứ {i + 1}: "))
        total += num
    print(f"Trung bình cộng là: {total / 5:.2f}")


# Bài 2: Diện tích tam giác từ 3 cạnh
def area():
    a = int(input("Nhập vào cạnh A: "))
    b = int(input("Nhập vào cạnh B: "))
    c = int(input("Nhập vào cạnh C: "))

    # Kiểm tra tam giác có hợp lệ không
    if a + b > c and a + c > b and b + c > a:
        p = (a + b + c) / 2
        dien_tich = m.sqrt(p * (p - a) * (p - b) * (p - c))
        print(f"Diện tích của tam giác {a}, {b}, {c} là: {dien_tich:.2f}")
    else:
        print("Ba cạnh không tạo thành tam giác hợp lệ.")


# Bài 3: Diện tích tam giác từ tọa độ
def area2():
    print("Nhập tọa độ điểm A:")
    ax = int(input("ax = "))
    ay = int(input("ay = "))

    print("Nhập tọa độ điểm B:")
    bx = int(input("bx = "))
    by = int(input("by = "))

    print("Nhập tọa độ điểm C:")
    cx = int(input("cx = "))
    cy = int(input("cy = "))

    ab = (bx - ax, by - ay)
    ac = (cx - ax, cy - ay)

    dien_tich = abs(0.5 * (ab[0] * ac[1] - ab[1] * ac[0]))
    print(f"Diện tích tam giác tọa độ là: {dien_tich:.2f}")


# bai 4
def total():
    n = input("Nhap vao so n: ")
    rs = 0
    for i in n:
        rs += int(i)
    print(f"ket qua la: {rs}")


# bai 6
def compare():
    a = int(input("Nhập số a: "))
    b = int(input("Nhập số b: "))
    c = int(input("Nhập số c: "))

    max_val = max(a, b, c)
    print(f"Giá trị lớn nhất là: {max_val}")

    values = [a, b, c]
    if values.count(max_val) >= 2:
        # Tìm và in ra số còn lại
        for val in values:
            if val != max_val:
                print(f"Giá trị còn lại là: {val}")
                break


# bai 7
def nextday():
    d = int(input("Nhập ngày (d): "))
    m = int(input("Nhập tháng (m): "))
    y = int(input("Nhập năm (y): "))

    # Số ngày trong mỗi tháng (tháng 2 xử lý riêng)
    def is_leap(year):
        return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

    days_in_month = [
        31,
        29 if is_leap(y) else 28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31,
    ]

    if m < 1 or m > 12 or d < 1 or d > days_in_month[m - 1]:
        print("Ngày không hợp lệ.")
        return

    d += 1
    if d > days_in_month[m - 1]:
        d = 1
        m += 1
        if m > 12:
            m = 1
            y += 1

    print(f"Ngày tiếp theo là: {d}/{m}/{y}")


def main():
    print("\n--- Bai 1 ---")
    average()

    print("\n--- Bai 2 ---")
    area()

    print("\n--- Bai 3 ---")
    area2()

    print("\n--- Bai 4 ---")
    total()

    print("\n--- Bai 6 ---")
    compare()

    print("\n--- Bai 7 ---")
    nextday()


if __name__ == "__main__":
    main()
