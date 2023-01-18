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
        static int n;
        static int m;
        static boolean visited[];
        static List<Node> list[];
        static int w[];
        static int INF = Integer.MAX_VALUE;

        static void Dekkstrea(Node start){
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
            StringTokenizer st = new StringTokenizer(br.readLine() + " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            list = new ArrayList[n + 1];
            visited = new boolean[n+1];
            w = new int[n+1];
            Arrays.fill(w, INF);
            for(int i = 1;i<=n;i++){
                list[i] = new ArrayList<>();
            }

            for(int i = 0; i<m;i++){
                st = new StringTokenizer(br.readLine() + " ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                list[a].add(new Node(b,c));
                list[b].add(new Node(a,c));
            }
            Dekkstrea(new Node(1,0));
            System.out.println(w[n]);

        }
    }