import java.util.*;

class Solution {
    int[] xd = {0,0,1,-1};
    int[] yd = {1,-1,0,0};
    int N, M;
    public int solution(int[][] maps) {
        N = maps.length;
        M = maps[0].length;
        int answer = 0;
        int[][] visit = new int[N][M];
        visit[0][0] = 1;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0});
        while(!q.isEmpty()){
            int[] cur = q.poll();
            for(int i=0;i<4;i++){
                int nx = cur[0] + xd[i];
                int ny = cur[1] + yd[i];
                if(isInRange(nx,ny) && visit[nx][ny] == 0 && maps[nx][ny] != 0){
                    visit[nx][ny] = visit[cur[0]][cur[1]]+1;
                    q.add(new int[]{nx,ny});
                }
            }
        }
        return visit[N-1][M-1] == 0 ? -1 : visit[N-1][M-1];
    }
    
    boolean isInRange(int x, int y){
        return x>=0 && x<N && y>=0 && y<M;
    }
}