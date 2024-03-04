def solution(h1, m1, s1, h2, m2, s2):
    answer = 0
    start_time = h1*3600+m1*60+s1
    end_time = h2*3600+m2*60+s2
    if start_time in [0,12*3600]:
        answer += 1
    while start_time < end_time:
        cur_h = start_time/120%360
        cur_m = start_time/10%360
        cur_s = start_time*6%360
        
        start_time += 1
        
        if start_time/120%360 == 0:
            next_h = 360
        else:
            next_h = start_time/120%360
        if start_time/10%360 == 0:
            next_m = 360
        else:
            next_m = start_time/10%360
        if start_time*6%360 == 0:
            next_s = 360
        else:
            next_s = start_time*6%360
            
        if cur_s < cur_h and next_s >= next_h:
            answer += 1
        if cur_s < cur_m and next_s >= next_m:
            answer += 1
        if next_s == next_h and next_h == next_m:
            answer -= 1
        
    return answer