import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] startPos = new int[]{Integer.MAX_VALUE, Integer.MAX_VALUE};
        int startIdx = 0;
        List<int[]> arr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (startPos[0] > x && startPos[1] > y) {
                startPos[0] = x;
                startPos[1] = y;
                startIdx = i;
            }
            arr.add(new int[]{x, y});
        }

        //가장 작은 좌표를 기준으로 정렬
        arr.addAll(arr.subList(0, startIdx));
        for (int i = 0; i < startIdx; i++)
            arr.remove(0);
        arr.add(arr.get(0));
//        for (int[] a : arr) {
//            System.out.println(Arrays.toString(a));
//        }

        int idx = 1, cnt = 1;
        //x, idx
        List<int[]> mountains = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if ((arr.get(i)[1] < 0 && arr.get(i + 1)[1] > 0) || (arr.get(i)[1] > 0 && arr.get(i + 1)[1] < 0)) {
//            if ((long) arr.get(i)[1] * arr.get(i + 1)[1] < 0) {
//                System.out.println(idx);
                mountains.add(new int[]{arr.get(i)[0], idx});
                cnt++;
                if (cnt % 2 == 1)
                    idx++;
            }
        }
        mountains.sort((o1, o2) -> {
            return o1[0] - o2[0];
        });

        int[] answer = new int[2];
        Stack<Object[]> stack = new Stack<>();
        for (int i = 0; i < mountains.size(); i++) {
            idx = mountains.get(i)[1];

            if (stack.isEmpty()) {
                stack.add(new Object[]{idx, false});
                answer[0]++;
            } else {
                if ((int) stack.peek()[0] == idx) {
                    if (!(boolean) stack.peek()[1]) {
                        answer[1]++;
                    }
                    stack.pop();
                } else {
                    stack.peek()[1] = true;
                    stack.add(new Object[]{idx, false});
                }
            }
        }
        System.out.printf("%d %d", answer[0], answer[1]);
    }
}