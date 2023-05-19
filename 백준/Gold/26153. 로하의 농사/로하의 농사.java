import java.io.*;
import java.util.*;


public class Main {
    static class XY{
        int x;
        int y;
        int vector;
        int cnt;
        int sum;

        public XY(int x, int y, int vector, int cnt, int sum){
            this.x = x;
            this.y = y;
            this.vector = vector;
            this.cnt = cnt;
            this.sum = sum;
        }
    }
    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};
    static int n;
    static int m;

    static int map[][];

    static boolean visited[][];
    static int sum;
    static int start_x;
    static int start_y;

    static void DFS(XY start){
        if(visited[start.x][start.y]) return;
        sum = Math.max(sum, start.sum);
        if(start.cnt == 0){
            return;
        }

        for(int i = 0;i<4;i++){
            int nextx = start.x + next_x[i];
            int nexty = start.y + next_y[i];
            if(nextx < 0 || nexty <0|| nextx>=n|| nexty>=m) continue;
            if(nextx == start_x && nexty == start_y) continue;
            visited[start.x][start.y] = true;
            if(start.vector!=-1 && start.vector != i){
                if(start.cnt - 2 >= 0) DFS(new XY(nextx,nexty,i,start.cnt - 2, start.sum + map[nextx][nexty]));
            }
            else{
                DFS(new XY(nextx,nexty,i,start.cnt - 1, start.sum + map[nextx][nexty]));
            }
            visited[start.x][start.y] = false;
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];
        for(int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        start_x = Integer.parseInt(st.nextToken());
        start_y = Integer.parseInt(st.nextToken());
        int cnt = Integer.parseInt(st.nextToken());
        sum = map[start_x][start_y];
        DFS(new XY(start_x,start_y,-1,cnt,map[start_x][start_y]));
        System.out.println(sum);
    }
}