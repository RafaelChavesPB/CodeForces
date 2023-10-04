def test(total, weekArr):
    costPerWeek = sum(weekArr)
    fullWeeks = total//costPerWeek
    rest = total%costPerWeek
    result = []
    for start in range(len(weekArr)):
        curr = rest + 0
        i = start + 0
        count = 0
        while(curr >= 0):
            count += 1;
            curr -= weekArr[i];
            i = (i + 1) % len(weekArr)
        result.append(count+len(weekArr)*fullWeeks)
    return result
        
    

abc = [int(x) for x in input().split()]
weekArrays = [[1,1,0,0,1,0,0], [0,0,1,0,0,0,1], [0,0,0,1,0,1,0]]
ans = 0
for weekDayResult in zip(*[test(abc[i], weekArrays[i]) for i in range(len(weekArrays))]):
    ans = max(min(weekDayResult), ans)
print(ans - 1)

