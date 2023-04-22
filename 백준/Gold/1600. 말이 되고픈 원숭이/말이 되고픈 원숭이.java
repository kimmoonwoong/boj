import java.util.*;
import java.io.*;

public class Main {
    static class Node{
        int x;
        int y;
        int cnt;
        int k;

        public Node(int x, int y, int cnt, int k){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.k = k;
        }
    }
    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};
    static int hourse_x[] = {-2, -1 ,-2, -1, 2, 1, 2, 1};
    static int hourse_y[] = {-1, -2, 1, 2, -1, -2 ,1, 2};
    static int k;
    static int n;
    static int m;
    static boolean visited[][][];
    static int map[][];

    static int BFS(){
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(0,0,0,0));

        while (!queue.isEmpty()){
            Node now = queue.poll();
            if (now.x == n - 1 && now.y == m - 1){
                return now.cnt;
            }

            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nexty < 0 || nextx >=n || nexty >=m) continue;
                if (visited[nextx][nexty][now.k]) continue;
                if (map[nextx][nexty] == 1) continue;
                visited[nextx][nexty][now.k] = true;
                queue.add(new Node(nextx, nexty, now.cnt + 1, now.k));
            }
            if (now.k < k) {
                for (int i = 0; i < 8; i++) {
                    int hoursex = now.x + hourse_x[i];
                    int hoursey = now.y + hourse_y[i];

                    if (hoursex < 0 || hoursey < 0 || hoursex >= n || hoursey >= m) continue;
                    if (visited[hoursex][hoursey][now.k + 1]) continue;
                    if (map[hoursex][hoursey] == 1) continue;
                    visited[hoursex][hoursey][now.k + 1] = true;
                    queue.add(new Node(hoursex,hoursey, now.cnt + 1, now.k + 1));
                }
            }
        }
        return -1;
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visited = new boolean[n][m][k + 1];
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
