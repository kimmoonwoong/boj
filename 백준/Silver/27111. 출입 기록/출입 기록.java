import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Map<Integer, Integer> map = new HashMap<>();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(map.containsKey(a)){
                if(b == 0){
                    if(map.get(a) == 0) cnt++;
                    else map.replace(a, 0);
                }
                else{
                    if(map.get(a) == 0) map.replace(a,1);
                    else cnt++;
                }
            }
            else{
                if(b == 0) cnt++;
                else{
                    map.put(a,1);
                }
            }
        }

        for(int key: map.keySet()){
            if(map.get(key) == 1) cnt++;
        }
        System.out.println(cnt);
    }
}