import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int arr[];
    static int num(int i){
        int count = 0;

        for(int k = 0;k<3;k++){
            if(arr[k] == i) count++;
        }
        return i * (count + 2);
    }
    static int pedigree(int i){
        if(i < 6){
            return num(i + 1);
        }
        else if(i == 6){
            int num = 0;
            for(int j=0;j<3;j++){
                for(int k = j + 1; k<3;k++){
                    if(arr[j] == arr[k]){
                        num = arr[j];
                    }
                }
            }
            return num * 4;
        }
        else if(i == 7){
            int count = 0;
            for(int j = 0;j<3;j++){
                int cnt = 0;
                for(int k = j + 1; k<3;k++) {
                    if (arr[j] == arr[k]) {
                        cnt++;
                    }
                }
                count = Math.max(count,cnt);
            }
            if(count == 0){
                return 0;
            }
            else if(count == 1){
                int index = 0;
                int idx = 0;
                if(arr[0] == arr[1]){
                    idx = 0;
                    index = 2;
                }
                else if(arr[1] == arr[2]) {
                    idx = 1;
                    index = 0;
                }
                else if(arr[0] == arr[2]){
                    idx = 0;
                    index = 1;
                }

                if(arr[idx] < arr[index]){
                    return arr[index] * 3 + arr[idx] * 2;
                }
                else return arr[idx] * 3 + arr[index] * 2;
            }
            else{
                int k = 0;
                for (int j = 6;j>=1;j--){
                    if(arr[0] != j){
                        k = j;
                        break;
                    }
                }
                return arr[0] * 3 + k * 2;
            }
        }
        else if(i == 8){
            boolean check[] = new boolean[6];
            for(int j = 0;j<3;j++){
                if(arr[j] > 5) return 0;
                if(check[arr[j]]) return 0;
                else{
                    check[arr[j]] = true;
                }
            }
            return 30;
        }
        else if(i == 9){
            boolean check[] = new boolean[7];
            for(int j = 0;j<3;j++){
                if(arr[j] == 1) return 0;
                if(check[arr[j]]) return 0;
                else{
                    check[arr[j]] = true;
                }
            }
            return 30;
        }
        else if(i == 10){
            for(int j = 1;j<3;j++){
                if(arr[0] != arr[j]) return 0;
            }
            return 50;
        }
        else{
            return 6 * 2 + arr[0] + arr[1] + arr[2];
        }

    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        char c[] = new char[12];
        arr = new int[3];
        for(int i = 0;i<s.length();i++){
            c[i] = s.charAt(i);
        }

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0;i<3;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int max = 0;

        for(int i = 0;i<12;i++) {
            if (c[i] != 'N') {
                max = Math.max(max, pedigree(i));
            }
        }
        System.out.println(max);

    }
}