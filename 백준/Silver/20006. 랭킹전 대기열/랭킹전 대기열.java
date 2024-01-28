import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws IOException {
        //입력
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<Room> rooms = new ArrayList<Room>();
        A:
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int level = Integer.parseInt(st.nextToken());
            String nickname = st.nextToken();
            for (Room room : rooms) {
                if (room.users.size() == M) {
                    continue;
                }
                if (level >= room.min && level <= room.max) {
                    room.users.add(new User(level, nickname));
                    continue A;
                }
            }
            Room room = new Room();
            room.min = level - 10;
            room.max = level + 10;
            room.users.add(new User(level, nickname));
            rooms.add(room);
        }

        StringBuilder answer = new StringBuilder();
        for (Room room : rooms) {
            if (room.users.size() == M) {
                answer.append("Started!").append("\n");
            } else {
                answer.append("Waiting!").append("\n");
            }
            room.users.sort((o1, o2) -> {
                return o1.nickname.compareTo(o2.nickname);
            });
            room.users.stream().forEach(
                i -> answer.append(i.level).append(" ").append(i.nickname).append("\n")
            );
        }
        System.out.println(answer);
    }

    static class Room {
        int min, max;
        List<User> users = new ArrayList<>();
    }

    static class User {
        int level;
        String nickname;

        public User(int level, String nickname) {
            this.level = level;
            this.nickname = nickname;
        }
    }
}