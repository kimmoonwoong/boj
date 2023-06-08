import java.util.*;
import java.io.*;
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
    static List<Node> list[];
    static List<Integer> fastpathList[];
    static int w[];
    static int INF = Integer.MAX_VALUE;
    static boolean visited[][];
    static void Dekkstra(int s){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(s, 0));
        w[s] = 0;
        while (!queue.isEmpty()){
            Node now =queue.poll();

            if (w[now.next] < now.value){
                continue;
            }

            for(Node next: list[now.next]){
                if(visited[now.next][next.next]) continue;
                if(w[next.next] == w[now.next] + next.value){
                    fastpathList[next.next].add(now.next);
                }
                else if(w[next.next] > w[now.next] + next.value){
                    fastpathList[next.next].clear();
                    fastpathList[next.next].add(now.next);
                    w[next.next] = w[now.next] + next.value;
                    queue.add(new Node(next.next, w[next.next]));
                }
            }
        }
    }
    static void BFS(int start, int end){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        while (!queue.isEmpty()){
            int now = queue.poll();
            for(int next: fastpathList[now]){
                if(visited[next][now]) continue;
                visited[next][now] = true;
                queue.add(next);
            }
        }
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0) break;
            list= new ArrayList[n];
            w = new int[n];
            visited = new boolean[n][n];
            fastpathList = new ArrayList[n];
            Arrays.fill(w, INF);
            for(int i = 0;i<n;i++) {
                list[i] = new ArrayList<>();
                fastpathList[i] = new ArrayList<>();
            }
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            for(int i = 0;i<m;i++){
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                list[a].add(new Node(b,c));
            }
            Dekkstra(s);
            BFS(e, s);
            Arrays.fill(w, INF);
            Dekkstra(s);

            if(w[e] == INF) sb.append(-1).append("\n");
            else sb.append(w[e]).append("\n");

        }
        System.out.println(sb);
    }
}