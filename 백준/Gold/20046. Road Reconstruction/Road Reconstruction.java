import java.io.*;
import java.util.*;

public class Main {
    static class XY implements Comparable<XY>{
        int x;
        int y;
        int cnt;

        public XY(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(XY o){
            return this.cnt - o.cnt;
        }
    }

    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};

    static int n;
    static int m;
    static boolean visited[][];
    static int map[][];

    static int BFS(){
        PriorityQueue<XY> queue = new PriorityQueue<>();
        queue.add(new XY(0,0,map[0][0]));
        if (map[0][0] == -1) return -1;
        while (!queue.isEmpty()){
            XY now = queue.poll();

            if (now.x == n - 1 && now.y == m - 1){
                return now.cnt;
            }

            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nexty<0|| nextx>=n || nexty>=m) continue;
                if (map[nextx][nexty] == -1) continue;
                if (visited[nextx][nexty]) continue;

                visited[nextx][nexty] = true;
                queue.add(new XY(nextx,nexty,now.cnt + map[nextx][nexty]));
            }
        }
        return -1;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        visited = new boolean[n][m];
        map = new int[n][m];

        for (int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ans = BFS();
        System.out.println(ans);
    }
}