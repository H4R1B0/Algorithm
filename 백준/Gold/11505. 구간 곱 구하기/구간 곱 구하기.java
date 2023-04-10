import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final long MOD = 1000000007;
    static int N, M, K;
    static long[] arr, tree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new long[N + 1];
        tree = new long[N * 4];

        //숫자 입력
        for (int i = 1; i <= N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        //세그먼트 트리 생성
        init(1, N, 1);

        StringBuilder answer = new StringBuilder();
        //명령어
        for (int i = 0; i < M + K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            if (a == 1) {
                arr[b] = c;
                update(1, N, 1, b, c);
            } else {
                answer.append(getMultiple(1, N, 1, b, (int) c)).append('\n');
            }
        }
        System.out.println(answer);
    }

    static long init(int start, int end, int node) {
        if (start == end)
            return tree[node] = arr[start];
        int mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % MOD;
    }

    static long update(int start, int end, int node, final int idx, final long num) {
        if (idx < start || idx > end)
            return tree[node];
        if (start == end)
            return tree[node] = num;
        int mid = (start + end) / 2;
        return tree[node] = update(start, mid, node * 2, idx, num) * update(mid + 1, end, node * 2 + 1, idx, num) % MOD;
    }

    static long getMultiple(int start, int end, int node, final int left, final int right) {
        if (left > end || right < start)
            return 1;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return getMultiple(start, mid, node * 2, left, right) * getMultiple(mid + 1, end, node * 2 + 1, left, right) % MOD;
    }
}