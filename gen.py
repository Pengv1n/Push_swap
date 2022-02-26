import random

size = 500
a = []
for _ in range(size):
    a.append(str(random.randint(-500000, 500000)))
print(" ".join(a))