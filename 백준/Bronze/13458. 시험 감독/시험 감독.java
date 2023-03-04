import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] students = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        String[] tmp = br.readLine().split(" ");
        int B = Integer.parseInt(tmp[0]);
        int C = Integer.parseInt(tmp[1]);
        System.out.println(getAnswer(students, B, C));
    }

    private static long getAnswer(int[] students, int B, int C) {
        long sum = 0;
        for (int i = 0; i < students.length; i++) {
            if (students[i] >= B)
                sum += (students[i] - B + C - 1) / C;
            sum++;
        }
        return sum;
    }
}