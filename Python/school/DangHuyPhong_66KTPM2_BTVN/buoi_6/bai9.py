total_staff = []
hr_room = []
administrative_room = []
media_room = []


def handlingStaff(idList, room):
    number_of_staff = list(map(int, idList.split(",")))
    for staff in number_of_staff:
        room.append(staff)
    return room


hr = input("Id nhan vien cua phong nhan su: ")
hr_room = handlingStaff(hr, hr_room)

administrative = input("Id nhan vien phong hanh chinh: ")
administrative_room = handlingStaff(administrative, administrative_room)

media = input("Id nhan vien phong truyen thong: ")
media_room = handlingStaff(media, media_room)

total_staff = list(set(media_room + hr_room + administrative_room))

print(f"\nBa phong ban nay su dung {len(total_staff)} nhan vien")

set1 = set(hr_room) & set(media_room)
set2 = set(hr_room) & set(administrative_room)
set3 = set(administrative_room) & set(media_room)

multi_room_staff = list(set(hr_room) & set(media_room) & set(administrative_room))
print(
    "Nhan vien lam viec o ca 3 phong la:",
    *multi_room_staff if len(multi_room_staff) > 0 else "0",
)

one_room_staff = list(set(total_staff) - set(multi_room_staff) - set1 - set2 - set3)
print(
    "Nhan vien lam viec o 1 phong la:",
    *one_room_staff if len(one_room_staff) > 0 else "0",
)

# a&b a&c b&c

# Đếm số lượng nhân viên trùng của các cặp phòng

# tìm xem cặp phòng nào trùng nhiều nhất
Max = max(set1, set2, set3)

# dùng từ điển lưu lại các cặp phòng và số lượng nhân viên dùng chung
numOset1 = len(list(set1))
numOset2 = len(list(set2))
numOset3 = len(list(set3))
strg = {
    "Nhan su & Truyen thong": set1,
    "Nhan su & Hanh chinh": set2,
    "Truyen thong & Hanh chinh": set3,
}

print("\nCap phong dung chung nhieu nhan vien nhat la:")

# loop qua từ điển, so sánh value(số lượng nvien dùng chung với max) nếu bằng max thì in ra key(Cặp phòng)
for key, value in strg.items():
    if value == Max:
        print(key)

print("\nMa nhan vien dau tien cua phong: ")
print(f"Nhan su: {min(hr_room)}")
print(f"Hanh chinh: {min(administrative_room)}")
print(f"Truyen thong: {min(media_room)}")

# dung roi day nhung ma hoi ruom ra, luoi nghi qua :<<
# chuan rui day
# done
# nhin no cu the nao :<
# de nho chat gpt optimize
# sai roi :<
# dung roi nhung ma van sieu ruom ra
# di ngu thoi off live nhe anh em :>>, xia xia ca nha :>>
