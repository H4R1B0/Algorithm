import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
	static int[] xd = { 0, 0, 1, -1 };
	static int[] yd = { 1, -1, 0, 0 };
	static int[][] board;
	static int[][] dist;
	static int[][] tmpDist;
	static int N;
	static int posLen;
	static int[] order;
	static Pos[] positions;
	static int answer = 987654321;
	static Pos home;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		board = new int[N][N];

		ArrayList<Pos> tmp = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) {
					tmp.add(new Pos(i, j));
				}
				if (board[i][j] == -1) {
					home = new Pos(i, j);
				}
			}
		}
		tmp.add(home); // posiotions에 집 추가
		board[home.x][home.y] = 0;
		positions = tmp.toArray(new Pos[tmp.size()]);
		posLen = positions.length;
		tmpDist = new int[N][N];
		dist = new int[posLen][posLen];
		order = new int[posLen - 1];
		Arrays.fill(order, -1);
		allPosDijkstra();
		if (posLen == 1) {
			System.out.println(0);
			return;
		}
		permutation(0);
		System.out.println(answer);
	}

	private static void dijkstra(int start, int end) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tmpDist[i][j] = 987654321;
			}
		}
		PriorityQueue<Move> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
		pq.add(new Move(positions[start].x, positions[start].y, 0));
		tmpDist[positions[start].x][positions[start].y] = 0;

		while (!pq.isEmpty()) {
			Move cur = pq.poll();

			if (tmpDist[cur.x][cur.y] < cur.cost)
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + xd[i];
				int ny = cur.y + yd[i];
				int nCost = cur.cost;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (tmpDist[nx][ny] > nCost + board[nx][ny]) {
						tmpDist[nx][ny] = nCost + board[nx][ny];
						pq.add(new Move(nx, ny, tmpDist[nx][ny]));
					}
				}
			}
		}

		dist[start][end] = tmpDist[positions[end].x][positions[end].y];
	}

	private static void allPosDijkstra() {
		for (int i = 0; i < posLen; i++) {
			for (int j = 0; j < posLen; j++) {
				if (i == j)
					continue;
				dijkstra(i, j);
			}
		}
	}

	private static void permutation(int idx) {
		if (idx == posLen - 1) {
//			System.out.println(Arrays.toString(order));
			int sum = 0;
			if(posLen == 2) {
				sum += dist[1][0];
				sum += dist[0][1];
			}
			else {
				sum += dist[posLen - 1][order[0]];
				for (int i = 0; i < posLen - 2; i++) {
					sum += dist[order[i]][order[i + 1]];
				}
				sum += dist[order[posLen - 2]][posLen - 1];
			}

			answer = Math.min(answer, sum);
			return;
		}

		// 해당 자리에 뽑을 가능한 모든 수에 대해 시도
		for (int i = 0; i < posLen - 1; i++) {
			if (order[i] == -1) {
				order[i] = idx;
				permutation(idx + 1);
				order[i] = -1;
			}
		}
	}

	static class Move {
		int x, y, cost;

		Move(int x, int y, int cost) {
			this.x = x;
			this.y = y;
			this.cost = cost;
		}
	}

	static class Pos {
		int x, y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}