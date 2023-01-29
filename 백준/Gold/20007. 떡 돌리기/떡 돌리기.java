import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node>{
        int next;
        int value;

        public Node(int next, int value){
            this.next = next;
            this.value = value;
        }

        @Override
        public int compareTo(Node o){
            return this.value - o.value;
        }
    }
    static int INF = Integer.MAX_VALUE;

    static List<Node> list[];
    static boolean visited[];
    static int w[];

    static void Dekkerstra(Node start){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        w[start.next] = 0;
        while (!queue.isEmpty()){
            Node now = queue.poll();
            if (visited[now.next]) continue;
            visited[now.next] = true;

            for (Node next: list[now.next]){
                if (w[next.next] > w[now.next] + next.value){
                    w[next.next] = w[now.next] + next.value;
                    queue.add(new Node(next.next, w[next.next]));
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        list = new ArrayList[n];
        visited = new boolean[n];
        w = new int[n];
        Arrays.fill(w, INF);
        for (int i = 0;i<n;i++){
            list[i] = new ArrayList<>();
        }

        for (int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
        }

        Dekkerstra(new Node(y,0));
        int ans = 0;
        int sum = 0;
        Arrays.sort(w);
        for (int i = 0;i<n;i++){
            if (w[i] == INF || w[i] * 2 > x){
                System.out.println(-1);
                System.exit(0);
            }

            if (sum + w[i] * 2 <= x){
                sum+=w[i] * 2;
            }
            else{
                ans++;
                sum = w[i] * 2;
            }
        }
        if (sum <= x) ans++;
        System.out.println(ans);
    }
}