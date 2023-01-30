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

    static int BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        int cnt = 1;
        queue.add(start);
        visited[start.x][start.y] = true;
        while (!queue.isEmpty()){
            XY now =queue.poll();

            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nexty<0 || nextx>=m || nexty>=n) continue;
                if (visited[nextx][nexty]) continue;
                if (map[nextx][nexty] != map[start.x][start.y]) continue;

                visited[nextx][nexty] = true;
                cnt++;
                queue.add(new XY(nextx,nexty));
            }
        }
        return cnt;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[m][n];
        visited = new boolean[m][n];

        for (int i = 0;i<m;i++){
            String s = br.readLine();
            for (int j = 0;j<n;j++){
                map[i][j] = s.charAt(j);
            }
        }
        int W_cnt = 0;
        int B_cnt = 0;
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                if (!visited[i][j]){
                    if (map[i][j] == 'W'){
                        W_cnt += Math.pow(BFS(new XY(i,j)),2);
                    }
                    else{
                        B_cnt += Math.pow(BFS(new XY(i,j)),2);
                    }
                }
            }
        }
        System.out.println(W_cnt + " " + B_cnt);

    }
}