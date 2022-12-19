import random
import string

max_pattern_len_str = input("Enter max pattern length (default: 1000) >> ").strip()
if not max_pattern_len_str:
    max_pattern_len = 1000
else:
    max_pattern_len = int(max_pattern_len_str)

num_patterns_str = input("Enter number of patterns (default: 1000) >> ").strip()
if not num_patterns_str:
    num_patterns = 1000
else:
    num_patterns = int(num_patterns_str)

pattern_list = []
for i in range(num_patterns):
    pattern_len = random.randint(1, max_pattern_len)
    pattern_list.append("".join(random.choice(string.ascii_letters) for i in range(pattern_len)))

with open("pattern.txt", "w", encoding="utf-8") as f:
    f.writelines(map(lambda x: x + "\n", pattern_list))
