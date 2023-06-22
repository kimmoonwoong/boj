import java.util.*;
import java.io.*;
public class Main {
    static class Node implements Comparable<Node>{
        int next;
        int value;
        int state;

        public Node(int next, int value, int state){
            this.next = next;
            this.value = value;
            this.state = state;
        }

        @Override
        public int compareTo(Node o){
            return this.value - o.value;
        }
    }

    static List<Node> list[];
    static int wolfw[][];
    static int foxw[];
    static int INF = Integer.MAX_VALUE;

    static void WolfDjs(){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(1,0,0));
        wolfw[1][0] = 0;
        while (!queue.isEmpty()){
            Node now = queue.poll();
            if(wolfw[now.next][now.state] < now.value) continue;

            for(Node next: list[now.next]){
                int state = now.state == 1 ? 0 : 1;
                if(now.state == 0){
                    if(wolfw[next.next][state] > wolfw[now.next][now.state] + (next.value / 2)){
                        wolfw[next.next][state] = wolfw[now.next][now.state] + (next.value / 2);
                        queue.add(new Node(next.next, wolfw[next.next][state], state));
                    }
                }
                else{
                    if(wolfw[next.next][state] > wolfw[now.next][now.state] + (next.value * 2)){
                        wolfw[next.next][state] = wolfw[now.next][now.state] + (next.value * 2);
                        queue.add(new Node(next.next, wolfw[next.next][state], state));
                    }
                }
            }
        }
    }

    static void FoxDjs(){
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(1,0,0));
        foxw[1] = 0;
        while (!queue.isEmpty()){
            Node now = queue.poll();

            if(now.value > foxw[now.next]) continue;

            for(Node next: list[now.next]){
                if(foxw[next.next] > foxw[now.next] + next.value){
                    foxw[next.next] = foxw[now.next] + next.value;
                    queue.add(new Node(next.next, foxw[next.next], 0));
                }
            }
        }
    }

    public static void main(String args[]) throws IOException, NumberFormatException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        wolfw = new int[n + 1][2];
        foxw = new int[n + 1];
        for(int i = 1;i<=n;i++) list[i] = new ArrayList<>();
        for(int arr[]: wolfw) Arrays.fill(arr, INF);
        Arrays.fill(foxw, INF);

        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken()) * 2;

            list[a].add(new Node(b,c,0));
            list[b].add(new Node(a,c,0));
        }

        FoxDjs();
        WolfDjs();
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(foxw[i] < Math.min(wolfw[i][0], wolfw[i][1])) ans++;
        }
        System.out.println(ans);
    }
}