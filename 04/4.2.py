x=[0]*3
y=[0]*3
X=0
Y=0
MAX=0
for i in range(0,3):
    x[i]=int(input())
    y[i]=int(input())
    if x[i]*x[i]+y[i]*y[i]>MAX:
        X=x[i]
        Y=y[i]
        MAX=x[i]*x[i]+y[i]*y[i]
print(X)
print(Y,end="")
