import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int[][] answer = new int[31][31];
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int len = str.length();

		for (int i = 0; i < len; i++) {
			answer[i][i] = 1;
		}

		for (int i = 0; i < len - 1; i++) {
			if (str.charAt(i) == str.charAt(i + 1))
				answer[i][i + 1] = 3;
			else
				answer[i][i + 1] = 2;
		}

		// 세자리이상인 경우
		for (int k = 3; k <= len; k++) {
			// k가 3인 경우, 0~2 / 1~1
			for (int left = 0; left < len; left++) {
				int right = left + k - 1;
				if (right >= len)
					break;
				if (str.charAt(left) == str.charAt(right))
					answer[left][right] = answer[left + 1][right] + answer[left][right - 1] + 1;
				else
					answer[left][right] = answer[left + 1][right] + answer[left][right - 1]
							- answer[left + 1][right - 1];
			}
		}

		System.out.println(answer[0][len - 1]);
	}
}