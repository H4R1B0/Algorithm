mo_list=['a','e','i','o','u'];
mo='';
aeiou_list=[];
while True:
    b=0;
    word=input();
    if(word=='#'):
        break;
    for i in range(0,len(word)):
        if word[i] in mo_list:
            mo=word[i];
            b=1;
            break;
    if(b==0):
        print(word+'ay');
    else:
        print(word[word.index(mo):]+word[0:word.index(mo)]+'ay');