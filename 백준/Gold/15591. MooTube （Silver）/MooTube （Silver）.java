import java.io.*;
import java.util.*;
public class Main {
    static class Node{
        int next;
        int value;

        public Node(int next, int value){
            this.next = next;
            this.value = value;
        }
    }
    static List<Node> list[];
    static boolean visited[];
    static int BFS(Node start, int k){
        Queue<Node> queue = new LinkedList<>();
        queue.add(start);
        int count = 0;
        visited[start.next] = true;
        while (!queue.isEmpty()){
            Node now = queue.poll();
            if(now.value != Integer.MAX_VALUE && now.value >= k) count++;
            for(Node next: list[now.next]){
                if(visited[next.next]) continue;
                if(next.value < k) continue;

                int min = Math.min(now.value, next.value);
                visited[next.next] = true;
                queue.add(new Node(next.next, min));
            }
        }
        return count;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for(int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
        }

        int count = 0;
        for(int i = 0;i<n - 1;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
        }
        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            sb.append(BFS(new Node(b,Integer.MAX_VALUE),a)).append("\n");
            visited = new boolean[n + 1];
        }
        System.out.println(sb);
    }
}