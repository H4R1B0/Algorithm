import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int N, M, A, C, G, T;
    static char[] arr;
    static boolean[] isSelected;
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
//        System.out.println(tmp[0]);
        N = Integer.parseInt(tmp[0]);
        M = Integer.parseInt(tmp[1]);
        String str = br.readLine();
        arr = str.toCharArray();
        isSelected = new boolean[arr.length];
        tmp = br.readLine().split(" ");
        A = Integer.parseInt(tmp[0]);
        C = Integer.parseInt(tmp[1]);
        G = Integer.parseInt(tmp[2]);
        T = Integer.parseInt(tmp[3]);
        int cntA =0, cntC=0, cntG=0, cntT=0;
        for(int i=0;i<M-1;i++){
            if(arr[i] == 'A')
                cntA++;
            if(arr[i] == 'C')
                cntC++;
            if(arr[i] == 'G')
                cntG++;
            if(arr[i] == 'T')
                cntT++;
//            System.out.println(str.substring(i,i+M));
        }
        for(int i=0;i<=N-M;i++){
            if(arr[i+M-1] == 'A')
                cntA++;
            if(arr[i+M-1] == 'C')
                cntC++;
            if(arr[i+M-1] == 'G')
                cntG++;
            if(arr[i+M-1] == 'T')
                cntT++;

            if(cntA>=A&&cntC>=C&&cntG>=G&&cntT>=T){
                answer++;
            }
            if(arr[i] == 'A')
                cntA--;
            if(arr[i] == 'C')
                cntC--;
            if(arr[i] == 'G')
                cntG--;
            if(arr[i] == 'T')
                cntT--;
        }

        System.out.println(answer);
    }
}