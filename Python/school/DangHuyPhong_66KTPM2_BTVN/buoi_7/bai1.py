D = {4: "four", 2: "two", 3: "three", 5: "five", 1: "one"}

sorted_key_list = sorted(D)  # new list

sorted_dict = {key: D[key] for key in sorted_key_list}

print(sorted_dict.values())
