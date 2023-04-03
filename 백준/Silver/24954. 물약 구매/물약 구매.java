import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<Integer> order = new ArrayList<Integer>();
    static int N, answer;
    static int[] costs;
    static List<List<int[]>> sales;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        costs = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        sales = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int M = Integer.parseInt(br.readLine());
            List<int[]> sale = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                int[] saleInfo = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                sale.add(saleInfo);
            }
            sales.add(sale);
        }
        answer = Integer.MAX_VALUE;
        permutation(0);
        System.out.println(answer);
    }

    static void permutation(int cnt) {
        if (cnt == N) {
            getAnswer();
            return;
        }
        for (int i = 0; i < N; i++) {
            if (!order.contains(i)) {
                order.add(i);
                permutation(cnt + 1);
                order.remove(order.size() - 1);
            }
        }
    }

    static void getAnswer() {
        int[] tmpCosts = costs.clone();
        int price = 0;
        for (int j = 0; j < N; j++) {
            price += tmpCosts[order.get(j)];
            List<int[]> sale = sales.get(order.get(j));
            for (int k = 0; k < sale.size(); k++) {
                int[] saleInfo = sale.get(k);
                int index = saleInfo[0] - 1;
                int discount = saleInfo[1];
                tmpCosts[index] = Math.max(1, tmpCosts[index] - discount);
            }
        }
        answer = Math.min(answer, price);
    }
}