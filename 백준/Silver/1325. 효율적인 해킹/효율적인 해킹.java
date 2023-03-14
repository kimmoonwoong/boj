import java.io.*;
import java.util.*;


public class Main {
    static List<Integer> list[];
    static boolean visited[];
    static int arr[];

    static void BFS(int start){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        int count = 0;
        visited[start] = true;
        while (!queue.isEmpty()){
            int now = queue.poll();

            for (int next: list[now]){
                if (visited[next]) continue;
                visited[next] = true;
                arr[next]++;
                queue.add(next);

            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        arr = new int[n + 1];
        for (int i = 1; i<=n;i++) list[i] = new ArrayList<>();

        for (int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
        }
        int max = 0;
        for (int i = 1;i<=n;i++){
            visited = new boolean[n + 1];
            BFS(i);
        }
        for (int i = 1;i<=n;i++) max = Math.max(max, arr[i]);

        StringBuilder sb = new StringBuilder();
        for (int i = 1;i<=n;i++){
            if (max == arr[i]) sb.append(i + " ");
        }
        System.out.println(sb);
    }
}
