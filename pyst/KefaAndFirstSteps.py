from sys import stdin, stdout

best = stdin.readline()
max = 0
cnt = 0
index = 0
for x in stdin.readline().split(' '):
    if x<index:
        if max<cnt:
            max = cnt
        cnt = 1
    else:
        cnt+=1
    index = x
if not max:
    stdout.write(str(best))
else:
    stdout.write(str(max))