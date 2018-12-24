from sys import stdin

tot = int(stdin.readline())
ant = 0
for char in stdin.readline():
    if char == 'A':
        ant+=1

dan = tot-ant
if dan>ant:
    print 'Danik'
elif ant==dan:
    print 'Friendship'
else:
    print 'Anton'