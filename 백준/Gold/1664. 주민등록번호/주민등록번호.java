import java.io.*;
import java.util.*;

public class Main {
    static List<Integer> days = new ArrayList<>();
    static List<Integer> months = new ArrayList<>();
    static List<Integer> years = new ArrayList<>();
    static int[] ends = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int[][] mod = new int[2][19];
    static long[] dp = new long[10];

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] number = br.readLine().toCharArray();

        //day
        for (int d = 1; d <= 31; d++) {
            if ((number[0] == 'X' || number[0] == '0' + d / 10) && (number[1] == 'X' || number[1] == '0' + d % 10)) {
                days.add(d);
            }
        }
        //month
        for (int m = 1; m <= 12; m++) {
            if ((number[2] == 'X' || number[2] == '0' + m / 10) && (number[3] == 'X' || number[3] == '0' + m % 10)) {
                months.add(m);
            }
        }
        //year
        for (int a = 0; a < 10; a++) {
            if (number[4] == 'X' || number[4] == '0' + a) {
                for (int b = 0; b < 10; b++) {
                    if (number[5] == 'X' || number[5] == '0' + b) {
                        for (int c = 0; c < 10; c++) {
                            if (number[6] == 'X' || number[6] == '0' + c) {
                                for (int d = 0; d < 10; d++) {
                                    if (number[7] == 'X' || number[7] == '0' + d) {
                                        if (a + b + c + d != 0) {
                                            years.add(a * 1000 + b * 100 + c * 10 + d);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //DDMMYYYY
        for (int y = 0; y < years.size(); y++) {
            for (int m = 0; m < months.size(); m++) {
                int end = getEnd(months.get(m), years.get(y));
                for (int d = 0; d < days.size() && days.get(d) <= end; d++) {
                    int num = 10 * (days.get(d) / 10) + 9 * (days.get(d) % 10) +
                        8 * (months.get(m) / 10) + 7 * (months.get(m) % 10) +
                        6 * (years.get(y) / 1000) + 5 * (years.get(y) / 100 % 10) +
                        4 * (years.get(y) / 10 % 10) + 3 * (years.get(y) % 10);
                    mod[0][num % 19]++;
                }
            }
        }

        //AAAAAAAAAA
        int k = 2;
        int[][] c = new int[11][19];
        c[0][0] = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (number[8 + i] == 'X' || number[8 + i] == '0' + j) {
                    for (int m = 0; m < 19; m++) {
                        c[i + 1][(m + k * j) % 19] += c[i][m];
                    }
                }
            }
            if (--k < 2) {
                k = 10;
            }
        }
        mod[1] = c[10];

        long answer = 0;
        for (int l = 0; l < 19; l++) {
            for (int d = 0; d < 19; d++) {
                dp[(l + d) % 19 < 10 ? (l + d) % 19 : 19 - (l + d) % 19] += (long) mod[0][l] * mod[1][d];
                answer += (long) mod[0][l] * mod[1][d];
            }
        }
        if (number[18] == 'X') {
            System.out.println(answer);
        } else {
            System.out.println(dp[number[18] - '0']);
        }
    }

    static int getEnd(int month, int year) {
        if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
            return 29;
        }
        return ends[month - 1];
    }
}