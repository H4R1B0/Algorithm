class Solution {
    int answer = Integer.MAX_VALUE;
    int N;
    int[][] values = {{1,1,1},{5,1,1},{25,5,1}};
    public int solution(int[] picks, String[] minerals) {
        //광물 개수
        N = minerals.length;
        //초기 세팅
        int[] arr = new int[N];
        for(int i=0;i<N;i++){
            if(minerals[i].equals("diamond"))
                arr[i] = 0;
            else if(minerals[i].equals("iron"))
                arr[i] = 1;
            else
                arr[i] = 2;
        }
        
        //곡괭이 3개 각각 시작
        for(int i=0;i<3;i++){
            if(picks[i] > 0){                
                picks[i]--;
                solve(i, 0, 0, picks, arr, 0);
                picks[i]++;
            }
        }
        return answer;
    }
    
    //현재 pick, pick 사용 횟수, 광물 확인 개수, picks, minerals, 합
    void solve(int pick, int pickCount, int checkCount, int[] picks, int[] minerals, int sum){
        // System.out.print(pick+" ");
        // if(answer < sum)
        //     return;
        
        if(checkCount == N || (pickCount==5 && picks[0]==0 && picks[1]==0 && picks[2]==0)){
            // System.out.println();
            answer = Math.min(answer, sum);
            return;
        }
        
        //현재 곡괭이 다 쓴 경우
        if(pickCount == 5){
            //쓸 수 있는 곡괭이 사용
            for(int i=0;i<3;i++){
                if(picks[i] > 0){
                    picks[i]--;
                    solve(i, 0, checkCount, picks, minerals, sum);
                    picks[i]++;
                }
            }
        }
        else{            
            solve(pick, pickCount+1, checkCount+1, picks, minerals, sum+values[pick][minerals[checkCount]]);
        }
    }
}