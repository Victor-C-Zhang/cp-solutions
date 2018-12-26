from sys import stdin, stdout

t = int(stdin.readline())
for _ in xrange(t):
    g = int(stdin.readline())
    if g==0:
        print "1"
    elif g==1:
        print "1"
    elif g==2:
        print "2"
    else:
        n = g-3
        f = ((n*(n+1)*(n*n + 5*n + 18))/4 + 12*n)/6 +4
        print f
