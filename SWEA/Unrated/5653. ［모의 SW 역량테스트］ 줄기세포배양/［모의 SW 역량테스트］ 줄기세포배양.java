import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
    static final int MAX = 410;
    static final int DEFAULT = 200;
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int N, M, K;
    static boolean[][] visit;
    static PriorityQueue<Cell> pq = new PriorityQueue<>((o1, o2) -> {
        return o2.vitality - o1.vitality;
    });

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            visit = new boolean[MAX][MAX];
            pq.clear();
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    int num = Integer.parseInt(st.nextToken());
                    if (num != 0) {
                        int x = DEFAULT + i;
                        int y = DEFAULT + j;
                        pq.offer(new Cell(x, y, num, num));
                        visit[x][y] = true;
                    }
                }
            }

            System.out.printf("#%d %d\n", test_case, getAnswer());

        }
    }

    static int getAnswer() {
        Queue<Cell> tmp = new LinkedList<Cell>();
        for (int time = 1; time <= K; time++) {
//            System.out.println(pq.size());
            while (!pq.isEmpty()) {
                Cell cell = pq.poll();

                cell.time--;
                if (cell.time == -1) {
                    for (int i = 0; i < 4; i++) {
                        int nx = cell.x + xd[i];
                        int ny = cell.y + yd[i];
                        if (!isInRange(nx, ny))
                            continue;
                        if (!visit[nx][ny]) {
                            visit[nx][ny] = true;
                            tmp.add(new Cell(nx, ny, cell.vitality, cell.vitality));
                        }
                    }
                }
                if (cell.time > -cell.vitality) {
                    tmp.add(cell);
                }
            }
            while (!tmp.isEmpty())
                pq.add(tmp.poll());
        }
        return pq.size();
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < MAX && y >= 0 && y < MAX;
    }

    static class Cell {
        int x, y, vitality, time;

        public Cell(int x, int y, int vitality, int time) {
            this.x = x;
            this.y = y;
            this.vitality = vitality;
            this.time = time;
        }
    }

}