import java.io.*;
import java.util.Arrays;

class Main {
    static int[] dic = new int[1000001];
    static boolean[] used = new boolean[10];

    public static void main(String[] args) throws IOException {
        init();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int num = Integer.parseInt(br.readLine());
            if (num == 0)
                break;
            System.out.println(dic[num]);
        }
    }

    static void init() {
        for (int idx = 1, num = 1; idx <= 1000000; num++) {
            if (!isDistinct(num)) {
                dic[idx++] = num;
            }
        }
    }

    static boolean isDistinct(int num) {
        /*
         * 메모리 초과 전
         * used = new boolean[10];
         * 메모리 초과 해결
         * Arrays.fill(used,false);
         * 반복문 안에서 계속 new로 계속 생성해주다보니 heap메모리에 계속 할당하게 되어 메모리 초과 발생.
         * 그렇기 때문에 new로 새로 할당해주는것이 아닌 배열 전체 초기화.
         * */
        Arrays.fill(used, false);
        while (num != 0) {
            if (used[num % 10]) {
                return true;
            }
            used[num % 10] = true;
            num /= 10;
        }
        return false;
    }
}