coin = [50,10,5,1]
change = int(input())
for i in range(0,len(coin)):
	num = int(change / coin[i])
	change -= num * coin[i]
	print(num,end='')
	if i < len(coin)-1 :
		print("\n",end='')