from sys import stdin, stdout

stdin.readline()

index = None
cnt = 0
for char in stdin.readline():
    if char == index:
        cnt+=1
    else: index = char

stdout.write(str(cnt))