import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String,String> map = new HashMap<>();
        for(int i = 0;i<n;i++){
            String s = br.readLine();
            if(s.length() > 1) {
                String sort = s.substring(1, s.length() - 1);
                char[] ch = sort.toCharArray();
                Arrays.sort(ch);
                String key = s.substring(0, 1) + new String(ch) + s.substring(s.length() - 1);
                map.put(key, s);
            }
            else{
                map.put(s,s);
            }

        }
        int m = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i<m;i++){
            String s = st.nextToken();
            if(s.length()>1) {
                String sort = s.substring(1, s.length() - 1);
                char[] ch = sort.toCharArray();
                Arrays.sort(ch);
                String key = s.substring(0, 1) + new String(ch) + s.substring(s.length() - 1);
                System.out.print(map.get(key) + " ");
            }
            else{
                System.out.print(map.get(s) + " ");
            }
        }
    }
}