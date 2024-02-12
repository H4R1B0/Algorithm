n = input()
arr = list(input())
if arr.count('A')==arr.count('B'):
    print('Tie')
elif arr.count('A')>arr.count('B'):
    print('A')
else:
    print('B')