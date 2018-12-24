from sys import stdin

stdin.readline()

#do first level
x = max(stdin.readline().split(' '))
for line in stdin.readlines():
    L = line.split(' ').sort(reverse=True)
    for y in L:
        if y<=x:
            x = y
            break
    else:
        print 'NO'
        break
else:
    print 'YES'