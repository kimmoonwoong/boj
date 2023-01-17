import java.io.*;
import java.util.*;

public class Main {

    static List<Integer> list[];
    static int integer[];
    static int time[];
    static int result[];
    static int ans = 0;

    static void topologySort(){
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 1;i< integer.length;i++){
            result[i] = time[i];
            if(integer[i] == 0){
                queue.add(i);
            }
        }

        while (!queue.isEmpty()){

            int now = queue.poll();

            for (int next: list[now]){
                integer[next]--;
                result[next] = Math.max(result[next], result[now] + time[next]);
                if (integer[next] == 0){
                    queue.add(next);
                }
            }
        }

        for (int i = 1;i<result.length;i++){
            ans = Math.max(ans, result[i]);
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        list = new ArrayList[n + 1];
        integer = new int[n + 1];
        time = new int[n + 1];
        result = new int[n + 1];
        for (int i  = 1; i<=n;i++){
            list[i] = new ArrayList<>();
        }
        for(int i = 1;i<=n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int t = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            time[i] = t;
            for (int j = 0;j<k;j++){
                int p = Integer.parseInt(st.nextToken());

                list[p].add(i);
                integer[i]++;
            }
        }
        topologySort();
        System.out.println(ans);
    }
}