import random

# bo gom 5 so trong tap hop so tu 1->45, nguoi choi thang khi trung 5/6 so khong ke thu tu

numberOfAttendant = int(input("Nhap so nguoi: "))

attendantsTickets = []


for i in range(0, numberOfAttendant):
    while True:
        ticket = input(
            f"Nhap vao bo 6 so cua nguoi thu {i+1} cach nhau boi khoang trang: "
        )
        numbers = ticket.split()
        if (
            len(numbers) == 6
            and len(set(numbers)) == 6
            and all(n.isdigit() and 1 <= int(n) <= 45 for n in numbers)
        ):
            break
        else:
            print("bo so co 6 so khac nhau trong khoang [1,45]")
    attendantsTickets.append(ticket)
while True:
    prize = input("Nhap vao bo 6 so cua giai thuong cach nhau boi khoang trang: ")
    inPrize = prize.split()
    if (
        len(inPrize) == 6
        and len(set(inPrize)) == 6
        and all(p.isdigit() and 1 <= int(p) <= 45 for p in inPrize)
    ):
        break
    else:
        print("giai thuong chi co 6 so khac nhau!")

print("Bo so cua cac nguoi chien thang la: ")
for ticket in attendantsTickets:
    c = 0
    checkTicket = set(ticket.split())
    for j in checkTicket:
        if c == 5:
            print(ticket)
            c = 0
        if int(j) in inPrize:
            c += 1
