import java.io.*;
import java.util.*;


public class Main {
    static class XY{
        int x;
        int y;

        public XY(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};

    static int map[][];
    static boolean visited[][];
    static int n;
    static int m;
    static int wallCount;
    static int ans = 0;
    static void Wall(){
        if (wallCount == 3){
            BFS();
            return;
        }
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (map[i][j] != 1 && map[i][j] != 2){
                    map[i][j] = 1;
                    wallCount++;
                    Wall();
                    map[i][j] = 0;
                    wallCount--;
                }
            }
        }
    }
    static void BFS(){
        Queue<XY> queue = new LinkedList<>();
        visited = new boolean[n][m];

        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (map[i][j] == 2) queue.add(new XY(i,j));
            }
        }
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for (int i = 0;i<4;i++){
                int nextx = next_x[i] + now.x;
                int nexty = next_y[i] + now.y;

                if (nextx < 0 || nexty<0 || nextx>=n|| nexty>=m) continue;
                if(visited[nextx][nexty]) continue;
                if (map[nextx][nexty] == 1 || map[nextx][nexty] == 2) continue;

                visited[nextx][nexty] = true;
                queue.add(new XY(nextx,nexty));
            }
        }
        int count = 0;
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (map[i][j] == 0 && !visited[i][j]) count++;
            }
        }
        ans = Math.max(ans, count);
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0;j<m;j++){
                int k = Integer.parseInt(st.nextToken());
                map[i][j] = k;

            }
        }

        Wall();
        System.out.println(ans);


    }
}