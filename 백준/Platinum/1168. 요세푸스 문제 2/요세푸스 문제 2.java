import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, K;
    static int[] node = new int[1 << 18];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        init(1, 1, N);

        StringBuilder answer = new StringBuilder();
        answer.append("<");
        int index = 1;
        for (int i = 0; i < N; i++) {
            int population = N - i;
            index = (index + K - 1) % population;
            if (index == 0)
                index = population;

            int num = getNum(1, 1, N, index);

            delete(1, 1, N, num);

            answer.append(num).append(", ");
        }
        answer.delete(answer.length() - 2, answer.length());
        answer.append(">");
        System.out.println(answer);
    }

    static int init(int cur, int left, int right) {
        if (left == right)
            return node[cur] = 1;
        int mid = (left + right) / 2;
        return node[cur] = init(cur * 2, left, mid) + init(cur * 2 + 1, mid + 1, right);
    }

    static int getNum(int cur, int left, int right, int index) {
        if (left == right)
            return left;
        int mid = (left + right) / 2;
        if (index <= node[cur * 2])
            return getNum(cur * 2, left, mid, index);
        return getNum(cur * 2 + 1, mid + 1, right, index - node[cur * 2]);
    }

    static int delete(int cur, int left, int right, int index) {
        node[cur]--;
        if (left == right)
            return 0;
        int mid = (left + right) / 2;
        if (index <= mid)
            return delete(cur * 2, left, mid, index);
        return delete(cur * 2 + 1, mid + 1, right, index);
    }
}