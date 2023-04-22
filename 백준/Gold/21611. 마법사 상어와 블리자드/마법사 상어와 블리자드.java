import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    static int N;
    static int[][] board;
    static int[] xd = {1, 0, -1, 0};
    static int[] yd = {0, 1, 0, -1};
    static int[] arr = new int[4];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        board = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int d = getDir(Integer.parseInt(st.nextToken()));
            int s = Integer.parseInt(st.nextToken());
            //구슬 파괴
            breakMarble(d, s);
            //구슬 모두 문자열로 가져오기
            String numbers = getMarble();
            //구슬 폭발과 앞으로 당기기 반복
            numbers = boomMarble(numbers);
//            System.out.println(numbers);
            //구슬 변화
            numbers = changeMarble(numbers);
            //변화된 구슬 다시 맵에 저장
            moveMarble(numbers);

        }
        System.out.println(arr[1] + arr[2] * 2 + arr[3] * 3);
    }

    static String getMarble() {
        int x = (N + 1) / 2;
        int y = (N + 1) / 2 - 1;
        //숫자들만 저장되는 스트링빌더
        StringBuilder sb = new StringBuilder();
        int cnt = 1;
        int move = 0;
        int dist = 1;
        int dir = 0;

        while (true) {
            //마지막 N만큼 움직였다면 끝
            if (dist == N && cnt == 1)
                break;
            //0이 아닌 숫자들만 저장
            if (board[x][y] != 0)
                sb.append(board[x][y]);
            x += xd[dir];
            y += yd[dir];
            move++;
            //움직인 거리와 움직여야하는 거리가 같은 경우
            if (move == dist) {
                cnt++;
            }

            //두번 dist만큼 움직인 경우 초기화
            if (cnt == 2) {
                dist++;
                move = 0;
                dir = (dir + 1) % 4;
                cnt = 0;
            }

            //움직여야하는 만큼 움직인 경우 방향 바꿈
            if (move == dist) {
                dir = (dir + 1) % 4;
                move = 0;
            }
        }
        return sb.toString();
    }

    static String boomMarble(String numbers) {
        //4개 이상의 구슬 찾기 위한 정규식
        String regex = "(.)\\1{3,}";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(numbers);

        //4개 이상으로 연속된 숫자가 문자열안에 있다면
        while (numbers.matches(".*" + regex + ".*")) {
            //모두 찾아서 카운팅
            while (matcher.find()) {
                String str = matcher.group();
                //폭발하는 숫자만큼 증가
                countMarble(str);
            }
            //찾은 구슬들 지우기
            numbers = numbers.replaceAll(regex, "");
            matcher = pattern.matcher(numbers);
        }
        return numbers;
    }

    //구슬 카운팅
    static void countMarble(String str) {
        int num = str.charAt(0) - '0';
        arr[num] += str.length();
    }

    //해당 방향으로 개수만큼 파괴
    static void breakMarble(int d, int s) {
        int x = (N + 1) / 2;
        int y = (N + 1) / 2;
        for (int i = 0; i < s; i++) {
            x += xd[d];
            y += yd[d];
            if (isInRange(x, y))
                board[x][y] = 0;
        }
    }

    //구슬 변화
    private static String changeMarble(String numbers) {
        StringBuilder sb = new StringBuilder();
        //1개 이상의 구슬 찾기 위한 정규식
        String regex = "(.)\\1{0,}";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(numbers);
        while (matcher.find()) {
            String str = matcher.group();
            sb.append(str.length()).append(str.charAt(0));
        }
        return sb.toString();
    }

    //이동한 구슬 맵에 저장
    static void moveMarble(String numbers) {
        board = new int[N + 1][N + 1];
        int x = (N + 1) / 2;
        int y = (N + 1) / 2 - 1;
        int cnt = 1;
        int move = 0;
        int dist = 1;
        int dir = 0;
        int idx = 0;
        while (idx < numbers.length()) {
            board[x][y] = numbers.charAt(idx++) - '0';
            //마지막 (1, 1)까지 움직였다면 끝
            if (x == 1 && y == 1) {
                break;
            }
            x += xd[dir];
            y += yd[dir];
            move++;
            //움직인 거리와 움직여야하는 거리가 같은 경우
            if (move == dist) {
                cnt++;
            }

            //두번 dist만큼 움직인 경우 초기화
            if (cnt == 2) {
                dist++;
                move = 0;
                dir = (dir + 1) % 4;
                cnt = 0;
            }

            //움직여야하는 만큼 움직인 경우 방향 바꿈
            if (move == dist) {
                dir = (dir + 1) % 4;
                move = 0;
            }
        }
    }

    //입력된 방향에 해당하는 인덱스
    static int getDir(int d) {
        if (d == 1)
            return 2;
        if (d == 2)
            return 0;
        if (d == 3)
            return 3;
        return 1;
    }

    static boolean isInRange(int x, int y) {
        return x >= 1 && x <= N && y >= 1 && y <= N;
    }
}