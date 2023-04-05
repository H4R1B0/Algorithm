import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N, D, K, C;
    static int[] plates;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        plates = new int[N];
        for (int i = 0; i < N; i++) {
            plates[i] = Integer.parseInt(br.readLine());
        }
        System.out.println(getAnswer());
    }

    static int getAnswer() {
        int answer = 0;
        Deque<Integer> dq = new ArrayDeque<>();
        int[] counts = new int[D + 1];

        //정답 초기 세팅
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            int num = plates[i];
            dq.addLast(num);
            if (counts[num] == 0) {
                cnt++;
            }
            counts[num]++;
        }
//        System.out.println(dq);
        if (counts[C] == 0)
            answer = cnt+1;
        else
            answer = cnt;

        int addIdx = K;
        for (int i = 0; i < N - 1; i++) {
//            System.out.println(cnt);
            int first = dq.pollFirst();
            counts[first]--;
            if (counts[first] == 0) {
                cnt--;
            }

            int num = plates[(K+i)%N];
            dq.addLast(num);
            if (counts[num] == 0) {
                cnt++;
            }
            counts[num]++;
            if (counts[C] == 0)
                answer = Math.max(answer, cnt+1);
            else
                answer = Math.max(answer, cnt);
//            System.out.println(dq);
            answer = Math.max(answer, cnt);
        }
        return answer;
    }
}