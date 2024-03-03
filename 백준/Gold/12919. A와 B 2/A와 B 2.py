def dfs(s):
    if len(s)==len(S):
        return s==S
    if s[-1]=='A':
        if dfs(s[:-1]):
            return True
    if s[0]=='B':
        if dfs(s[1:][::-1]):
            return True
    return False
    
S = input()
T = input()

if dfs(T):
    print(1)
else:
    print(0)