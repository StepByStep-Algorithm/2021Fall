n = int(input())
front = 1
back = n

while 1:
    middle = (front + back) // 2
    if middle ** 2 == n:
        print(middle)
        break
    elif middle ** 2 > n:
        back = middle - 1
    elif middle ** 2 < n:
        front = middle+ 1