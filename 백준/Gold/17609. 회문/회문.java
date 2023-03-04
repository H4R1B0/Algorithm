import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            System.out.println(isPalindrome(0, str.length() - 1, 0, str));
        }
    }

    static int isPalindrome(int left, int right, int cnt, String str) {
        while (left < right) {
            if (str.charAt(left) == str.charAt(right)) {
                left++;
                right--;
            } else {
                if (cnt == 0) {
                    if (isPalindrome(left + 1, right, cnt + 1, str) == 0 || isPalindrome(left, right - 1, cnt + 1, str) == 0)
                        return 1;
                    return 2;
                }
                return 2;
            }
        }
        return 0;
    }
}