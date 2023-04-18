import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[][] water;
    static int[] xd = {0, -1, -1, -1, 0, 1, 1, 1};
    static int[] yd = {-1, -1, 0, 1, 1, 1, 0, -1};
    static Queue<int[]> cloud = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        water = new int[N][N];
        for (int i = 0; i < N; i++) {
//            cloud[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                water[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        //구름 생성
        cloud.add(new int[]{N - 1, 0});
        cloud.add(new int[]{N - 1, 1});
        cloud.add(new int[]{N - 2, 0});
        cloud.add(new int[]{N - 2, 1});

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken()) - 1;
            int s = Integer.parseInt(st.nextToken()) % N;
            move(d, s);
        }
        System.out.println(getAnswer());
    }

    static void move(int d, int s) {
        boolean[][] checked = new boolean[N][N];
        int cloudSize = cloud.size();
        while (cloudSize-- > 0) {
            int[] cur = cloud.poll();
            int x = (cur[0] + xd[d] * s + N) % N;
            int y = (cur[1] + yd[d] * s + N) % N;
            checked[x][y] = true;
            water[x][y]++;
            cloud.add(new int[]{x, y});
        }
        //물 복사
        copyWater();
        //구름 생성
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!checked[i][j] && water[i][j] >= 2) {
                    cloud.add(new int[]{i, j});
                    water[i][j] -= 2;
                }
            }
        }
    }

    static void copyWater() {
        while (!cloud.isEmpty()) {
            int[] cur = cloud.poll();
            water[cur[0]][cur[1]] += getCount(cur[0], cur[1]);
        }
    }

    static int getCount(int x, int y) {
        int cnt = 0;
        for (int i = 1; i < 8; i += 2) {
            int nx = x + xd[i];
            int ny = y + yd[i];
            if (isInRange(nx, ny) && water[nx][ny] > 0)
                cnt++;
        }
        return cnt;
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    static int getAnswer() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cnt += water[i][j];
            }
        }
        return cnt;
    }
}