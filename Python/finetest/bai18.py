menu_storg = []
remain_storg = []


def insertProduct():
    s = ""
    s = input(f"{"Ten mat hang: ":<10}")
    return s


bang_gia = {"Ten mat hang: ": "none", "Gia ban hang: ": 0.0}
hang_ton = {"Ten mat hang: ": "none", "So luong ton kho: ": 0}
print("NHAP BANG GIA")
while True:
    productName = insertProduct()
    if productName == "":
        break
    bang_gia["Ten mat hang: "] = productName
    price = float(input(f"{'Gia ban hang: ':<10}"))
    bang_gia["Gia ban hang: "] = price
    menu_storg.append(bang_gia)

print("NHAP HANG TON")
while True:
    productName = insertProduct()
    if productName == "":
        break
    hang_ton["Ten mat hang: "] = productName
    quantity = int(input("So luong ton kho: "))
    hang_ton["So luong ton kho: "] = quantity
    remain_storg.append(hang_ton)


print("THONG KE HANG TON")
for price_item in menu_storg:
    for stock_item in remain_storg:
        if price_item["Ten mat hang: "] == stock_item["Ten mat hang: "]:
            price = float(price_item["Gia ban hang: "])
            stock = int(stock_item["So luong ton kho: "])
            total = price * stock
            print(f"{price_item["Ten mat hang: "]} {total:.2f}")
