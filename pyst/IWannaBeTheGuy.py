from sys import stdin

L = int(stdin.readline())
X = set(stdin.readline().split()[1:])
for y in stdin.readline().split()[1:]:
    X.add(y)

if len(X)==L:
    print 'I become the guy.'
else:
    print 'Oh, my keyboard!'