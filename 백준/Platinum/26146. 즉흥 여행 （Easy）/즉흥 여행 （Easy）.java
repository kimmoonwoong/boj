import java.io.*;
import java.util.*;


public class Main {
    static List<Integer> list[];
    static List<Integer> reverselist[];

    static boolean visited[];
    static boolean reversevisited[];


    static void BFS(boolean visited[], List<Integer> list[]){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        visited[1] = true;
        while (!queue.isEmpty()){
            int now = queue.poll();

            for(int next: list[now]){
                if(!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                }
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        list = new ArrayList[n + 1];
        reverselist = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        reversevisited = new boolean[n + 1];
        for(int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
            reverselist[i] = new ArrayList<>();
        }

        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a= Integer.parseInt(st.nextToken());
            int b= Integer.parseInt(st.nextToken());

            list[a].add(b);
            reverselist[b].add(a);
        }
        BFS(visited, list);
        for(int i = 1;i<=n;i++){
            if(!visited[i]){
                System.out.println("No");
                System.exit(0);
            }
        }
        BFS(reversevisited, reverselist);

        for(int i = 1;i<=n;i++){
            if(!reversevisited[i]){
                System.out.println("No");
                System.exit(0);
            }
        }
        System.out.println("Yes");
    }
}