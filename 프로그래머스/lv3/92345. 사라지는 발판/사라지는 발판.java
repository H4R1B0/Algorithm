class Solution {
    int N, M;
    int[] xd = {0,0,1,-1};
    int[] yd = {1,-1,0,0};
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        N = board.length;
        M = board[0].length;
        Node answer = dfs(board, aloc, bloc);
        return answer.cnt;
    }
    
    Node dfs(int[][] board, int[] aloc, int[] bloc){
        //게임이 끝난 경우
        if(isFinish(board, aloc))
            return new Node(false, 0);
        //a가 b를 잡은 경우
        if(aloc[0] == bloc[0] && aloc[1] == bloc[1])
            return new Node(true, 1);
        boolean isWin = false;
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for(int i=0;i<4;i++){
            int nx = aloc[0]+xd[i];
            int ny = aloc[1]+yd[i];
            if(isInRange(nx,ny) && board[nx][ny] == 1){
                board[aloc[0]][aloc[1]] = 0;
                Node ret = dfs(board, bloc, new int[]{nx,ny});
                board[aloc[0]][aloc[1]] = 1;
                    
                //게임 아직 진행중
                if(!ret.result){
                    min = Math.min(min, ret.cnt);
                    isWin=true;
                }
                //게임이 끝났는데 잡음
                else if(!isWin){
                    max = Math.max(max, ret.cnt);
                }
            }
        }
        //최적의 플레이를 한 경우이기 때문에
        //이긴 경우는 min
        //진 경우는 max
        int turn = isWin ? min : max;
        return new Node(isWin, turn+1);
    }
    
    boolean isFinish(int[][] board, int[] aloc){
        for(int i=0;i<4;i++){
            int nx = aloc[0]+xd[i];
            int ny = aloc[1]+yd[i];
            if(isInRange(nx,ny) && board[nx][ny] == 1)
                return false;
        }
        return true;
    }
    
    boolean isInRange(int x, int y){
        return x>=0 && x<N && y>=0 && y<M;
    }
    
    class Node{
        boolean result;
        int cnt;
        Node(){
            
        }
        Node(boolean result, int cnt){
            this.result = result;
            this.cnt = cnt;
        }
    }
}