import java.io.*;
import java.util.*;
public class Main {
    static class Player implements Comparable<Player>{
        int level;
        String name;

        public Player(int level, String name){
            this.level = level;
            this.name = name;
        }

        @Override
        public int compareTo(Player o){
            return this.name.compareTo(o.name);
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int p = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Player> list[] = new ArrayList[p];

        for (int i = 0;i<p;i++) list[i] = new ArrayList<>();

        for (int i = 0;i<p;i++){
            st = new StringTokenizer(br.readLine());

            int level = Integer.parseInt(st.nextToken());
            String name = st.nextToken();

            for (int j = 0;j<p;j++){
                if (list[j].size() < m && (list[j].isEmpty() || (level >= list[j].get(0).level - 10 && level <= list[j].get(0).level + 10))){
                    list[j].add(new Player(level,name));
                    break;
                }
            }
        }

        for (int i = 0;i<p;i++){
            if (!list[i].isEmpty()){
                Collections.sort(list[i]);
                if (list[i].size() == m){
                    System.out.println("Started!");
                    for (Player player : list[i]){
                        System.out.println(player.level + " " + player.name);
                    }
                }
                else {
                    System.out.println("Waiting!");
                    for (Player player : list[i]){
                        System.out.println(player.level + " " + player.name);
                    }
                }
            }
            else break;
        }

    }
}