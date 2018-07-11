num = input()
num = list(num)
ans = 0
for i in range(0,len(num)):
	ans += int(num[i])
print(ans)