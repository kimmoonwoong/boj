import java.util.*;

class Solution {
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
    static int D_a[];
    static int D_b[];
    static int D_s[];
    static List<Node> list[];
    
    static void Dekkstra(Node start, int w[]){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        w[start.next] = 0;
        while(!queue.isEmpty()){
            Node now = queue.poll();
            if (now.value > w[now.next]) continue;
            for(Node next: list[now.next]){
                if(w[next.next] > w[now.next] + next.value){
                    w[next.next] = w[now.next] + next.value;
                    queue.add(new Node(next.next, w[next.next]));
                }
            }
        }
    }
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = 0;
        list = new ArrayList[n + 1];
        D_a = new int[n + 1];
        D_b = new int[n + 1];
        D_s = new int[n + 1];
        Arrays.fill(D_a, INF);
        Arrays.fill(D_b, INF);
        Arrays.fill(D_s, INF);
        
        for(int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
        }
        for(int edge[] : fares){
            list[edge[0]].add(new Node(edge[1], edge[2]));
            list[edge[1]].add(new Node(edge[0], edge[2]));
        }
        Dekkstra(new Node(s,0), D_s);
        Dekkstra(new Node(a,0), D_a);
        Dekkstra(new Node(b,0), D_b);
        answer = Integer.MAX_VALUE;
        for(int i = 1;i<=n;i++){
            System.out.println(D_a[i] + " " + D_b[i] +" " + D_s[i] + " " + i);
            answer = Math.min(answer, D_a[i] + D_b[i] + D_s[i]);
        }
        return answer;
    }
}