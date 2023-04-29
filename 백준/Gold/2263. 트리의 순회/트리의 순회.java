import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] inOrder, postOrder, index;
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        inOrder = new int[N + 1];
        postOrder = new int[N + 1];
        index = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            inOrder[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            postOrder[i] = Integer.parseInt(st.nextToken());
        }
        //인오더의 숫자들의 인덱스 저장
        for (int i = 1; i <= N; i++) {
            index[inOrder[i]] = i;
        }
        preOrder(1,N,1,N);
        System.out.println(answer);
    }

    static void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd)
            return;
        //루트는 프리오더의 맨 끝 숫자
        int root = postOrder[postEnd];
        //루트 숫자의 인덱스
        int idx = index[root];
        int len = idx - inStart;
        answer.append(root).append(" ");
        preOrder(inStart, idx - 1, postStart, postStart + len - 1);
        preOrder(idx + 1, inEnd, postStart + len, postEnd - 1);
    }
}