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
    static int next_x[] = {1,-1,0,0,1,-1,1,-1};
    static int next_y[] = {0,0,1,-1,1,-1,-1,1};
    static int n;
    static int m;
    static int map[][];
    static boolean visited[][];

    static boolean BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        visited[start.x][start.y] = true;
        boolean isCheck = false;
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for (int i = 0;i<8;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx <0 || nexty<0|| nextx>=n || nexty>=m) continue;
                if (map[nextx][nexty] > map[start.x][start.y]) isCheck = true;
                if (visited[nextx][nexty]) continue;
                if (map[nextx][nexty] == map[start.x][start.y]){
                    visited[nextx][nexty] = true;
                    queue.add(new XY(nextx,nexty));
                }
            }
        }
        if (isCheck || map[start.x][start.y] == 0) return false;
        else return true;
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
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = 0;

        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (visited[i][j]) continue;
                if (BFS(new XY(i,j))){
                    ans++;
                }
            }
        }
        System.out.println(ans);



    }
}