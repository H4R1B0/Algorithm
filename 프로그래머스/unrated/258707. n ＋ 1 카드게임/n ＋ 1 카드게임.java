import java.util.*;

class Solution {
    int n;
    public int solution(int coin, int[] cards) {
        int answer = 1;
        int idx = cards.length / 3;
        int target = cards.length + 1;
        
        //보유 카드
        Set<Integer> remainCards = new HashSet<>();
        for (int i = 0; i < idx; i++) {
            remainCards.add(cards[i]);
        }
        
        //픽한 카드
        Set<Integer> pickedCards = new HashSet<>();
        while (!remainCards.isEmpty() && idx < cards.length - 1) {
            //라운드 마다 카드 뽑기
            for (int i = idx; i < idx + 2; i++) {
                pickedCards.add(cards[i]);
            }
            
            Result result = getResult(remainCards, pickedCards, target);
            
            if(result.num == 0) {
                for (int num : result.nums) {
                    remainCards.remove(num);
                }
                idx += 2;
                answer++;
            } else if(result.num == 1) {
                if (coin >= 1) {
                    remainCards.remove(result.nums[0]);
                    pickedCards.remove(result.nums[1]);
                    coin -= 1;
                    idx += 2;
                    answer++;
                } else {
                    break;
                }
            } else if (result.num == 2) {
                if (coin >= 2) {
                    for (int num : result.nums) {
                        pickedCards.remove(num);
                    }
                    coin -= 2;
                    idx += 2;
                    answer++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        return answer;
    }
    
    Result getResult(Set<Integer> remainCards, Set<Integer> pickedCards, int target) {
        for(int num : remainCards) {
            //coin 0개 소비
            if(remainCards.contains(target - num)) {
                return new Result(0, new int[]{num, target-num});
            }
            //coin 1개 소비
            // if(pickedCards.contains(target - num)) {
            //     return new Result(1, new int[]{num, target-num});
            // }
        }
        //coin 1개 소비
        for(int num : remainCards) {
            if(pickedCards.contains(target - num)) {
                return new Result(1, new int[]{num, target-num});
            }
        }
        
        //coin 2개 소비
        for (int num : pickedCards) {
            if (pickedCards.contains(target - num)) {
                return new Result(2, new int[]{num, target - num});
            }
        }
        
        return new Result(-1, null);
    }
    
    class Result{
        int num;
        int[] nums;
        
        Result(int num, int[] nums){
            this.num = num;
            this.nums = nums;
        }
    }
}