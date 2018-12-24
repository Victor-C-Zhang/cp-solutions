from sys import stdin
import math

stdin.readline()
L = [int(x) for x in stdin.readline().split(' ')]
L.sort(reverse=True)

for y in L:
    if round(math.sqrt(y))**2 != y:
        print y
        break
    """x = 1
    while x*x<=y:
        if x*x == y:
            found = True
            break
        x+=1"""
