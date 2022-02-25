import random

a = []
for _ in range(50):
    a.append(str(random.randint(10, 100000)))
print(" ".join(a))