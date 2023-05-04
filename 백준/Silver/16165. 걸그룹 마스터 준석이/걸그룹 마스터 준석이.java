import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        Map<String, List<String>> group = new HashMap<>();
        Map<String, String> member = new HashMap<>();

        for (int i = 0;i<n;i++){
            String groupname = br.readLine();
            int m = Integer.parseInt(br.readLine());
            List<String> list = new ArrayList<>();
            for (int j = 0;j<m;j++){
                String membername = br.readLine();
                list.add(membername);
                member.put(membername, groupname);
            }
            Collections.sort(list);
            group.put(groupname, list);
        }
        for (int i = 0;i<k;i++){
            String s = br.readLine();
            int m = Integer.parseInt(br.readLine());
            if (m == 1){
                sb.append(member.get(s)).append("\n");
            }
            else {
                List<String> list = group.get(s);
                for (String membername: list){
                    sb.append(membername).append("\n");
                }
            }
        }
        System.out.println(sb);
    }
}