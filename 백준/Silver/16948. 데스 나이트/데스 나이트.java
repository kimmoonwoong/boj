import java.util.*;
import java.io.*;

public class Main {
    static class XY{
        int x;
        int y;
        int cnt;

        public XY(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
    static int next_x[] = {-2, -2, 0, 0, 2, 2};
    static int next_y[] = {-1, 1, -2, 2 , -1, 1};
    static int n;
    static boolean visited[][];

    static int BFS(int r1, int c1, int r2, int c2){
        Queue<XY> queue = new LinkedList<>();
        queue.add(new XY(r1, c1, 0));
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for (int i = 0;i<6;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];
                if (nextx == r2 && nexty == c2){
                    return now.cnt + 1;
                }
                if (nextx < 0 || nexty < 0 || nextx>=n || nexty>=n) continue;
                if (visited[nextx][nexty]) continue;

                visited[nextx][nexty] = true;
                queue.add(new XY(nextx, nexty, now.cnt + 1));
            }
        }
        return -1;
    }

    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        visited = new boolean[n][n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r1 = Integer.parseInt(st.nextToken());
        int c1 = Integer.parseInt(st.nextToken());
        int r2 = Integer.parseInt(st.nextToken());
        int c2 = Integer.parseInt(st.nextToken());

        int ans = BFS(r1, c1, r2, c2);
        System.out.println(ans);
    }
}