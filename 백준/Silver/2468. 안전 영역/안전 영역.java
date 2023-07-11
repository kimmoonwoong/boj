import java.util.*;
import java.io.*;
public class Main {
    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};
    static class XY{
        int x;
        int y;

        public XY(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    static int n;
    static int map[][];
    static boolean visited[][];

    static void BFS(XY start, int k){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        visited[start.x][start.y] = true;

        while (!queue.isEmpty()){
            XY now = queue.poll();

            for(int i = 0;i<4;i++){
                int nextx = next_x[i] + now.x;
                int nexty = next_y[i] + now.y;

                if(nextx < 0 || nexty < 0 || nextx>=n || nexty >= n) continue;
                if(visited[nextx][nexty]) continue;
                if(k >= map[nextx][nexty]) continue;

                visited[nextx][nexty] = true;
                queue.add(new XY(nextx,nexty));
            }
        }
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        int max = 0;
        map = new int[n][n];
        visited = new boolean[n][n];
        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                max = Math.max(map[i][j], max);
            }
        }
        int ans = 1;
        for(int k = 1;k<=max;k++){
            int prev = 0;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(map[i][j] <=  k) continue;
                    if(visited[i][j]) continue;

                    BFS(new XY(i, j), k);
                    prev++;
                }
            }
            visited = new boolean[n][n];
            ans = Math.max(prev, ans);
        }
        System.out.println(ans);


    }
}