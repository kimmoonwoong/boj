import java.util.*;
import java.io.*;

public class Main {
    static class XY{
        int x;
        int y;

        public XY(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    static class Node{
        int x;
        int y;
        int area;
        int cnt;

        public Node(int x, int y, int area, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.area = area;
        }
    }

    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};
    static int n;
    static int map[][];
    static boolean visited[][];
    static boolean visited2[][][];
    static Queue<Node> nodeQueue = new LinkedList<>();

    static void areaCheckBFS(XY start, int area){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        visited[start.x][start.y] = true;
        map[start.x][start.y] = area;
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for(int i = 0;i<4;i++){
                int nextx = next_x[i] + now.x;
                int nexty = next_y[i] + now.y;

                if (nextx < 0 || nexty < 0 || nextx>=n || nexty>=n) continue;
                if (visited[nextx][nexty]) continue;
                if (map[nextx][nexty] == 0){
                    visited[nextx][nexty] = true;
                    nodeQueue.add(new Node(nextx,nexty,area, 0));
                }
                if (map[nextx][nexty] == 1) {
                    map[nextx][nexty] = area;
                    visited[nextx][nexty] = true;
                    queue.add(new XY(nextx,nexty));
                }
            }
        }
    }
    static int BFS(){
        while (!nodeQueue.isEmpty()){
            Node now = nodeQueue.poll();
            if (map[now.x][now.y] != 0 && map[now.x][now.y] != now.area){
                return now.cnt ;
            }
            for(int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nexty < 0 || nextx >= n || nexty>=n) continue;
                if (visited2[nextx][nexty][now.area]) continue;
                if (map[nextx][nexty] == now.area) continue;

                visited2[nextx][nexty][now.area] = true;
                nodeQueue.add(new Node(nextx,nexty,now.area,now.cnt + 1));
            }
        }

        return 0;
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        map = new int[n][n];
        visited = new boolean[n][n];
        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int area = 1;
        for(int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                if (map[i][j] == 0 || visited[i][j]) continue;
                areaCheckBFS(new XY(i,j), area);
                area++;
            }
        }

        visited2 = new boolean[n][n][area];
        int ans = BFS();
        System.out.println(ans);
    }
}