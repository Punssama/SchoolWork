prices = {}
stock = {}
strg = {}
i = 1
while True:
    product = input(f"Nhap vao ten mat hang thu {i}: ")
    if product == "":
        break
    prices[product] = float(input(f"Nhap vao gia tien mat hang thu {i}: "))
    i += 1

for stock_item in prices.keys():
    stock[stock_item] = int(input(f"Nhap vao so luong hang ton cua {stock_item}: "))


for product, price in prices.items():
    strg[product] = round(price * stock[product])

sorted_dict = sorted(strg.values(), reverse=True)


for i in sorted_dict:
    for key, value in strg.items():
        if value == i:
            print(f"{key:<10}{value}")
