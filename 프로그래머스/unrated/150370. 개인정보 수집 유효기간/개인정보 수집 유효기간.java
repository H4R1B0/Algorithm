import java.util.*;

class Solution {
    final int MONTH = 28;
    final int YEAR = 12 * MONTH;
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        
        Map<String, Integer> termMap = new HashMap<>();
        for(String term : terms){
            StringTokenizer st = new StringTokenizer(term);
            termMap.put(st.nextToken(), Integer.parseInt(st.nextToken()));
        }
        
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<privacies.length;i++){
            String privacy = privacies[i];
            int day = getDay(today);
            StringTokenizer st = new StringTokenizer(privacy);
            if(day >= getDay(st.nextToken()) + termMap.get(st.nextToken())*MONTH){
                ans.add(i+1);
            }
        }
        int[] answer = new int[ans.size()];
        for(int i=0;i<answer.length;i++){
            answer[i] = ans.get(i);
        }
        return answer;
    }
    
    int getDay(String date){
        String[] tmp = date.split("\\.");
        int day = Integer.parseInt(tmp[0])*YEAR + Integer.parseInt(tmp[1])*MONTH + Integer.parseInt(tmp[2]);
        return day;
    }
}