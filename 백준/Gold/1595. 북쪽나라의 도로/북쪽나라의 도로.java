import java.util.*;
import java.io.*;
public class Main {
    static class Node{
        int next;
        int value;

        public Node(int next, int value){
            this.next = next;
            this.value = value;
        }
    }
    static List<Node> list[] = new ArrayList[10001];
    static boolean visited[] = new boolean[10001];
    static int res[] = new int[10001];
    static int size = 0;

    static int BFS(Node start){
        Queue<Node> queue = new LinkedList<>();
        queue.add(start);
        visited[start.next] = true;

        while (!queue.isEmpty()){
            Node now = queue.poll();
            for (Node next: list[now.next]){
                if (visited[next.next]) continue;
                visited[next.next] = true;
                res[next.next] = res[now.next] + next.value;
                queue.add(next);
            }
        }

        int ret = 1;
        for (int i = 2;i<=size;i++){
            if (res[i] > res[ret]) ret = i;
        }
        return ret;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 1;i<=10000;i++){
            list[i] = new ArrayList<>();
        }
        while (true){
            String s = br.readLine();
            if (s == null || s.equals("")) break;
            StringTokenizer st = new StringTokenizer(s);
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
            size = Math.max(size, Math.max(a,b));
        }

        int k = BFS(new Node(1,0));
        visited = new boolean[10001];
        res = new int[10001];
        int ans = BFS(new Node(k, 0));
        System.out.println(res[ans]);
    }
}