class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        int curHealth = health;
        int attackIdx = 0;
        int cnt = 0;
        for(int time=1;time<=attacks[attacks.length-1][0];time++){
            if(time == attacks[attackIdx][0]){
                curHealth -= attacks[attackIdx][1];
                attackIdx++;
                cnt = 0;
            } else{
                curHealth = Math.min(health, curHealth + bandage[1]);
                cnt++;
                
                if(cnt == bandage[0]){
                    curHealth = Math.min(health, curHealth + bandage[2]);
                    cnt = 0;
                }
            }
            
            if(curHealth <= 0)
                return -1;
        }
        return curHealth;
    }
}