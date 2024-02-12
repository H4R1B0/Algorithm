str = input()
l = len(str)
# print(str[:l//2])
# print(str[::-1][:l//2])
if str[:l//2]==str[::-1][:l//2]:
    print(1)
else:
    print(0)