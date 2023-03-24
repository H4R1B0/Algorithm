import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] xd = {-1, 0, 1, 0};
    static int[] yd = {0, 1, 0, -1};
    static int N, K, R;
    static boolean[][][] linked;
    static List<int[]> cows = new ArrayList<>();
    static boolean[][] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        linked = new boolean[N + 1][N + 1][4];
        //길 입력
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            for (int dir = 0; dir < 4; dir++) {
                int nx = x1 + xd[dir];
                int ny = y1 + yd[dir];
                if (nx == x2 && ny == y2) {
                    linked[x1][y1][dir] = true;
                    linked[x2][y2][(dir + 2) % 4] = true;
                }
            }
        }
        //소 위치 입력
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            cows.add(new int[]{x, y});
        }

        int answer = 0;
        for (int i = 0; i < K; i++) {
            visit = new boolean[N + 1][N + 1];
            bfs(cows.get(i)[0], cows.get(i)[1]);
            for (int j = i + 1; j < K; j++) {
                if (!visit[cows.get(j)[0]][cows.get(j)[1]])
                    answer++;
            }
        }
        System.out.println(answer);
    }

    static void bfs(int a, int b) {
        Queue<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{a, b});
        visit[a][b] = true;
        //길을 건너지 않고 만날 수 있는 소 확인
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for (int i = 0; i < 4; i++) {
                //길이 있는 경우 패스
                if (linked[x][y][i])
                    continue;

                int nx = x + xd[i];
                int ny = y + yd[i];
                if (isInRange(nx, ny) && !visit[nx][ny]) {
                    visit[nx][ny] = true;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }

    static boolean isInRange(int x, int y) {
        return x >= 1 && x <= N && y >= 1 && y <= N;
    }
}