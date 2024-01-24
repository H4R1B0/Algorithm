import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[][] board = new char[N][N];
        for (int i = 0; i < N; i++) {
            board[i] = br.readLine().toCharArray();
        }
        int[] heart = new int[2];
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (board[i][j] == '*' && board[i - 1][j] == '*' && board[i][j - 1] == '*' && board[i + 1][j] == '*' && board[i][j + 1] == '*') {
                    heart[0] = i;
                    heart[1] = j;
                }
            }
        }

        int[] answer = new int[5];
        for (int i = heart[1] - 1; i >= 0; i--) {
            if (board[heart[0]][i] == '_') {
                break;
            }
            answer[0]++;
        }
        for (int i = heart[1] + 1; i < N; i++) {
            if (board[heart[0]][i] == '_') {
                break;
            }
            answer[1]++;
        }
        for (int i = heart[0] + 1; i < N; i++) {
            if (board[i][heart[1]] == '_') {
                break;
            }
            answer[2]++;
        }
        for (int i = heart[0] + answer[2] + 1; i < N; i++) {
            if (board[i][heart[1] - 1] == '_') {
                break;
            }
            answer[3]++;
        }
        for (int i = heart[0] + answer[2] + 1; i < N; i++) {
            if (board[i][heart[1] + 1] == '_') {
                break;
            }
            answer[4]++;
        }
        System.out.println((heart[0] + 1) + " " + (heart[1] + 1));
        System.out.println(Arrays.stream(answer).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
    }
}