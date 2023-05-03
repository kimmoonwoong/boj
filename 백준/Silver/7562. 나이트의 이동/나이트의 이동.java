import java.util.*;
import java.io.*;

public class Main {
    static class Node{
        int x;
        int y;
        int cnt;

        public Node(int x, int y, int cnt){
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
    static int next_x[] = {-2, -1, 1, 2, 2, 1, -1 , -2};
    static int next_y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static int n;
    static boolean visited[][];

    static int BFS(int start_x, int start_y, int end_x, int end_y){
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(start_x, start_y, 0));
        while (!queue.isEmpty()){
            Node now = queue.poll();
            if (now.x == end_x && now.y == end_y) return now.cnt;

            for (int i = 0;i<8;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if (nextx < 0 || nexty < 0 || nextx>=n || nexty>=n) continue;
                if (visited[nextx][nexty]) continue;

                visited[nextx][nexty] = true;
                queue.add(new Node(nextx, nexty, now.cnt + 1));
            }
        }
        return 0;
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0){
            n = Integer.parseInt(br.readLine());
            visited = new boolean[n][n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start_x = Integer.parseInt(st.nextToken());
            int start_y = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int end_x = Integer.parseInt(st.nextToken());
            int end_y = Integer.parseInt(st.nextToken());
            sb.append(BFS(start_x,start_y,end_x,end_y)).append("\n");
        }
        System.out.println(sb);
    }
}