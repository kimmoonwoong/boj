import java.io.*;
import java.math.BigInteger;
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
    static int w1[];
    static int w2[];
    static boolean visited[];
    static List<int[]> check;

    static void Dekkstra(Node start, int[] w){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(start);
        w[start.next] = 0;
        while (!queue.isEmpty()){
            Node now = queue.poll();

            if(visited[now.next]) continue;
            visited[now.next] = true;

            for(Node next: list[now.next]){
                if(w[next.next] > w[now.next] + next.value){
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
        int robot1 = Integer.parseInt(st.nextToken());
        int robot2 = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        check = new ArrayList<>();
        w1 = new int[n + 1];
        w2 = new int[n + 1];
        Arrays.fill(w1, INF);
        Arrays.fill(w2, INF);
        for(int i =1;i<=n;i++){
            list[i] = new ArrayList<>();
        }

        for (int i = 0;i<n-1;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
            check.add(new int[] {a,b});
        }

        Dekkstra(new Node(robot1,0),w1);
        visited = new boolean[n + 1];
        Dekkstra(new Node(robot2,0),w2);
        int ans = Integer.MAX_VALUE;
        for (int[] room: check){
            ans = Math.min(w1[room[0]] + w2[room[1]], ans);
            ans = Math.min(w1[room[1]] + w2[room[0]], ans);
        }
        if(robot1 == robot2 || n == 1){
            System.out.println(0);
        }
        else System.out.println(ans);
    }
}