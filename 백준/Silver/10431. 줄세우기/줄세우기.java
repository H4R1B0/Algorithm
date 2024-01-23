import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int P = Integer.parseInt(br.readLine());
        int[] nums = new int[20];
        StringBuilder answer = new StringBuilder();
        for (int p = 1; p <= P; p++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            for (int i = 0; i < 20; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }
            int total = 0;
            for(int i=0;i<19;i++){
                for(int j=i+1;j<20;j++){
                    if(nums[i] > nums[j]){
                        int tmp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = tmp;
                        total++;
                    }
                }
            }
            answer.append(p).append(' ').append(total).append('\n');
        }
        System.out.println(answer);
    }
}