from itertools import permutations
nums=['1','2','3','4','5','6','7','8','9']
arr=list(permutations(nums,3))
#print(arr)
N=int(input())
for _ in range(N):
    #print(arr)
    tmp=[]
    #print(type(tmp))
    word,s,b=map(int,input().split())
    word=list(str(word))
    #print(word)
    for num in arr:
        #print('1' in num)
        tmp_s,tmp_b=0,0
        for i in range(len(word)):
            if word[i] in num:
                #print(num[i])
                if word[i]==num[i]:
                    tmp_s+=1
                else:
                    tmp_b+=1
        #print(tmp_s,tmp_b)
        if tmp_s==s and tmp_b==b:
            tmp.append(num)
            #print(num)
    #print(tmp)
    arr=tmp
    #print(arr)
print(len(tmp))
        
