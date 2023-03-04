import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    static List<Integer> posX = new ArrayList<>();
    static List<Integer> posY = new ArrayList<>();
    static List<Pos> positions = new ArrayList<>();
    static int[][] board;
    static int N;
    static int answer = 100000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String[] tmp;
        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            int x = Integer.parseInt(tmp[0]);
            int y = Integer.parseInt(tmp[1]);
            posX.add(x);
            posY.add(y);
            positions.add(new Pos(x, y));
        }

        init();

        getAnswer();

        System.out.println(answer);
    }

    static void init() {
        posX = posX.stream().distinct().sorted().collect(Collectors.toList());
        posX.add(0, 0);
        posY = posY.stream().distinct().sorted().collect(Collectors.toList());
        posY.add(0, 0);
        board = new int[posX.size() + 1][posY.size() + 1];
        for (Pos position : positions) {
            board[posX.indexOf(position.x)][posY.indexOf(position.y)]++;
        }

        for (int i = 1; i < board.length; i++) {
            for (int j = 1; j < board[i].length; j++) {
                board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
            }
        }
    }

    static void getAnswer() {
        for (int i = 1; i < posX.size(); i++) {
            for (int j = 1; j < posY.size(); j++) {
                calculate(i, j);
            }
        }
    }

    static void calculate(int x, int y) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (board[x][y] - board[x][j] - board[i][y] + board[i][j] >= N / 2) {
                    answer = Math.min(answer, (posX.get(x) - posX.get(i + 1) + 2) * (posY.get(y) - posY.get(j + 1) + 2));
                }
            }
        }
    }

    static class Pos {
        int x, y;

        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}