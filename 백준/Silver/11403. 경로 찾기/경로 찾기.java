import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int map[][]= new int[n][n];
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0;j<n;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                for (int k = 0;k<n;k++){
                    if (map[j][i] == 1 && map[i][k] == 1){
                        map[j][k] = 1;
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();

        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                sb.append(map[i][j] + " ");
            }
            sb.append("\n");
        }
        System.out.println(sb);

    }
}