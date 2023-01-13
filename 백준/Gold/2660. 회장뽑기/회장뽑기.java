import java.io.*;
import java.util.*;

public class Main {
    static List<Integer> list[];
    static int count[];
    static boolean visited[];
    static int n;
    static int min = Integer.MAX_VALUE;

    static int BFS(int start){
        Queue<Integer> queue = new LinkedList<>();
        visited = new boolean[n+1];
        count = new int[n + 1];
        int max = 0;
        queue.add(start);
        visited[start] = true;
        while (!queue.isEmpty()){
            int now = queue.poll();
            for(int next: list[now]){
                if(visited[next]) continue;

                visited[next] = true;
                count[next] = count[now] + 1;
                queue.add(next);
            }
        }
        for(int i = 1;i<=n;i++){
            if(max< count[i]) max= count[i];
        }
        if(min> max) min = max;
        return max;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine() + " ");
        n = Integer.parseInt(st.nextToken());
        list = new ArrayList[n + 1];
        int result[] = new int[n+1];
        int resultcount = 0;
        int resultP[] = new int[n + 1];
        for(int i = 1; i<=n;i++){
            list[i] = new ArrayList<>();
        }
        while (true){
            StringTokenizer st1 = new StringTokenizer(br.readLine() + " ");
            int a = Integer.parseInt(st1.nextToken());
            int b = Integer.parseInt(st1.nextToken());
            if(a== -1 && b==-1) break;
            list[a].add(b);
            list[b].add(a);
        }
        for(int i = 1; i<=n;i++){
            result[i] = BFS(i);
        }
        int j = 0;
        for(int i =1;i<=n;i++){
            if(result[i] == min) {
                resultcount++;
                resultP[j] = i;
                j++;
            }
        }
        System.out.println(min + " "+ resultcount);
        for(int i = 0;i<j;i++){
            System.out.print(resultP[i] + " ");
        }
    }
}