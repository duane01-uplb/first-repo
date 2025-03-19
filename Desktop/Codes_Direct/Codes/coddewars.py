n = int(input())

find = False

divisors = []
mini_divisors = []
divisors_of_mini_divisors = []

for i in range(1 , n):
    if  n % i == 0:
        divisors.append(i)

for i in divisors:
    for j in range(1 , i):
        if i % j == 0:
            if j in mini_divisors:
                continue
            else:
                mini_divisors.append(i)

for j in mini_divisors:
    for i in range(1 , j):
        if j % i == 0:
            divisors_of_mini_divisors.append(i)
            if j ** len(divisors_of_mini_divisors) == n:
                print(j)
                find = True
                break
if not find:
    print("-1")