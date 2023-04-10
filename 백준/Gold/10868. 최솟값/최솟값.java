import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] arr;
    static int[] tree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1];
        tree = new int[N * 4];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        //세그먼트 트리 생성
        init(1, N, 1);

        StringBuilder sb = new StringBuilder();
        //구간 구하기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            sb.append(getAnswer(1, N, 1, a, b)).append('\n');
        }
        System.out.println(sb);
    }

    static int init(int start, int end, int node) {
        if (start == end) {
            return tree[node] = arr[start];
        }

        int mid = (start + end) / 2;
        return tree[node] = Math.min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
    }

    static int getAnswer(int start, int end, int node, int left, int right) {
        if (left > end || right < start)
            return Integer.MAX_VALUE;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return Math.min(getAnswer(start, mid, node * 2, left, right), getAnswer(mid + 1, end, node * 2 + 1, left, right));
    }
}