import java.util.*;
import java.io.*;
public class Main {
    static List<Integer> list[];
    static int count[];
    static String check[];
    static long DFS(int node){
        long sum = 0;
        for (int next: list[node]){
            sum += DFS(next);
        }
        if(node == 1) return sum;

        if(check[node].equals("S")){
            return sum+count[node];
        }
        else {
            return sum - count[node] < 0 ? 0 : sum - count[node];
        }
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        list = new ArrayList[n + 1];
        count = new int[n + 1];
        check = new String[n + 1];
        for(int i = 1;i<=n;i++) list[i] = new ArrayList<>();
        for(int i = 2;i<=n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            String s = st.nextToken();
            int counts = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());

            check[i] = s;
            count[i] = counts;
            list[next].add(i);
        }
        long ans = DFS(1);
        System.out.println(ans);
    }
}