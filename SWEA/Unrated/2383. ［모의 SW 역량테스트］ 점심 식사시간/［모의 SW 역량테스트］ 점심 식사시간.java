import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * 1. 모든 사람들의 위치 저장
 * 2. 모든 사람들이 문을 선택하는 경우의 수 중복 순열
 * 3. 계단에 먼저 온 순서대로 내려가기 시작함
 * 4. 계단을 이용중인 사람이 이동을 완료하면 대기중인 사람 계단 내려감
 */

class Solution {
    static int N, answer;
    static int[][] board;
    static List<int[]> people;
    static List<int[]> stairs;
    static int[] order;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            answer = Integer.MAX_VALUE;
            people = new ArrayList<>();
            stairs = new ArrayList<>();
            N = Integer.parseInt(br.readLine());
            board = new int[N][N];
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                    if (board[i][j] == 1) {
                        people.add(new int[]{i, j});
                    } else if (board[i][j] > 1) {
                        stairs.add(new int[]{i, j, board[i][j]});
                    }
                }
            }
            order = new int[people.size()];
            select(0);
            System.out.printf("#%d %d\n", test_case, answer);
        }
    }

    static void select(int idx) {
        if (idx == people.size()) {
            getAnswer();
            return;
        }

        for (int i = 0; i < 2; i++) {
            order[idx] = i;
            select(idx + 1);
        }
    }

    static int getDistance(int[] from, int[] to) {
        return Math.abs(from[0] - to[0]) + Math.abs(from[1] - to[1]);
    }

    static boolean isOver(int[][] exits) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (exits[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    static void getAnswer() {
        int[][] exits = new int[2][3];
        //계단에 먼저 도착한 사람들 순서 우선순위 큐
        //거리, idx
        PriorityQueue<Integer>[] pq = new PriorityQueue[2];
        pq[0] = new PriorityQueue<>();
        pq[1] = new PriorityQueue<>();
        for (int i = 0; i < people.size(); i++) {
            pq[order[i]].add(getDistance(people.get(i), stairs.get(order[i])));
        }

        int time = 0, peopleSize = people.size();
        for (time = 0; ; time++) {
            if (peopleSize == 0) {
                if (isOver(exits))
                    break;
            }

            //계단 2개
            for (int i = 0; i < 2; i++) {
                //최대 3명까지 이동
                for (int j = 0; j < 3; j++) {
                    //계단에 사람 있는 경우
                    if (exits[i][j] > 0)
                        exits[i][j]--;

                    //사람 내려감
                    if (exits[i][j] == 0) {
                        //대기중인 사람 있음
                        if (!pq[i].isEmpty() && pq[i].peek() <= time) {
                            //계단 시간 채우기
                            exits[i][j] = stairs.get(i)[2];
                            pq[i].poll();
                            peopleSize--;
                        }
                    }
                }
            }
        }
        answer = Math.min(answer, time);
    }
}