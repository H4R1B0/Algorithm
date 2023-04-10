import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] arr;
    static Tree[] trees;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1];
        trees = new Tree[N * 4];
        for (int i = 0; i < trees.length; i++) {
            trees[i] = new Tree();
        }
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        //세그먼트 트리 생성
        init(1, N, 1);
//        for (int i = 1; i < 40; i++) {
//            System.out.println(i + " " + trees[i].min + " " + trees[i].max);
//        }

        StringBuilder sb = new StringBuilder();
        //구간 구하기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            Tree answer = getAnswer(1, N, 1, a, b);
            sb.append(answer.min).append(" ").append(answer.max).append('\n');
        }
        System.out.println(sb);
    }

    static Tree init(int start, int end, int node) {
        if (start == end) {
            trees[node].max = Math.max(trees[node].max, arr[start]);
            trees[node].min = Math.min(trees[node].min, arr[start]);
            return trees[node];
        }

        int mid = (start + end) / 2;
        Tree first = init(start, mid, node * 2);
        Tree second = init(mid + 1, end, node * 2 + 1);
        return trees[node] = new Tree(Math.min(first.min, second.min), Math.max(first.max, second.max));
    }

    static Tree getAnswer(int start, int end, int node, int left, int right) {
        if (left > end || right < start)
            return new Tree();
        if (left <= start && end <= right)
            return trees[node];
        int mid = (start + end) / 2;
        Tree first = getAnswer(start, mid, node * 2, left, right);
        Tree second = getAnswer(mid + 1, end, node * 2 + 1, left, right);
        return new Tree(Math.min(first.min, second.min), Math.max(first.max, second.max));
    }

    static class Tree {
        int min, max;

        public Tree() {
            this.min = Integer.MAX_VALUE;
            this.max = -1;
        }

        public Tree(int min, int max) {
            this.min = min;
            this.max = max;
        }
    }
}