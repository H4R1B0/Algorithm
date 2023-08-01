import java.util.*;

class Solution {
    int N, M;
    int[] xd = {0,0,1,-1};
    int[] yd = {1,-1,0,0};
    int[] start;
    char[][] initBoard;
    boolean[][] visit;
    
    public int solution(String[] board) {
        int answer = Integer.MAX_VALUE;
        N = board.length;
        M = board[0].length();
        initBoard = new char[N][M];
        visit = new boolean[N][M];
        
        for(int i=0;i<N;i++){
            initBoard[i] = board[i].toCharArray();
            for(int j=0;j<M;j++){
                if(initBoard[i][j] == 'R'){
                    start = new int[]{i,j};
                    initBoard[i][j] = '.';
                }
            }
        }
        return bfs();
    }
    
    int bfs(){
        //x, y
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{start[0], start[1], 0});
        visit[start[0]][start[1]] = true;
        while(!q.isEmpty()){
            int[] cur = q.poll();
            
            if(initBoard[cur[0]][cur[1]] == 'G')
                return cur[2];
            
            for(int dir=0;dir<4;dir++){
                int x = cur[0];
                int y = cur[1];
                
                while(isInRange(x, y) && initBoard[x][y]!='D'){
                    x += xd[dir];
                    y += yd[dir];
                }
                x -= xd[dir];
                y -= yd[dir];
                
                if(visit[x][y])
                    continue;
                visit[x][y] = true;
                q.offer(new int[]{x,y,cur[2]+1});
            }
        }
        
        return -1;
    }
    
    boolean isInRange(int x, int y){
        return x>=0 && x< N && y>=0 && y<M;
    }
}