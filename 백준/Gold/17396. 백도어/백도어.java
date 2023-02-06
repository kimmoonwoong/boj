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
            if(this.value - o.value >0) return 1;
            else return -1;
        }
    }
    static int n;
    static int m;
    static long w[];
    static boolean visited[];
    static List<Node> list[];
    static long INF = Long.MAX_VALUE;

    static void Dekkstra(){
        PriorityQueue<Node> queue= new PriorityQueue<>();
        queue.add(new Node(0,0));
        w[0] = 0;
        while (!queue.isEmpty()){
            Node now =queue.poll();
            if(visited[now.next] && now.next != n-1) continue;
            visited[now.next] = true;
            for(Node next: list[now.next]){
                if(w[next.next] > w[now.next] + next.value){
                    w[next.next] = w[now.next] + next.value;
                    queue.add(new Node(next.next, w[next.next]));
                }
            }
        }
        if(w[n-1] != INF) System.out.println(w[n - 1]);
        else System.out.println(-1);
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine() + " ");

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        list = new ArrayList[n];
        visited = new boolean[n];
        w = new long[n];
        Arrays.fill(w, INF);
        st = new StringTokenizer(br.readLine() + " ");
        for(int i = 0;i<n;i++) {
            int k = Integer.parseInt(st.nextToken());
            if(k == 1){
                visited[i] = true;
            }
        }
        for(int i = 0;i<n;i++){
            list[i] = new ArrayList<>();
        }
        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine() + " ");
            int a = Integer.parseInt(st.nextToken());
            int b= Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
        }
        Dekkstra();
    }
}