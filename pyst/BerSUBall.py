from sys import stdin

b = int(stdin.readline())
boys = [int(x) for x in stdin.readline().split(' ')]
boys.sort()

g = int(stdin.readline())
girls = [int(x) for x in stdin.readline().split(' ')]
girls.sort()

cnt = 0
bc = 0
gc = 0

while True:
    if boys[bc]-girls[gc] in [-1,0,1]:
        cnt+=1
        bc+=1
        gc+=1
    elif boys[bc]>girls[gc]:
        gc+=1
    else:
        bc+=1
    if bc == b or gc == g:
        break

print cnt