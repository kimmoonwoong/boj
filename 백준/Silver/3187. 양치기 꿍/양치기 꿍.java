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

    static char map[][];
    static boolean visited[][];

    static int W_count;
    static int S_count;

    static void BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        int w_count = 0;
        int s_count = 0;
        if (map[start.x][start.y] == 'v') w_count++;
        else if (map[start.x][start.y] == 'k') s_count++;
        visited[start.x][start.y] = true;
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nexty < 0 || nextx>=n || nexty>=m) continue;
                if (visited[nextx][nexty]) continue;
                if (map[nextx][nexty] == '#') continue;

                if (map[nextx][nexty] == 'v') w_count++;
                else if (map[nextx][nexty] == 'k') s_count++;

                visited[nextx][nexty] = true;
                queue.add(new XY(nextx,nexty));
            }
        }
        if (w_count >= s_count) W_count+=w_count;
        else S_count += s_count;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new boolean[n][m];

        for (int i = 0;i<n;i++){
            String s = br.readLine();
            for (int j = 0;j<m;j++){
                map[i][j] = s.charAt(j);
            }
        }

        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (visited[i][j] || map[i][j] == '#') continue;

                BFS(new XY(i,j));
            }
        }
        System.out.println(S_count + " " + W_count);
    }
}