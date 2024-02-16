def solution(friends, gifts):
    friends = sorted(friends)
    give_cnt = {friend: 0 for friend in friends}
    receive_cnt = {friend: 0 for friend in friends}
    present_score = {friend: 0 for friend in friends}
    next_month_cnt = {friend: 0 for friend in friends}
    gr_record = {
        friend: {other: [0,0] for other in set(friends)-{friend}}
        for friend in friends
    }
    # print(gr_record))
    for gift in gifts:
        giver, receiver = gift.split()
        give_cnt[giver]+=1
        receive_cnt[receiver]+=1
        gr_record[giver][receiver][0]+=1
        gr_record[receiver][giver][1]+=1
    
    
    for friend in friends:
        present_score[friend] = give_cnt[friend] - receive_cnt[friend]
    # print(present_score)
    
    for i in range(len(friends)-1):
        friend = friends[i]
        others = friends[i+1:]
        for other in others:
            AtoB = gr_record[friend][other][0]
            BtoA = gr_record[friend][other][1]
            if AtoB > BtoA:
                next_month_cnt[friend]+=1
            elif AtoB < BtoA:
                next_month_cnt[other]+=1
            else:
                if present_score[friend] > present_score[other]:
                    next_month_cnt[friend] += 1
                elif present_score[friend] < present_score[other]:
                    next_month_cnt[other] += 1
    answer = max(list(next_month_cnt.values()))
    return answer