import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, answer;
    static int[] xd = {0, 0, 1, -1};
    static int[] yd = {1, -1, 0, 0};
    static int[][] board;
    static boolean[][] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new int[N][N];
        visit = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while (true) {
            //가장 큰 블록 찾기
            Block result = getBigBlock();

            if (result.blocks.size() < 2)
                break;
            //블록 삭제
            deleteBlock(result);
            //중력
            gravity();
            //회전
            rotate();
            //중력
            gravity();
        }
        System.out.println(answer);
    }

    static Block getBlock(int a, int b) {
        List<int[]> blocks = new ArrayList<>();
        List<int[]> normalBlocks = new ArrayList<>();
        Queue<int[]> rainbowBlocks = new LinkedList<>();
        Queue<int[]> q = new LinkedList<>();
        blocks.add(new int[]{a, b});
        normalBlocks.add(new int[]{a, b});
        q.add(new int[]{a, b});
        visit[a][b] = true;
        int rainbowCount = 0; //rainbow count

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + xd[i];
                int ny = y + yd[i];

                if (!isInRange(nx, ny) || visit[nx][ny])
                    continue;

                //rainbow
                if (board[nx][ny] == 0) {
                    visit[nx][ny] = true;
                    rainbowBlocks.add(new int[]{nx, ny});
                    rainbowCount++;
                    blocks.add(new int[]{nx, ny});
                    q.add(new int[]{nx, ny});
                }
                //normal block
                else if (board[nx][ny] == board[a][b]) {
                    visit[nx][ny] = true;
                    blocks.add(new int[]{nx, ny});
                    q.add(new int[]{nx, ny});
                    normalBlocks.add(new int[]{nx, ny});
                }
            }
        }

        while (!rainbowBlocks.isEmpty()){
            visit[rainbowBlocks.peek()[0]][rainbowBlocks.peek()[1]] = false;
            rainbowBlocks.poll();
        }

        Collections.sort(normalBlocks, (o1, o2) -> {
            if (o1[0] == o2[0])
                return o1[1] - o2[1];
            return o1[0] - o2[0];
        });

        Block block = new Block();
        block.x = normalBlocks.get(0)[0];
        block.y = normalBlocks.get(0)[1];
        block.rainbowCount = rainbowCount;
        block.blocks = blocks;
        return block;
    }

    static Block getBigBlock() {
        visit = new boolean[N][N];
        Block result = new Block();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visit[i][j]) {
                    if (board[i][j] >= 1 && board[i][j] <= M) {
                        Block tmp = getBlock(i, j);

                        if (result.blocks.size() == 0) {
                            result = tmp;
                        } else {
                            if (isBigBlock(result, tmp))
                                result = tmp;
                        }
                    }
                }
            }
        }
        return result;
    }

    static void gravity() {
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == -2 || board[i][j] == -1)
                    continue;

                int color = board[i][j];
                int nx = i + 1;
                while (true) {
                    if (nx == N)
                        break;
                    if (board[nx][j] != -2) {
                        break;
                    }
                    nx++;
                }
                nx--;
                board[i][j] = -2;
                board[nx][j] = color;
            }
        }
    }

    static void rotate() {
        int[][] tmpBoard = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmpBoard[i][j] = board[j][N - 1 - i];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = tmpBoard[i][j];
            }
        }
    }

    static void deleteBlock(Block result) {
        List<int[]> blocks = result.blocks;
        for (int i = 0; i < blocks.size(); i++) {
            int x = blocks.get(i)[0];
            int y = blocks.get(i)[1];
            board[x][y] = -2;
        }
        answer += (blocks.size() * blocks.size());
    }

    static boolean isBigBlock(Block a, Block b) {
        if (a.blocks.size() == b.blocks.size()) {
            if (a.rainbowCount == b.rainbowCount) {
                if (a.x == b.x)
                    return a.y < b.y;
                return a.x < b.x;
            }
            return a.rainbowCount < b.rainbowCount;
        }
        return a.blocks.size() < b.blocks.size();
    }

    static boolean isInRange(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    //블록 클래스
    static class Block {
        int x, y, rainbowCount;
        List<int[]> blocks = new ArrayList<>();
    }
}