import java.util.*;
import java.io.*;

public class Main {
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        List<Integer> list1 = new ArrayList<>();
        List<Integer> arr = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0;i<k;i++){
            arr.add(Integer.parseInt(st.nextToken()));
        }
        List<Integer> list = new ArrayList<>();
        int ans = 0;
        for (int i = 0;i<k;i++){

            if (list.indexOf(arr.get(i)) !=  -1) {
                continue;
            }
            if (list.size() < n){
                list.add(arr.get(i));
                continue;
            }

            int temp = 0;
            int index = 0;
            for (int curr: list){
                boolean isCheck = false;
                int indexcheck = 0;
                for (int j = i;j<k;j++){
                    if (curr == arr.get(j)){
                        isCheck = true;
                        indexcheck = j;
                        break;
                    }
                }
                if (!isCheck){
                    temp = curr;
                    break;
                }
                else if(indexcheck > index){
                    index = indexcheck;
                    temp = curr;
                }
            }
            list.set(list.indexOf(temp), arr.get(i));
            ans++;
        }
        System.out.println(ans);
    }
}
