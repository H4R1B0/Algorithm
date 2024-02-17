def post_order(root, s, e):
    for i in range(s,e):
        if in_order[i]==pre_order[root]:
            post_order(root+1, s,i)
            post_order(root+1+i-s,i+1,e)
            print(pre_order[root], end=" ")

t = int(input())
for _ in range(t):
    n = int(input())
    pre_order = list(map(int, input().split()))
    in_order = list(map(int, input().split()))
    post_order(0,0,n)
    print()