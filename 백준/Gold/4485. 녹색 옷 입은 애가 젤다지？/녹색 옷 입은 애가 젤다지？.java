import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N;
    static int[][] board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int testCase = 1; ; testCase++) {
            N = Integer.parseInt(br.readLine());
            if (N == 0)
                break;
            board = new int[N][N];
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int answer = getAnswer();
            System.out.println(String.format("Problem %d: %d", testCase, answer));
        }
    }

    static int getAnswer() {
        int answer = 0;
        int[][] dist = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        dist[0][0] = board[0][0];
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            return o1[2] - o2[2];
        });
        pq.add(new int[]{0, 0, board[0][0]});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int x = cur[0];
            int y = cur[1];
            int cost = cur[2];

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];
                if(isInRange(nx,ny)){
                    int nextCost = cost + board[nx][ny];
                    if(dist[nx][ny] > nextCost){
                        dist[nx][ny] = nextCost;
                        pq.add(new int[]{nx,ny,nextCost});
                    }
                }
            }
        }
        return dist[N-1][N-1];
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}