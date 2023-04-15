import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    static int[] rates = new int[] { 10, 20, 30, 40 };
	static int[] permutatedRates;
    static PriorityQueue<Event> priorityQueue;
    
    public int[] solution(int[][] users, int[] emoticons) {
        // priorityQueue = new PriorityQueue<>(new Comparator<Event>() {
        //     public int compare(Event e1, Event e2) {
        //         if(e1.count == e2.count)
        //             return e1.cost >= e2.cost ? -1 : 1;
        //         return e1.count >= e2.count ? -1 : 1;
        //     }
        // });
        priorityQueue = new PriorityQueue<>((o1,o2)->{
            if(o1.count == o2.count)
                return o2.cost - o1.cost;
            return o2.count - o1.count;
        });
        permutatedRates = new int[emoticons.length];
        permutation(0, users, emoticons);
        Event tmp = priorityQueue.poll();
        int[] answer = {tmp.count, tmp. cost};
        return answer;        
    }
    
    void calculate(int[][] users, int[] emoticons){
        int serviceCount = 0;
        int serviceCost = 0;
        for(int[] user : users){
            int userRate = user[0];
            int userCost = user[1];                
            int buyCost = 0;

            for(int idx=0;idx<emoticons.length;idx++){
                int emoticonRate = permutatedRates[idx];
                if(userRate <= emoticonRate){
                    buyCost += (emoticons[idx]*(100-emoticonRate)/100);
                }
            }
            if(userCost <= buyCost){
                serviceCount++;
            }
            else{
                serviceCost += buyCost;
            }
        }
        priorityQueue.add(new Event(serviceCount, serviceCost));
    }
    
    void permutation(int cnt, int[][] users, int[] emoticons) {
		if (cnt == emoticons.length) {
			calculate(users, emoticons);
			return;
		}
		for (int i = 0; i < 4; i++) {
			permutatedRates[cnt] = rates[i];
			permutation(cnt + 1, users, emoticons);
		}
	}
    
    class Event{
        int count;
        int cost;
        
        Event(int count, int cost){
            this.count = count;
            this.cost = cost;
        }
    }
}