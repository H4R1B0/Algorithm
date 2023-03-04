import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N;
    static int[][] board;
    static PriorityQueue<Pos> pq = new PriorityQueue<>((o1, o2) -> {
        return o1.cost - o2.cost;
    });

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= T; testCase++) {
            N = Integer.parseInt(br.readLine());
            board = new int[N][N];
            for (int i = 0; i < N; i++) {
                char[] input = br.readLine().toCharArray();
                for (int j = 0; j < N; j++) {
                    board[i][j] = input[j] - '0';
                }
            }
            System.out.printf("#%d %d\n", testCase, getAnswer());
        }
    }

    static int getAnswer() {
        pq.clear();
        int answer = Integer.MAX_VALUE;
        boolean[][] visit = new boolean[N][N];
        visit[0][0] = true;
        pq.add(new Pos(0, 0, 0));
        while (!pq.isEmpty()) {
            Pos cur = pq.poll();

            if (cur.x == N - 1 && cur.y == N - 1) {
                answer = Math.min(answer, cur.cost);
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + xd[i];
                int ny = cur.y + yd[i];
                if (!isInRange(nx, ny) || visit[nx][ny])
                    continue;

                visit[nx][ny] = true;
                int nextCost = cur.cost + board[nx][ny];
                pq.add(new Pos(nx, ny, nextCost));
            }
        }
        return answer;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    static class Pos {
        int x, y, cost;

        public Pos(int x, int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
}