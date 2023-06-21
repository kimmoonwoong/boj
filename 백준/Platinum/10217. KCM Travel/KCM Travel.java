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
            return this.c - o.c;
        }
    }

    static int n;
    static int m;
    static int k;

    static Integer w[][];
    static List<Node> list[];
    static int INF = Integer.MAX_VALUE;
    static int Dekkstra(Node start){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        w[start.next][0] = 0;
        for(int i = 1; i<=m;i++){
            w[start.next][i] = 0;
        }
        int ans = INF;
        while (!queue.isEmpty()){
            Node now = queue.poll();
            if (ans <= w[now.next][now.c] ) continue;

            for (Node next : list[now.next]){
                if (now.c + next.c > m) continue;

                if(ans<= w[now.next][now.c] + next.d) continue;

                if (next.next == n){
                    ans = w[now.next][now.c] + next.d;
                    continue;
                }

                if (w[next.next][next.c + now.c] > w[now.next][now.c] + next.d){
                    if(w[next.next][next.c + now.c].equals(INF)) queue.add(new Node(next.next,now.c + next.c, w[now.next][now.c] + next.d));
                    w[next.next][now.c + next.c] = w[now.next][now.c] + next.d;
                }
            }
        }
        return ans;
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
            w = new Integer[n + 1][m + 1];
            for(Integer arr[] : w) Arrays.fill(arr, INF);
            for(int i = 1;i<=n;i++) list[i] = new ArrayList<>();
            for(int i = 0;i<k;i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b =  Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());

                list[a].add(new Node(b,c,d));
            }
            for(List<Node> list1 : list){
                if(list1 == null) continue;
                Collections.sort(list1);
            }
            int k = Dekkstra(new Node(1,0,0));

            if (k == INF) sb.append("Poor KCM").append("\n");
            else sb.append(k).append("\n");

        }
        System.out.println(sb);
    }
}