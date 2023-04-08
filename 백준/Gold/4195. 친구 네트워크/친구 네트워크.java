import java.util.*;
import java.io.*;

public class Main {
    static int parent[];
    static int count[];
    static int find(int x){
        if (x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }
    static void union(int x, int y){
        x = find(x);
        y = find(y);

        if (x!=y){
            if (x < y) {
                parent[y] = x;
                count[x] += count[y];
            }
            else{
                parent[x] = y;
                count[y] += count[x];
            }
        }
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            Map<String, Integer> map = new HashMap<>();
            parent = new int[2 * n];
            count = new int[2 * n];
            int num = 0;
            for (int i = 0;i<n;i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();

                if (!map.containsKey(a)){
                    map.put(a, num);
                    count[num] = 1;
                    parent[num] = num;
                    num++;
                }
                if (!map.containsKey(b)){
                    map.put(b, num);
                    count[num] = 1;
                    parent[num] = num;
                    num++;
                }

                union(map.get(a), map.get(b));
                int index = find(map.get(a));
                sb.append(count[index]).append("\n");
            }
        }
        System.out.println(sb);
    }
}
