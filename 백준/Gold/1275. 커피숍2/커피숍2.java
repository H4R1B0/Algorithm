import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, Q;
    static int[] arr;
    static long[] tree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        arr = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        tree = new long[N * 4];

        //세그먼트 트리 생성
        init(1, N, 1);
        StringBuilder sb = new StringBuilder();
        //명령어
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            long b = Integer.parseInt(st.nextToken());
            if (x <= y)
                sb.append(getSum(1, N, 1, x, y));
            else
                sb.append(getSum(1, N, 1, y, x));
            sb.append('\n');
            long diff = b - arr[a];
            arr[a] = (int) b;
            update(1, N, 1, a, diff);
        }
        System.out.println(sb);
    }

    static long init(int start, int end, int node) {
        if (start == end)
            return tree[node] = arr[start];
        int mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }

    static long getSum(int start, int end, int node, int left, int right) {
        if (end < left || right < start)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
    }

    static void update(int start, int end, int node, int idx, long diff) {
        if (idx < start || idx > end)
            return;
        tree[node] += diff;
        if (start == end)
            return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, diff);
        update(mid + 1, end, node * 2 + 1, idx, diff);
    }
}