class Solution {
    int N, M, endX, endY;
    String tmp = "";
    String[] dir = {"d", "l", "r", "u"};
    int xd[] = {1,0,0,-1};
    int yd[] = {0,-1,1,0};
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        N = n;
        M = m;
        endX = r-1;
        endY = c-1;
        int dist = Math.abs(r-x) + Math.abs(c-y);
        dfs(x-1,y-1,k,"",dist);
        if(tmp.equals(""))
            return "impossible";
        return tmp;
    }
    
    boolean dfs(int x, int y, int k, String str, int dist){
        //이동 가능한 횟수 0, 남은 거리 0
        if(k==0 && dist ==0){
            tmp = str;
            return true;
        }
        
        for(int i=0;i<4;i++){
            int nx = x+xd[i];
            int ny = y+yd[i];
            //범위 안에 있으면서 남은 이동 거리가 k이하인 경우만 가능
            if(isInRange(nx,ny) && dist<=k){
                //현재 방향으로 갔다가 반대로 가는 경우도 있기 때문에 dist와 k가 같은 홀수나 짝수여야함
                if((dist%2) == (k%2)){
                    if(dfs(nx, ny, k-1, str+dir[i], Math.abs(endX-nx) + Math.abs(endY-ny)))
                        return true;
                }
            }
        }
        return false;
    }
    
    boolean isInRange(int x, int y){
        return x>=0 && x<N && y>=0 && y<M;
    }
}