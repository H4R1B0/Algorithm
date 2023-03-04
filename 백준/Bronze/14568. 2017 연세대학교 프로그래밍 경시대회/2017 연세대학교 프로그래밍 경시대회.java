import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        //택희, 영훈, 남규
        //A  ,  B  , C
        //C = B + 2개 이상
        //모두 최소 한개 이상
        //A 짝수
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int cnt = 0;
        for (int A = 2; N - A >= 4; A += 2) {
            int BC = N - A;
            for (int C = 1; BC - C * 2 >= 2; C++) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}