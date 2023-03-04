encode_list=["000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"];
ABCDEFGH_list=['A','B','C','D','E','F','G','H'];
count=input();
word=input();
word_len=len(word);
word_list=[];
word_not='';
realword='';
def check(word_ch):
    b=0;
    for i in range(8):
        num=0;
        for j in range(6):
            if(word_ch[j]!=encode_list[i][j]):
                num+=1;
            if(num>2):
                break;
        if(num<=1):
            b=1;
            return ABCDEFGH_list[i];
    if(b==0):
        global word_not;
        if(word_not==''):
            word_not=word_ch;
        return str(word_list.index(word_not)+1);
for i in range(int(count)):
    word_list.append(word[i*6:(i+1)*6]);
b=0;
for i in range(int(count)):
    if check(word_list[i]) in ABCDEFGH_list:
        realword+=check(word_list[i]);
    else:
        print(check(word_list[i]));
        b=1;
        break;
if(b==0):
    print(realword);
