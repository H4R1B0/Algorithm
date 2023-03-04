import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int K = Integer.parseInt(tmp[1]);

        List<Integer> arr = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            arr.add(i);
        }
        List<Integer> answer = new ArrayList<>();
        int idx = 0;
        while(answer.size() != N){
            idx = (idx+K-1)%arr.size();
            answer.add(arr.get(idx));
            arr.remove(idx);
        }

        StringBuilder sb = new StringBuilder();
        sb.append('<');
        for(int i=0;i<answer.size()-1;i++){
            sb.append(Integer.toString(answer.get(i))).append(", ");
        }
        sb.append(Integer.toString(answer.get(answer.size()-1))).append('>');
        System.out.println(sb);
    }
}
