class Solution {
    int N, M;
    int[] xd = {-1,1,0,0};
    int[] yd = {0,0,-1,1};
    int[][] map;
    boolean[][][] visit;
    boolean redEnd, blueEnd;
    
    public int solution(int[][] maze) {
        int answer = 0;
        N = maze.length;
        M = maze[0].length;
        
        Point red=null, blue=null;
        map = new int[N][M];
        visit = new boolean[N][M][2];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                map[i][j] = maze[i][j];
                
                if(maze[i][j] == 1){
                    red = new Point(i,j);
                } else if(maze[i][j] == 2){
                    blue = new Point(i,j);
                }
            }
        }
        
        visit[red.x][red.y][0] = true;
        visit[blue.x][blue.y][1] = true;
        answer = dfs(red, blue, 0);
        return answer==Integer.MAX_VALUE ? 0:answer;
    }
    
    private int dfs(Point red, Point blue, int cnt){
        if(redEnd && blueEnd){
            return cnt;
        }
        
        int answer = Integer.MAX_VALUE;
        
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                Point nextRed = (!redEnd) ? getPoint(red,i) : red;
                Point nextBlue = (!blueEnd) ? getPoint(blue,j) : blue;
                
                if(!isPossible(red, nextRed, blue, nextBlue)){
                    continue;   
                }
                
                visit[nextRed.x][nextRed.y][0] = true;
                visit[nextBlue.x][nextBlue.y][1] = true;
                
                if(map[nextRed.x][nextRed.y] == 3){
                    redEnd = true;
                }
                if(map[nextBlue.x][nextBlue.y] == 4){
                    blueEnd = true;
                }
                
                answer = Math.min(answer, dfs(nextRed, nextBlue, cnt+1));
                
                redEnd = false;
                blueEnd = false;
                
                visit[nextRed.x][nextRed.y][0] = false;
                visit[nextBlue.x][nextBlue.y][1] = false;
            }
        }
        return answer;
    }
    
    private Point getPoint(Point pos, int dir){
        return new Point(pos.x+xd[dir], pos.y+yd[dir]);
    }
    
    private boolean isPossible(Point curRed, Point nextRed, Point curBlue, Point nextBlue){
        if(nextRed.x<0 || nextRed.x>=N || nextRed.y<0 || nextRed.y>=M || map[nextRed.x][nextRed.y] == 5){
            return false;
        }
        if(nextBlue.x<0 || nextBlue.x>=N || nextBlue.y<0 || nextBlue.y>=M || map[nextBlue.x][nextBlue.y] == 5){
            return false;
        }
        
        if((curRed.x == nextBlue.x && curRed.y == nextBlue.y) && (curBlue.x == nextRed.x && curBlue.y == nextRed.y)){
            return false;
        }
        
        if((!redEnd && visit[nextRed.x][nextRed.y][0]) || (!blueEnd && visit[nextBlue.x][nextBlue.y][1])){
            return false;   
        }
        
        if(nextRed.x==nextBlue.x && nextRed.y==nextBlue.y){
            return false;
        }
        
        return true;
    }
    
    class Point{
        int x, y;
        
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}