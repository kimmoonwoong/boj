import java.util.*;
import java.io.*;
public class Main {
    static List<Integer> list[];
    static boolean visited[];
    static int arr[];
    static boolean BFS(int start){
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;
        int idx = 2;
        while (!queue.isEmpty()){
            int now = queue.poll();
            HashSet<Integer> set =  new HashSet<>();
            for(int next: list[now]){
                if (visited[next]) continue;

                visited[next] = true;
                set.add(next);
            }
            if(set.size() == 0) continue;
            for(int i = idx; i<idx + set.size();i++){
                if(set.contains(arr[i])) queue.add(arr[i]);
                else return false;
            }
            idx+= set.size();
        }
        return true;
    }
    public static void main(String args[]) throws IOException, NumberFormatException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        list = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        arr = new int[n + 1];
        for(int i = 1;i<=n;i++){
            list[i] = new ArrayList<>();
        }
        for(int i = 0;i<n - 1;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list[a].add(b);
            list[b].add(a);
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1;i<=n;i++) arr[i] = Integer.parseInt(st.nextToken());

        if(BFS(1)) System.out.println(1);
        else System.out.println(0);
    }
}