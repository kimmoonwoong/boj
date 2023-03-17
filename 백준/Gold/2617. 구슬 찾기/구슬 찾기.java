import java.io.*;
import java.util.*;
public class Main {
    static List<Integer> list[];
    static boolean visited[];
    static int arrA[];
    static int arrB[];
    static int length;
    static void DFS(int cur, int start){
        visited[cur] = true;
        for (int next: list[cur]){
            if (visited[next]) continue;
            arrA[start]++;
            arrB[next]++;
            DFS(next, start);
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        arrA = new int[n + 1];
        arrB = new int[n + 1];
        for (int i = 1;i<=n;i++) list[i] = new ArrayList<>();

        for (int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[b].add(a);
        }

        for (int i = 1;i<=n;i++){
            visited = new boolean[n + 1];
            DFS(i,i);
        }
        int ans= 0;
        for (int i = 1;i<=n;i++){
            if (arrA[i] >= (n + 1) / 2 || arrB[i] >= (n + 1) / 2) ans++;
        }
        System.out.println(ans);
    }
}