import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static char[][] board = new char[3][3];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder answer = new StringBuilder();
        while (true) {
            String line = br.readLine();
            if (line.equals("end")) {
                System.out.println(answer);
                break;
            }
            answer.append(getAnswer(line)).append('\n');
        }
    }

    static String getAnswer(String line) {
        int xCnt = 0, oCnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = line.charAt(3 * i + j);
                if (board[i][j] == 'X') {
                    xCnt++;
                } else if (board[i][j] == 'O') {
                    oCnt++;
                }
            }
        }
        boolean xWin = false, oWin = false;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                xWin = true;
            }
            if (board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                oWin = true;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == 'X' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                xWin = true;
            }
            if (board[0][i] == 'O' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                oWin = true;
            }
        }
        if (board[0][0] == 'X' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            xWin = true;
        }
        if (board[0][2] == 'X' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            xWin = true;
        }
        if (board[0][0] == 'O' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            oWin = true;
        }
        if (board[0][2] == 'O' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            oWin = true;
        }
        if (xWin && !oWin && xCnt - oCnt == 1) {
            return "valid";
        }
        if (!xWin && oWin && xCnt - oCnt == 0) {
            return "valid";
        }
        if (!xWin && !oWin && xCnt == 5 && oCnt == 4) {
            return "valid";
        }
        return "invalid";
    }
}