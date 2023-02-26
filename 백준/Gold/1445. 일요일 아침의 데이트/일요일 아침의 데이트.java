import java.io.*;
import java.util.*;
public class Main {
    static class XY implements Comparable<XY>{
        int x;
        int y;
        int g;
        int gi;

        public XY(int x, int y, int g, int gi){
            this.x = x;
            this.y =y;
            this.g =g;
            this.gi = gi;
        }

        public int compareTo(XY o){
            if (this.g == o.g) return this.gi - o.gi;
            else return this.g - o.g;
        }
    }

    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};

    static int n;
    static int m;

    static int map[][];
    static boolean visited[][];

    static void BFS(XY start){
        PriorityQueue<XY> queue = new PriorityQueue<>();
        queue.add(start);

        while (!queue.isEmpty()){
            XY now = queue.poll();
            if (map[now.x][now.y] == 3){
                System.out.println(now.g + " " + now.gi);
                break;
            }
            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];
                if (nextx < 0 || nexty<0 || nextx>=n || nexty>=m) continue;
                if (visited[nextx][nexty]) continue;

                if (map[nextx][nexty] == 1){
                    queue.add(new XY(nextx,nexty, now.g + 1, now.gi));
                }
                else if (map[nextx][nexty] == 2){
                    queue.add(new XY(nextx,nexty, now.g, now.gi + 1));
                }
                else{
                    queue.add(new XY(nextx,nexty, now.g, now.gi));
                }
                visited[nextx][nexty] = true;

            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];
        XY start = null;
        for (int i = 0;i<n;i++){
            String s = br.readLine();
            for (int j = 0;j<m;j++){
                if (s.charAt(j) == 'F') map[i][j] = 3;
                else if (s.charAt(j) == 'S'){
                    start = new XY(i,j,0,0);
                    map[i][j] = 4;
                }
                else if (s.charAt(j) == 'g'){
                    map[i][j] = 1;
                    for (int k = 0;k<4;k++){
                        int nextx = i + next_x[k];
                        int nexty = j + next_y[k];

                        if (nextx < 0 || nexty < 0 || nextx>=n || nexty>=m) continue;
                        if (map[nextx][nexty] == 3 || map[nextx][nexty] == 4 || map[nextx][nexty] == 1) continue;
                        map[nextx][nexty] = 2;
                    }
                }
            }
        }
        BFS(start);
    }
}