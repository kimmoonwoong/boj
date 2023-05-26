import java.util.*;
import java.io.*;
public class Main {
    static class Node implements Comparable<Node>{
        int next;
        int c;
        int d;

        public Node(int next, int c, int d){
            this.next = next;
            this.c = c;
            this.d = d;
        }

        @Override
        public int compareTo(Node o){
            return this.d - o.d;
        }
    }

    static int n;
    static int m;
    static int k;

    static int w[][];
    static List<Node> list[];
    static int INF = Integer.MAX_VALUE;
    static void Dekkstra(Node start){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        w[start.next][0] = 0;

        while (!queue.isEmpty()){
            Node now = queue.poll();
            if (w[now.next][now.c] < now.d ) continue;

            for (Node next : list[now.next]){
                if (now.c + next.c > m) continue;

                if (w[next.next][next.c + now.c] > w[now.next][now.c] + next.d){
                    w[next.next][now.c + next.c] = w[now.next][now.c] + next.d;
                    queue.add(new Node(next.next,now.c + next.c, w[next.next][now.c + next.c]));
                }
            }
        }
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T  = Integer.parseInt(br.readLine());

        while (T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            list = new ArrayList[n + 1];
            w = new int[n + 1][m + 1];
            for(int arr[] : w) Arrays.fill(arr, INF);
            for(int i = 1;i<=n;i++) list[i] = new ArrayList<>();
            for(int i = 0;i<k;i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b =  Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());

                list[a].add(new Node(b,c,d));
            }

            Dekkstra(new Node(1,0,0));
            int ans = INF;
            for(int i = 0;i<=m;i++){
                ans = Math.min(ans, w[n][i]);
            }
            if (ans == INF) sb.append("Poor KCM").append("\n");
            else sb.append(ans).append("\n");

        }
        System.out.println(sb);
    }
}