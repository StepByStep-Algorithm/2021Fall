# BOJ 13706번 : 제곱근

#from math import isqrt
# print(isqrt(int(input())))

n = int(input()) # n 입력받기
low = 1
high = n

# 이진 탐색
while 1:
    mid = (low + high) // 2
    if (mid ** 2 == n): # mid x 2가 n이면
        print(mid) # mid 출력
        break
    elif (mid ** 2 > n): # mid x 2가 n보다 크면
        high = mid - 1 # high 값을 mid - 1로 갱신
    elif (mid ** 2 < n): # mid x 2가 n보다 작으면
        low = mid + 1 # low 값을 mid + 1로 갱신