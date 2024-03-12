def solution(bandage, health, attacks):
    attack_idx = 0
    cnt = 0
    cur_health = health
    for time in range(1,attacks[-1][0]+1):
        if time==attacks[attack_idx][0]:
            cur_health -= attacks[attack_idx][1]
            attack_idx += 1
            cnt = 0
        else:
            cur_health = min(health, cur_health+bandage[1])
            cnt += 1
            if cnt==bandage[0]:
                cur_health = min(health, cur_health+bandage[2])
                cnt = 0
        if cur_health<=0:
            return -1
    return cur_health