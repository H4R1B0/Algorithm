import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    //우하좌상
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int N, K, L;
    static boolean[][] apple;
    static Map<Integer, String> moveInfo;
    static Deque<Node> snake;
    static int x, y, dir;

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        apple = new boolean[N][N];

        for (int i = 0; i < K; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            apple[r - 1][c - 1] = true;
        }

        L = Integer.parseInt(br.readLine());
        moveInfo = new HashMap<>();
        for (int i = 0; i < L; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            String dir = st.nextToken();

            moveInfo.put(time, dir);
        }
        //입력 완료

        x = 0;
        y = 0;
        dir = 0;
        snake = new ArrayDeque<>();
        snake.addFirst(new Node(x, y)); //뱀의 초기 위치 넣어주기

        int time = 0; //출력 할 시간
        while (true) {
            //1.시간 +1
            time++;

            //2. 뱀 이동
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //3. 종료 조건 충족 시 종료
            if (isBreak(nx, ny)) {
                break;
            }

            //4. 사과 유무 처리
            snake.addFirst(new Node(nx, ny));
            if (apple[nx][ny]) { //사과가 있다면
                apple[nx][ny] = false;
            } else { //사과가 없다면
                snake.pollLast();
            }

            //5. 현재 시간에 방향을 변경해야 하는 경우 방향 변경
            if (moveInfo.containsKey(time)) {
                String newD = moveInfo.get(time);
                changeDir(newD);
            }

            //6. 방문 처리, 값 변경
            x = nx;
            y = ny;
        }

        System.out.println(time);
    }

    //방향 변경
    private static void changeDir(String newD) {
        if (newD.equals("D")) {
            dir = (dir + 1) % 4;
        } else if (newD.equals("L")) {
            dir -= 1;
            if (dir == -1) dir = 3;
        }
    }

    //종료 조건 처리
    private static boolean isBreak(int x, int y) {
        if (x < 0 || x >= N || y < 0 || y >= N) {
            return true;
        }

        //자기 몸에 닿았을 때
        int size = snake.size();
        for (int i = 0; i < size; i++) {
            Node tmp = snake.pollFirst();
            if (tmp.x == x && tmp.y == y)
                return true;
            snake.addLast(tmp);
        }
        return false;
    }
}