import java.util.*;

class Solution {
    int N, M;
    int[] xd = {0,0,1,-1};
    int[] yd = {1,-1,0,0};
    boolean[][] visit;
    int[][] arr;
    Map<Integer, Integer> map = new HashMap<>();
    
    public int solution(int[][] land) {
        int answer = 0;
        N = land.length;
        M = land[0].length;
        visit = new boolean[N][M];
        arr = new int[N][M];
        
        
        int idx = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(land[i][j] == 1 && !visit[i][j]){
                    bfs(i,j, land, idx);
                    idx++;
                }
            }
        }
        
        Set<Integer> set = new HashSet<>();
        for(int j=0;j<M;j++){
            set.clear();
            int sum=0;
            for(int i=0;i<N;i++){
                if(arr[i][j] == 0)
                    continue;
                
                set.add(arr[i][j]);
            }
            
            for(int s : set){
                sum+=map.get(s);
            }
            answer = Math.max(answer, sum);
        }
        
        return answer;
    }
    
    private void bfs(int a, int b, int[][] land, int idx){
        int cnt = 1;
        visit[a][b] = true;
        List<int[]> pos = new ArrayList<>();
        pos.add(new int[]{a,b});
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{a,b});
        while(!q.isEmpty()){
            int[] cur = q.poll();
            
            for(int i=0;i<4;i++){
                int nx = cur[0]+xd[i];
                int ny = cur[1]+yd[i];
                
                if(isRange(nx,ny) && land[nx][ny] == 1 && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    q.offer(new int[]{nx,ny});
                    pos.add(new int[]{nx,ny});
                    cnt++;
                }
            }
        }
        
        for(int[] p : pos){
            arr[p[0]][p[1]] = idx;
        }
        map.put(idx, cnt);
    }
    
    private boolean isRange(int x, int y){
        return x>=0 && x<N && y>=0 && y<M;
    }
}