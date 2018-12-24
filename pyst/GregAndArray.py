from sys import stdin

utl = [int(x) for x in stdin.readline().split(' ')]
n = utl[0]
m = utl[1]
k = utl[2]
que = [0]*(n+2)
arr = [0]+[int(x) for x in stdin.readline().split(' ')]+[0]
sto = [0]
for _ in xrange(m):
    sto.append(stdin.readline().split(' '))
for _ in xrange(k):
    (i,j) = (int(x) for x in stdin.readline().split(' '))
    que[i] +=1
    que[j+1]-=1
for i in xrange(1,n):
    que[i]=que[i-1]+que[i]

for i,[L,R,D] in enumerate(sto):
    sto[i][2]*=que[i]
