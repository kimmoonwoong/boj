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

    static int s;
    static int e;

    static boolean BFS(int mid){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(s);

        while (!queue.isEmpty()){
            int now = queue.poll();

            if (now == e){
                return true;
            }
            if (visited[now]) continue;
            visited[now] = true;

            for (Node next: list[now]){
                if (mid <= next.value){
                    queue.add(next.next);
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];

        for (int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
        }
        int max = 0;
        for (int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
            max = Math.max(max, c);
        }
        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        int start = 0;
        int end = max;

        while (start<=end){
            int mid = (start + end) / 2;
            visited = new boolean[n + 1];
            if (BFS(mid)){
                start = mid + 1;
            }
            else end = mid - 1;
        }

        System.out.println(end);

    }
}