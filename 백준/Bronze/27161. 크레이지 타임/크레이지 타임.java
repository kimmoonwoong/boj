import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int num = 0;
        boolean isCheck = false;
        StringBuilder sb = new StringBuilder();
        int time[] = {1,2,3,4,5,6,7,8,9,10,11,12};
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            String s = st.nextToken();
            int k = Integer.parseInt(st.nextToken());

            if(k == time[num] && !s.equals("HOURGLASS")){
                sb.append(time[num]+ " " + "YES").append("\n");
            }
            else{
                sb.append(time[num] + " " + "NO").append("\n");
            }

            if(k == time[num] && s.equals("HOURGLASS")){
                if(!isCheck){
                    if(num + 1 > 11) num = 0;
                    else num++;
                }
                else{
                    if(num - 1 < 0) num = 11;
                    else num--;
                }
                continue;
            }
            else if(s.equals("HOURGLASS")){
                isCheck = !isCheck;
            }

            if(!isCheck){
                if(num + 1 > 11) num = 0;
                else num++;
            }
            else{
                if(num - 1 < 0) num = 11;
                else num--;
            }
        }
        System.out.println(sb);
    }
}