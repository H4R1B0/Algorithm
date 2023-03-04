import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static Deque<Integer> q = new LinkedList<>();
    static StringBuilder answer = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] tmp = null;
        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            if (tmp[0].equals("push")) {
                int num = Integer.parseInt(tmp[1]);
                push(num);
            } else if (tmp[0].equals("size")) {
                size();
            } else if (tmp[0].equals("empty")) {
                empty();
            }
            else if (q.isEmpty()) {
                answer.append(-1).append('\n');
            } else if (tmp[0].equals("front")) {
                front();
            } else if (tmp[0].equals("back")) {
                back();
            } else if (tmp[0].equals("pop")) {
                pop();
            }
        }
        System.out.println(answer);
    }

    static void push(int num) {
        q.add(num);
    }

    static void front() {
        answer.append(q.getFirst()).append('\n');
    }

    static void back() {
        answer.append(q.getLast()).append('\n');
    }

    private static void size() {
        answer.append(q.size()).append('\n');
    }

    private static void empty() {
        if (q.isEmpty())
            answer.append(1).append('\n');
        else
            answer.append(0).append('\n');
    }

    private static void pop() {
        answer.append(q.poll()).append('\n');
    }
}