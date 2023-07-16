import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        int len;
        int start = 0, end = 0;
        
        //보석의 종류
        Set<String> kind = new HashSet<String>(Arrays.asList(gems));
        Map<String, Integer> dic = new HashMap<>();
        
        for(int i=0;i<gems.length;i++){
            dic.put(gems[i], dic.getOrDefault(gems[i], 0) + 1);
            
            //순차적으로 종류만큼 있는 경우
            if(dic.size() == kind.size()){
                break;
            }
            
            end++;
        }
        len = end - start;
        answer[0] = start+1;
        answer[1] = end+1;
        
        while(end < gems.length){
            //왼쪽 땡기기
            String left = gems[start];
            dic.put(left, dic.getOrDefault(left, 0) - 1);
            start++;
            
            //left를 가진 개수가 0인 경우
            if(dic.getOrDefault(left, 0) == 0){
                end++;
                while(end < gems.length){
                    dic.put(gems[end], dic.getOrDefault(gems[end], 0) + 1);
                    if(left.equals(gems[end])){
                        break;
                    }
                    end++;
                }
                if(end >= gems.length)
                    break;
            }
            
            //가장 짧은 구역 갱신
            if(len > end - start){
                len = end - start;
                answer[0] = start+1;
                answer[1] = end+1;
            }
        }
        
        return answer;
    }
}