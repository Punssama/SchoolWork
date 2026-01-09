import re


def is_valid_email(email):
    pattern = r"^[a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    return re.match(pattern, email) is not None


email = input("Nhập email: ")
if is_valid_email(email):
    print("✅ Đây là email hợp lệ.")
else:
    print("❌ Đây không phải là email hợp lệ.")
