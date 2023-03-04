encoded_str = input();
num_strings = input();
diff_list = [];
comp_list = [];
str_len = len(encoded_str) - 1;
num=0;
diff_num=0;
d=0;
def making_difflist(length,list,result_list):
    for i in range(length):
        tmp = ord(list[i+1]) - ord(list[i]);
        if(tmp<0): tmp+=26;
        result_list.append(tmp);

def cmp(a,b):
    if((a>b) - (b<a)): return 0;
    else: return 1;
        
making_difflist(str_len,encoded_str,diff_list);

for i in range(int(num_strings)):
    compare_str = input();
    making_difflist(len(compare_str)-1,compare_str,comp_list);
    for j in range(len(diff_list)-len(comp_list)+1):
        if(diff_list[j:j+len(comp_list)] == comp_list):
            num=j;
            diff_num = ord(encoded_str[num]) - ord(compare_str[0]);
            d=1;
            break;
    if(d==1):
        break;
    comp_list = [];

if(diff_num<0):
    for i in range(str_len+1):
        result_num = ord(encoded_str[i])-diff_num;
        if(result_num>122): result_num-=26;
        print(chr(result_num),end="");
else:
    for i in range(str_len+1):
        result_num = ord(encoded_str[i])-diff_num;
        if(result_num<97):
            result_num+=26;
        print(chr(result_num),end=""); 