import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        char[] arr = br.readLine().toCharArray();
        int answer = 0;
        for(int i=0;i<N;i++){
            if(arr[i] != 'P'){
                continue;
            }

            for(int j=i-K;j<=i+K;j++){
                if(j>=0 && j<N && arr[j]=='H'){
                    arr[j]='.';
                    answer++;
                    break;
                }
            }
        }
        System.out.println(answer);
    }
}