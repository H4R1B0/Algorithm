import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = null;
        tmp = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int L = Integer.parseInt(tmp[1]);
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(arr);
        for(int i=0;i<arr.length;i++){
            if(arr[i] >L)
                break;
            if(arr[i] <= L){
                L+=1;
            }
        }
        System.out.println(L);
    }
}