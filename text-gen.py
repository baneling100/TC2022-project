import random
import string

repeats_str = input("Enter number of repetitions for input generation (default: 5000) >> ").strip()
if not repeats_str:
    repeats = 5000
else:
    repeats = int(repeats_str)

pattern_list: list[str] = []
with open("pattern.txt", "r", encoding="utf-8") as f:
    pattern_list = list(map(lambda s: s.strip(), f.readlines()))

str_build_list = []
for i in range(repeats):
    pattern_use_prob = random.random()
    if (pattern_use_prob < 0.7):
        str_build_list.append("".join(random.choice(string.ascii_letters) for i in range(50)))
    else:
        pattern = random.choice(pattern_list)
        prob = random.random()
        if (prob < 0.6):
            new_len = int(len(pattern) * random.random())
            str_build_list.append(pattern[0:new_len])
        else:
            str_build_list.append(pattern)

with open("random-new.txt", "w", encoding="utf-8") as f:
    f.write("".join(str_build_list) + "\n")
