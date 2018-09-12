a=int(input())
b=int(input())
c=int(input())
A=a*a
B=b*b
C=c*c
if a+b<c or a+c<b or b+c<a:
    print("null",end="")
elif A+B==C or B+C==A or A+C==B:
    print("3",end="")
elif (float)(A+B-C)/(2*a*b)>0 and (float)(B+C-A)/(2*b*c)>0 and (float)(A+C-B)/(2*a*c)>0:
    print("1",end="")
else:
    print("2",end="")
