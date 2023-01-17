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

    static int n;
    static int m;
    static int map[][];
    static boolean visited[][];

    static void BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        map[start.x][start.y] = 0;
        visited[start.x][start.y] = true;
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nextx>=n||nexty<0||nexty>=m) continue;
                if (visited[nextx][nexty]) continue;
                if (map[nextx][nexty] == 0) continue;

                map[nextx][nexty] = map[now.x][now.y] + 1;
                visited[nextx][nexty] = true;

                queue.add(new XY(nextx,nexty));
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
            st = new StringTokenizer(br.readLine());
            for (int j = 0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 2) start = new XY(i,j);
            }
        }
        BFS(start);
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (!visited[i][j] && map[i][j] != 0) System.out.print(-1 + " ");
                else System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }
}