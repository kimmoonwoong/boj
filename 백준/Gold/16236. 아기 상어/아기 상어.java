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
    static int next_x[] = {-1,0,1,0};
    static int next_y[] = {0,1,0,-1};

    static int INF = Integer.MAX_VALUE;
    static int n;
    static int dist[][];
    static int map[][];
    static boolean visited[][];
    static int size = 2;
    static int ans = 0;
    static int count = 0;

    static void BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        for (int [] arr: dist){
            Arrays.fill(arr, INF);
        }
        visited = new boolean[n][n];
        visited[start.x][start.y] = true;
        dist[start.x][start.y] = 0;
        int min = INF;
        while (!queue.isEmpty()){
            XY now = queue.poll();

            for (int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx<0 || nexty<0 || nextx>=n || nexty>=n) continue;
                if (visited[nextx][nexty]) continue;
                if (map[nextx][nexty] > size) continue;

                if (map[nextx][nexty] <= size) {
                    dist[nextx][nexty] = dist[now.x][now.y] + 1;
                    if (map[nextx][nexty] != 0 && size != map[nextx][nexty]) min = Math.min(dist[nextx][nexty],min);
                }
                visited[nextx][nexty] = true;
                queue.add(new XY(nextx,nexty));
            }
        }
        if (min == INF){
            System.out.println(ans);
            System.exit(0);
        }
        boolean isCheck = false;
        int top = INF;
        int left = INF;
        XY choicexy = null;
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                if (dist[i][j] == min && map[i][j] != 0 && map[i][j] < size){
                    if (top > i){
                        top = i;
                        choicexy = new XY(i,j);
                        isCheck = false;
                    }
                    else if (top == i){
                        if (choicexy.y > j){
                            choicexy = new XY(i,j);
                        }
                    }
                }
            }
        }
        ans += min;
        map[choicexy.x][choicexy.y] = 0;
        count++;
        if (count == size){
            size++;
            count = 0;
        }
        BFS(choicexy);
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        dist = new int[n][n];
        visited = new boolean[n][n];
        for (int [] arr: dist){
            Arrays.fill(arr,INF);
        }
        int start_x = 0;
        int start_y = 0;
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 9){
                    start_x = i;
                    start_y = j;
                    map[start_x][start_y] = 0;
                }
            }
        }
        BFS(new XY(start_x,start_y));
    }
}