time1=input();
time2=input();
time1_args=time1.split(':');
time1_sum=3600*int(time1_args[0])+60*int(time1_args[1])+int(time1_args[2]);
time2_args=time2.split(':');
time2_sum=3600*int(time2_args[0])+60*int(time2_args[1])+int(time2_args[2]);
sum=time2_sum-time1_sum;
if(sum<0):
    sum+=3600*24;
time_list=[];
time_list.append(str(int(sum/3600)));
time_list.append(str(int(sum%3600/60)));
time_list.append(str(int(sum%60)));
for i in range(3):
    if(len(time_list[i])==1):
        time_list[i]='0'+time_list[i];
print(time_list[0]+':'+time_list[1]+':'+time_list[2]);