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
        public int compareTo(Node o) {
            return this.value - o.value;
        }
    }
    static List<Node> list[];
    static PriorityQueue<Integer> distance[];
    static int k;
    static boolean visited[][];
    static void Dekkstra(Node start){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        distance[start.next].add(0);
        while (!queue.isEmpty()){
            Node now = queue.poll();
            for(Node next: list[now.next]){
                if(distance[next.next].size() < k){
                    distance[next.next].add((next.value + now.value) * -1);
                    queue.add(new Node(next.next, next.value + now.value));
                }
                else{
                    if((distance[next.next].peek() * -1) > (next.value + now.value)){
                        distance[next.next].poll();
                        distance[next.next].add((next.value + now.value) * -1);
                        queue.add(new Node(next.next, next.value + now.value));
                    }
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        distance = new PriorityQueue[n + 1];
        for(int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
            distance[i] = new PriorityQueue<>();
        }
        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c= Integer.parseInt(st.nextToken());
            list[a].add(new Node(b,c));
        }
        Dekkstra(new Node(1,0));
        for(int i = 1;i<=n;i++){
            if(distance[i].size() == k){
                sb.append(distance[i].peek() * -1).append("\n");
            }
            else{
                sb.append(-1).append("\n");
            }
        }
        System.out.println(sb);
    }
}