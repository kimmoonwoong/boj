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
    static class Edge{
        int a;
        int b;
        public Edge(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
    static int INF = Integer.MAX_VALUE;
    static List<Node> list[];
    static boolean visited[];
    static int w[];
    static Edge min_edge[];

    static void Dekkstra(){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(1,0));
        w[1] = 0;

        while (!queue.isEmpty()){
            Node now = queue.poll();

            for (Node next: list[now.next]){
                if (w[next.next] > w[now.next] + next.value){
                    w[next.next] = w[now.next] + next.value;
                    min_edge[next.next] = new Edge(now.next, next.next);
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

        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        w = new int[n + 1];
        min_edge = new Edge[n + 1];
        Arrays.fill(w, INF);

        for (int i = 1;i<=n;i++){
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

        Dekkstra();
        System.out.println(n - 1);
        for (int i = 2;i<=n;i++){
            System.out.println(min_edge[i].a + " " + min_edge[i].b);
        }
    }
}