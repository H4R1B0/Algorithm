import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Point start, end;
        Point[] cannons;
        double[] time;

        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        start = new Point(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        end = new Point(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));

        int n = Integer.parseInt(br.readLine());
        cannons = new Point[n];
        time = new double[n];

        PriorityQueue<Vertex> pq = new PriorityQueue<>(Comparator.comparingDouble(o -> o.time));
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            double a = Double.parseDouble(st.nextToken());
            double b = Double.parseDouble(st.nextToken());
            cannons[i] = new Point(a, b);
            time[i] = getDistance(start, cannons[i]) / 5.0;
            pq.add(new Vertex(i, time[i]));
        }

        //다익스트라
        while (!pq.isEmpty()) {
            Vertex cur = pq.poll();

            if (time[cur.idx] > cur.time) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (i == cur.idx) {
                    continue;
                }

                double nextTime = cur.time + Math.min(2.0 + Math.abs(50.0 - getDistance(cannons[cur.idx], cannons[i])) / 5.0, getDistance(cannons[cur.idx], cannons[i]) / 5.0);
                if (time[i] > nextTime) {
                    time[i] = nextTime;
                    pq.add(new Vertex(i, nextTime));
                }
            }
        }

        double answer = getDistance(start, end) / 5.0;
        for (int i = 0; i < n; i++) {
            double tmp = time[i] + Math.min(2.0 + Math.abs(50.0 - getDistance(end, cannons[i])) / 5.0, getDistance(end, cannons[i]) / 5.0);
            answer = Math.min(answer, tmp);
        }
        System.out.printf("%.6f", answer);
    }

    private static double getDistance(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    static class Point {
        double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Vertex {
        int idx;
        double time;

        public Vertex(int idx, double time) {
            this.idx = idx;
            this.time = time;
        }
    }
}