from random import randint
LIMIT = 2*10**5
print(LIMIT)
print(*[randint(0,100) for x in range(LIMIT)])
print(LIMIT)
for i in range(LIMIT):
    a = randint(0, LIMIT)
    b = randint(0, LIMIT)
    print(min(a,b),max(a,b))

