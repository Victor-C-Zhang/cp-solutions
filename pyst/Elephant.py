from sys import stdin, stdout
from math import ceil

x = str(2*int(stdin.read()))
ans = int(x[:-1])
if x[-1]!="0":
    ans+=1

stdout.write(str(ans))