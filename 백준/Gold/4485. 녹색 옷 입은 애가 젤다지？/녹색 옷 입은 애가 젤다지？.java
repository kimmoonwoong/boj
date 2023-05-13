import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node>{
        int x;
        int y;
        int rupee;

        public Node(int x, int y, int rupee){
            this.x = x;
            this.y = y;
            this.rupee = rupee;
        }

        @Override
        public int compareTo(Node o) {
            return this.rupee - o.rupee;
        }
    }
    static int nextx[] = {1,-1,0,0};
    static int nexty[] = {0,0,1,-1};
    static int map[][];
    static boolean visited[][];
    static int n;
    static int INF = Integer.MAX_VALUE;
    static int wmap[][];
    static int cnt = 1;
    static void Dekkestra(Node start){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        wmap[0][0] = map[0][0];
        queue.add(start);
        while (!queue.isEmpty()){
            Node now = queue.poll();
            for(int i = 0;i<4;i++){
                int next_x = now.x + nextx[i];
                int next_y = now.y + nexty[i];

                if(next_x<0|| next_y<0|| next_x>=n||next_y>=n) continue;


                if(wmap[next_x][next_y] > now.rupee + map[next_x][next_y]){
                    wmap[next_x][next_y] = now.rupee + map[next_x][next_y];
                    queue.add(new Node(next_x,next_y,now.rupee + map[next_x][next_y]));
                }
            }
        }
    }


    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true){
            n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            map = new int[n][n];
            wmap = new int[n][n];
            visited = new boolean[n][n];
            for(int[] a: wmap){
                Arrays.fill(a, INF);
            }
            for(int i = 0; i<n;i++){
                StringTokenizer st = new StringTokenizer(br.readLine() + " ");
                for(int j = 0; j<n;j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            Dekkestra(new Node(0,0,map[0][0]));
            sb.append("Problem " + cnt + ": " + wmap[n - 1][n - 1]).append("\n");
            cnt++;
        }
        System.out.print(sb);

    }
}