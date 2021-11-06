N = int(input())
start = 1
end = N

def sqroot(start, end, N):
    middle = (start + end) // 2
    if middle * middle == N:
        print(middle)
    elif middle * middle < N:
        sqroot(middle + 1, end, N)
    else:
        sqroot(start, middle - 1, N)

sqroot(start, end, N)

