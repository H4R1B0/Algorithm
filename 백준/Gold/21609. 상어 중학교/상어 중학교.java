import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class Node{
		int x, y;

		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Node [x=" + x + ", y=" + y + "]";
		}

	}

	static int N, maxCnt, result;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int[][] blocks;
	static Node standard;
	static Queue<Node> queue;
	static Queue<Node> group;
	static Queue<Node> rainbow;
	static boolean[][] visited;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		blocks = new int[N][N];

		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				blocks[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		//1. 블록 그룹 찾기
		//1-1. 검정색 블록, 무지개블록 pass
		while(true) {
			visited = new boolean[N][N];
			maxCnt = -1;
			queue = new ArrayDeque<>();
			group = new ArrayDeque<>();
			rainbow = new ArrayDeque<>();
			standard = new Node(N, N);
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(visited[i][j]) continue;
					if(blocks[i][j] != -1 && blocks[i][j] != 0 && blocks[i][j] != -2) {
						findGroup(i, j);
					}
				}
			}
			if(group.size() < 2) break;

//		System.out.println(group);

			//2. 큐에 저장된 블록 모두 -2로 셋팅
			//2-1. 점수 추가
			result += Math.pow(group.size(), 2);
			for(Node node : group) {
				blocks[node.x][node.y] = -2;
			}

			//3. 중력 작용(완탐 -> 큰 행부터시작)
			//3-1. 아래 행이 비어있으면 옮김(검정색 블록  continue)
			moveBlock();
//			System.out.println("-------");
//			for(int i=0; i<N; i++) {
//				System.out.println(Arrays.toString(blocks[i]));
//			}
//			System.out.println();

			//4. 90도 반시계 이동(배열 하나 만들어서 저장)
			rotate90();

//			for(int i=0; i<N; i++) {
//				System.out.println(Arrays.toString(blocks[i]));
//			}
//			System.out.println();

			//5. (3)중력 작용
			moveBlock();

//			for(int i=0; i<N; i++) {
//				System.out.println(Arrays.toString(blocks[i]));
//			}
//			System.out.println();
//			System.out.println("result "+result);
		}
		System.out.println(result);

		br.close();
	}

	private static void rotate90() {
		int[][] temp = new int[N][N];

		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				temp[N-1-j][i] = blocks[i][j];
			}
		}

		for(int i=0; i<N; i++) {
			blocks[i] = temp[i].clone();
		}

	}

	//3. 중력 작용(완탐 -> 큰 행부터시작)
	//3-1. 아래 행이 비어있으면 옮김(검정색 블록 continue)
	//!!!!!!!!!!!!!!!!!1
	private static void moveBlock() {
		//빈공간, 데이터 있는 공간 찾기
		//1. 빈공간 저장
		//2. 검은 블록 만나면 초기화
		//3. 일반 블록인 경우, 빈 공간에 저장
		Queue<Node> space = new ArrayDeque<>();
		for(int i=0; i<N; i++) {    //열 단위로 보기
			for(int j=N-1; j>=0; j--) {
				if(blocks[j][i] == -2) space.offer(new Node(j, i));
				else if(blocks[j][i] == -1) space.clear();
				else {
					if(!space.isEmpty()) {
						Node node = space.poll();
						blocks[node.x][node.y] = blocks[j][i];
						blocks[j][i] = -2;
						space.offer(new Node(j, i)); //!!!!!!!!!중요, 현재 위치가 빈공간이 되므로
					}
				}
			}
			space.clear();
		}
	}


	//1-2. 일반 블록 : 해당 번호와 0인 경우 상하좌우로 찾음(검정색 블록 or 다른 번호 블록 pass)
	//	기준 블록, 블록 수(무지개블록 수), 블록 정보(큐에 저장)
	//	무지개블록 저장(큐) -> 다음 블록에서 찾을 때, 방문처리 해제
	private static void findGroup(int x, int y) {
		Queue<Node> nQueue = new ArrayDeque<>();
		Queue<Node> nGroup = new ArrayDeque<>();
		Queue<Node> nRainbow = new ArrayDeque<>();
		int blockNum = blocks[x][y];
		Node nStandard = new Node(x, y);

		visited[x][y] = true;
		nQueue.offer(new Node(x, y));
		nGroup.offer(new Node(x, y));

		while(!nQueue.isEmpty()) {
			Node node = nQueue.poll();
			int px = node.x;
			int py = node.y;

			for(int i=0; i<4; i++) {
				int nx = px + dx[i];
				int ny = py + dy[i];

				if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if(visited[nx][ny]) continue;

				//일반 블록의 number가 같은 경우
				if(blocks[nx][ny] == blockNum) {
					if(nx < nStandard.x) nStandard = new Node(nx, ny);
					else if(nx == nStandard.x && ny < nStandard.y) {
						nStandard = new Node(nx, ny);
					}
					nQueue.offer(new Node(nx, ny));
					nGroup.offer(new Node(nx, ny));
					visited[nx][ny] = true;
				} else if(blocks[nx][ny] == 0) {    //무지개 블록인 경우
					nQueue.offer(new Node(nx, ny));
					nGroup.offer(new Node(nx, ny));
					nRainbow.offer(new Node(nx, ny));    //추가
					visited[nx][ny] = true;
				}
			}
		}

		//무지개블록 방문 false처리
		for(Node node : nRainbow) {
			visited[node.x][node.y] = false;
		}

		//https://www.acmicpc.net/board/view/110216
		//블록 그룹 찾기
		if(maxCnt < nGroup.size()) {    //그룹의 크기
			update(nGroup, nRainbow, nStandard);
		} else if(maxCnt == nGroup.size()) {
			if(rainbow.size() < nRainbow.size()) {    //무지개 블록 크기
				update(nGroup, nRainbow, nStandard);
			} else if(rainbow.size() == nRainbow.size()) {
				if(standard.x < nStandard.x) {    //기준 블록 행의 크기
					update(nGroup, nRainbow, nStandard);
				} else if(standard.x == nStandard.x) {
					if(standard.y < nStandard.y) {    //기중 블록 열의 크기
						update(nGroup, nRainbow, nStandard);
					}
				}
			}
		}
	}


	private static void update(Queue<Node> nGroup, Queue<Node> nRainbow, Node nStandard) {
		maxCnt = nGroup.size();
		group = nGroup;
		rainbow = nRainbow;
		standard = nStandard;
	}
}