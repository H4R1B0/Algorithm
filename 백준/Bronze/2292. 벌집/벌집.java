import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int cnt = 1;
        int sum = 0;
        if(N == 1){
            System.out.println(1);
            return;
        }
        while (true) {
            sum += cnt;
            cnt++;
//            System.out.println("sum = " + sum);
            if(N-1 <= 6*sum){
                break;
            }
        }
        System.out.println(cnt);
    }
}