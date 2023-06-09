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
    static boolean BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        visited[start.x][start.y] = true;
        int cnt = 1;
        int max_x = start.x;
        int min_x = start.x;
        int max_y = start.y;
        int min_y = start.y;

        while (!queue.isEmpty()){
            XY now = queue.poll();
            for(int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if(nextx < 0 || nexty < 0 || nextx>=n || nexty>=m) continue;
                if(visited[nextx][nexty]) continue;
                if(map[nextx][nexty] != map[start.x][start.y]) continue;

                visited[nextx][nexty] = true;
                cnt+=1;
                max_x = Math.max(max_x, nextx);
                min_x = Math.min(min_x, nextx);
                max_y = Math.max(max_y, nexty);
                min_y = Math.min(min_y, nexty);
                queue.add(new XY(nextx,nexty));
            }
        }
        int x = (max_x - min_x) + 1;
        int y = (max_y - min_y) + 1;
        if(x*y == cnt) return true;
        else return false;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new char[n][m];
        visited = new boolean[n][m];
        for(int i = 0;i<n;i++){
            String s = br.readLine();
            for(int j = 0; j<m;j++){
                map[i][j] = s.charAt(j);
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j]){
                    if(!BFS(new XY(i,j))){
                        System.out.println("BaboBabo");
                        System.exit(0);
                    }
                }
            }
        }
        System.out.println("dd");
    }
}