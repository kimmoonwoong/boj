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
        static int g;
        static int h;

        static void Dekkstra(Node start){
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
            StringBuilder sb = new StringBuilder();
            int T = Integer.parseInt(br.readLine());

            while (T-- >0){
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());
                list = new ArrayList[n + 1];
                visited = new boolean[n + 1];
                w = new int[n + 1];
                Arrays.fill(w, INF);
                for (int i = 1;i<=n;i++){
                    list[i] = new ArrayList<>();
                }
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                g = Integer.parseInt(st.nextToken());
                h = Integer.parseInt(st.nextToken());

                for (int i = 0;i<m;i++){
                    st = new StringTokenizer(br.readLine());
                    int a = Integer.parseInt(st.nextToken());
                    int b = Integer.parseInt(st.nextToken());
                    int c = Integer.parseInt(st.nextToken());

                    if ((a == g && b == h) || (a == h && b == g)){
                        list[a].add(new Node(b,(c * 2 - 1)));
                        list[b].add(new Node(a,(c * 2 - 1)));
                    }
                    else{
                        list[a].add(new Node(b,(c * 2)));
                        list[b].add(new Node(a,(c * 2)));
                    }
                }

                int ansarr[] = new int[t];
                for (int i = 0;i<t;i++) ansarr[i] = Integer.parseInt(br.readLine());
                Arrays.sort(ansarr);

                Dekkstra(new Node(s,0));
                for (int i : ansarr){
                    if (w[i] % 2 != 0 && w[i] != INF) sb.append(i + " ");
                }
                sb.append("\n");
            }
            System.out.println(sb);


        }
    }