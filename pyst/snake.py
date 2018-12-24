def snake(arr):
    reverse = True
    for i in xrange(len(arr)):
        reverse = not reverse
        if reverse:
            for j in xrange(len(arr[i])):
                print arr[i][len(arr[i])-1-j]
        else:
            for j in xrange(len(arr[i])):
                print arr[i][j]
