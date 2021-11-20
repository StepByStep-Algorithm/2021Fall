import sys

word = list(sys.stdin.readline().rstrip())
letters = 0
i = 0
while word:
    #c=
    if word[i] == 'c' and i < len(word) - 1 and word[i + 1] == '=':
        letters += 1
        del word[i:i + 2]
    #c-
    elif word[i] == 'c' and i < len(word) - 1 and word[i + 1] == '-':
        letters += 1
        del word[i:i + 2]
    #dz=
    elif word[i] == 'd' and i < len(word) - 2 and word[i + 1] == 'z' and word[i + 2] == '=':
        letters += 1
        del word[i:i + 3]
    #d-
    elif word[i] == 'd' and i < len(word) - 1 and word[i + 1] == '-':
        letters += 1
        del word[i:i + 2]
    #lj
    elif word[i] == 'l' and i < len(word) - 1 and word[i + 1] == 'j':
        letters += 1
        del word[i:i + 2]
    #nj
    elif word[i] == 'n' and i < len(word) - 1 and word[i + 1] == 'j':
        letters += 1
        del word[i:i + 2]
    #s=
    elif word[i] == 's' and i < len(word) - 1 and word[i + 1] == '=':
        letters += 1
        del word[i:i + 2]
    #z=
    elif word[i] == 'z' and i < len(word) - 1 and word[i + 1] == '=':
        letters += 1
        del word[i:i + 2]
    else:
        del word[i]
        letters += 1


##('c=','c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=')

print(letters)

