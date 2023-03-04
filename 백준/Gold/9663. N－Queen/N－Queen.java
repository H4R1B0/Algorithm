import java.util.Scanner;

class Main {
    static int[] positions;
    static boolean[] visit;
    static int answer;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        positions = new int[N];
        visit = new boolean[N];
        dfs(0, N);
        System.out.println(answer);
    }

    static void dfs(int cnt, final int N) {
        if (cnt == N) {
            answer++;
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!visit[i]) {
                positions[cnt] = i;

                if (isValid(cnt)) {
                    visit[i] = true;
                    dfs(cnt + 1, N);
                    visit[i] = false;
                }
            }
        }
    }

    static boolean isValid(final int cnt) {
        for (int i = 0; i < cnt; i++) {
            if (positions[i] == positions[cnt] || cnt - i == Math.abs(positions[cnt] - positions[i])) {
                return false;
            }
        }
        return true;
    }
}