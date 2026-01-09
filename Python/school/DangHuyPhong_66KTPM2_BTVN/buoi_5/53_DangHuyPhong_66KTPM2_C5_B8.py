def generate_valid_strings(n):
    memo = {}

    def gen(length):
        if length in memo:
            return memo[length]
        result = set()
        if length == 2:
            result.add("()")
        else:
            for i in range(2, length, 2):
                for a in gen(i):
                    wrapped = f"({a})"
                    if len(wrapped) < n:
                        result.add(wrapped)
                    for b in gen(length - i):
                        combined = a + b
                        if len(combined) < n:
                            result.add(combined)
        memo[length] = result
        return result

    final_result = set()
    for l in range(2, n, 2):  # chỉ độ dài chẵn
        final_result.update(gen(l))

    return sorted(final_result)


N = int(input("N: "))
results = generate_valid_strings(N)

print(f"valid strings with length < {N} là:")
for s in results:
    print(s)
