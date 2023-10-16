import java.io.*;
import java.util.*;

public class Main {
    static class XY{
        int x;
        int y;
        int chang;

        public XY(int x, int y, int chang){
            this.x = x;
            this.y = y;
            this.chang = chang;
        }
    }
    static int nextx[] = {1,-1,0,0};
    static int nexty[] = {0,0,1,-1};
    static int map[][];
    static boolean visited[][];
    static int changeRoom[][];
    static int n;
    static int INF = Integer.MAX_VALUE;

    static void BFS(){
        Queue<XY> queue = new LinkedList<>();
        queue.add(new XY(0,0,0));
        while (!queue.isEmpty()){
            XY now =queue.poll();
            for(int i = 0; i<4;i++){
                int next_x = now.x + nextx[i];
                int next_y = now.y + nexty[i];

                if(next_x<0 || next_y<0 || next_x>=n|| next_y>=n) continue;

                if(map[next_x][next_y] == 0){
                    if(changeRoom[next_x][next_y] > now.chang + 1){
                        changeRoom[next_x][next_y] = now.chang + 1;
                        queue.add(new XY(next_x,next_y,now.chang + 1));
                    }
                }
                else{
                    if(changeRoom[next_x][next_y] > now.chang){
                        changeRoom[next_x][next_y] = now.chang;
                        queue.add(new XY(next_x,next_y, now.chang));
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visited = new boolean[n][n];
        changeRoom = new int[n][n];
        for(int a[]: changeRoom){
            Arrays.fill(a, INF);
        }
        for(int i = 0;i<n;i++){
            String s = br.readLine();
            for(int j = 0; j<n;j++){
                map[i][j] = Integer.parseInt(s.substring(j , j+ 1));
            }
        }
        BFS();
        System.out.println(changeRoom[n - 1][n - 1]);
    }
}