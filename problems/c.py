f = [1,1]
for i in range(44):
    f.append(f[-1]+f[-2])
for i in range(len(f)):
    print(i, f[i])