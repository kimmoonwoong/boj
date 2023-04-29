import java.util.*;
import java.io.*;

public class Main {
    static int parent[] = new int[1000001];
    static int cnt[] = new int[1000001];
    static int find(int x){
        if (parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }
    static void union(int x, int y){
        x = find(x);
        y = find(y);

        if (x == y) return;

        parent[x] = y;
        cnt[y] += cnt[x];
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        for(int i = 0;i<1000001;i++){
            parent[i] = i;
            cnt[i] = 1;
        }
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int a = Integer.parseInt(st.nextToken());
            if (s.equals("I")){
                int b = Integer.parseInt(st.nextToken());
                union(a,b);
            }
            else {
                sb.append(cnt[find(a)]).append("\n");
            }
        }
        System.out.println(sb);

    }
}