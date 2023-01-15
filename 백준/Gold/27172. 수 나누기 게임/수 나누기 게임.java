import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static class XY{
        int num;
        int index;

        public XY(int num, int index){
            this.num =  num;
            this.index = index;

        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<Integer, XY> map = new HashMap<>();
        int arr[] = new int[n];
        for (int i = 0;i<n;i++){
            int k = Integer.parseInt(st.nextToken());
            arr[i] = k;
            map.put(k, new XY(k,i));
        }
        int result[] = new int[n];
        for (int i = 0;i<n;i++){
            for(int j = 1; j<=Math.sqrt(arr[i]);j++){
                if(arr[i] % j == 0){
                    if(map.containsKey(j)){
                        result[map.get(j).index]++;
                        result[i]--;
                    }
                    if(j!=arr[i]/j){
                        if(map.containsKey(arr[i]/j)){
                            result[map.get(arr[i]/j).index]++;
                            result[i]--;
                        }
                    }
                }
            }
        }
        for (int i = 0;i<n;i++){
            System.out.print(result[i] + " ");
        }

    }
}