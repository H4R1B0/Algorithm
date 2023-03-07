import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    static int N, answer = 0;
    static int[][] game;
    static boolean[] isSelect = new boolean[10];
    static int[] order = new int[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        game = new int[N + 1][10];
        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++) {
                game[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        isSelect[4] = true;
        order[4] = 1;
        select(2);
        System.out.println(answer);
    }

    static void select(int cnt) {
        if (cnt == 10) {
//            System.out.println(Arrays.toString(order));
            play();
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (!isSelect[i]) {
                isSelect[i] = true;
                order[i] = cnt;
                select(cnt + 1);
                isSelect[i] = false;
            }
        }
    }

    static void play() {
        int score = 0;
        int playerNum = 1;
        int[] state;
        for (int i = 1; i <= N; i++) {
            int outCnt = 0;
            boolean isNext = false;
            state = new int[4];
            while (true) {
                for (int j = playerNum; j <= 9; j++) {
                    int result = game[i][order[j]];
                    if (result == 0) {
                        outCnt++;
                    } else if (result == 1) {
                        for (int idx = 3; idx >= 1; idx--) {
                            if (state[idx] == 1) {
                                if (idx == 3) {
                                    state[idx] = 0;
                                    score++;
                                } else {
                                    state[idx + 1]++;
                                    state[idx] = 0;
                                }
                            }
                        }
                        state[1] = 1;
                    } else if (result == 2) {
                        for (int idx = 3; idx >= 1; idx--) {
                            if (state[idx] == 1) {
                                if (idx == 3 || idx == 2) {
                                    state[idx] = 0;
                                    score++;
                                } else {
                                    state[idx + 2]++;
                                    state[idx] = 0;
                                }
                            }
                        }
                        state[2] = 1;
                    } else if (result == 3) {
                        for (int idx = 3; idx >= 1; idx--) {
                            if (state[idx] == 1) {
                                state[idx] = 0;
                                score++;
                            }
                        }
                        state[3] = 1;
                    } else {
                        for (int idx = 3; idx >= 1; idx--) {
                            if (state[idx] == 1) {
                                state[idx] = 0;
                                score++;
                            }
                        }
                        score++;
                    }
                    if (outCnt == 3) {
                        playerNum = j + 1;
                        if (playerNum == 10)
                            playerNum = 1;
                        isNext = true;
                        break;
                    }
                }
                if (isNext)
                    break;
                playerNum = 1;
            }
        }
        answer = Math.max(answer, score);
    }
}