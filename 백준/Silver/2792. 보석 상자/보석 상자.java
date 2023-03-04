import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int answer = 0, N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[] arr = new int[M];
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < M; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            max = Math.max(max, arr[i]);
        }

        int left = 1, right = max;
        while(left <= right){
            int cnt = 0;
            int mid = (left+right)/2;
            for(int i=0;i<arr.length;i++){
                cnt+=(arr[i]+mid-1)/mid;
            }
            if(cnt > N){
                left = mid+1;
            }
            else{
                answer = mid;
                right = mid-1;
            }
        }
        System.out.println(answer);
    }
}