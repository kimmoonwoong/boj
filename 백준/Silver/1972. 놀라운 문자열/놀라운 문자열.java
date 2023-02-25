import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true){
            String s = br.readLine();
            if (s.equals("*")) break;
            boolean isCheck = false;
            for (int i = 1;i<s.length() - 1; i++){
                Map<String, Integer> map = new HashMap<>();

                for (int j = 0;j<s.length() - i;j++){
                    String k = s.substring(j, j + 1) + s.substring(j + i, j+ i+1);
                    if (map.containsKey(k)){
                        sb.append(s + " is NOT surprising.").append("\n");
                        isCheck = true;
                        break;
                    }
                    else{
                        map.put(k, 1);
                    }
                }
                if (isCheck) break;
            }

            if (!isCheck){
                sb.append(s + " is surprising.").append("\n");
            }
        }
        System.out.println(sb);



    }
}