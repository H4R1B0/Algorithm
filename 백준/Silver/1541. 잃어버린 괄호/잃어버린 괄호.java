import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int idx = 0, subCnt = 0;
        List<Integer> addArr = new ArrayList<>();
        List<Integer> subArr = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
//            System.out.println(str.charAt(i));
            if (str.charAt(i) == '-' || str.charAt(i) == '+') {
                String num = str.substring(idx, i);
//                System.out.println(num);
                if (subCnt == 0) {
                    addArr.add(Integer.parseInt(num));
                } else {
                    subArr.add(Integer.parseInt(num));
                }
                if (str.charAt(i) == '-')
                    subCnt++;
                idx = i+1;
            }
        }
        String num = str.substring(idx);
//        System.out.println(num);
        if (subCnt == 0) {
            addArr.add(Integer.parseInt(num));
        } else {
            subArr.add(Integer.parseInt(num));
        }
        int sum = 0;
        for(int a : addArr)
            sum+=a;
        for(int a : subArr)
            sum-=a;
        System.out.println(sum);
    }
}