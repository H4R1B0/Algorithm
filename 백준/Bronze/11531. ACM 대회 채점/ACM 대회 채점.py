pro_list=[];
ox_list=[];
fail_list=[];
count=0;
sum=0;
while True:
    args=input();
    if(args==('-1')):
        break;
    args_list=args.split(' ');
    num=args_list[0];
    id=args_list[1];
    ox=args_list[2];
    if id in pro_list:
        if(ox=="right"):
            if(ox_list[pro_list.index(id)]=="wrong"):
                ox_list[pro_list.index(id)]="right";
                sum+=20*int(fail_list[pro_list.index(id)]);
                sum+=int(num);
                count+=1;
        else:
            ox_list[pro_list.index(id)]="wrong";
            fail_list[pro_list.index(id)]=str(int(fail_list[pro_list.index(id)])+1);
    else:
        pro_list.append(id);
        if(ox=="right"):
            sum+=int(num);
            ox_list.append("right");
            fail_list.append('0');
            count+=1;
        else:
            ox_list.append("wrong");
            fail_list.append('1');
print(str(count)+' '+str(sum));
