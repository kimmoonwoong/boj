import java.io.*;
import java.util.*;
public class Main {
    static class Node implements Comparable<Node>{
        int next;
        long value;
        public Node(int next, long value){
            this.next = next;
            this.value = value;
        }

        @Override
        public int compareTo(Node o) {
            if (this.value == o.value) return 0;
            else if (this.value < o.value) return 1;
            else return -1;
        }
    }
    static class Edge{
        int a;
        int b;
        int value;

        public Edge(int a, int b, int value){
            this.a = a;
            this.b = b;
            this.value = value;
        }
    }
    static long INF = Long.MAX_VALUE;
    static List<Node> list[];
    static long w[];
    static int a;
    static int b;
    static int k;

    static void Dekkstra(Node start){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        w[start.next] = 0;
        while (!queue.isEmpty()){
            Node now = queue.poll();
            for (Node next : list[now.next]) {
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
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        w = new long[n + 1];
        Arrays.fill(w, INF);
        for (int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
        }
        List<Edge> edge = new ArrayList<>();
        for (int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            edge.add(new Edge(a,b,c));
        }

        k = Integer.parseInt(br.readLine());

        for (int i = 0;i<k;i++){
            st = new StringTokenizer(br.readLine());
            int before = Integer.parseInt(st.nextToken());
            int after = Integer.parseInt(st.nextToken());

            Edge now = edge.get(i);
            list[now.a].add(new Node(now.b, after));
            list[now.b].add(new Node(now.a, after));
            list[now.a].add(new Node(now.b, before));
            list[now.b].add(new Node(now.a, before));
        }
        if (k == 0){
            for (Edge now : edge){
                list[now.a].add(new Node(now.b, now.value));
                list[now.b].add(new Node(now.a, now.value));
            }
        }
        Dekkstra(new Node(a,0));
        System.out.println(w[b]);
    }
}