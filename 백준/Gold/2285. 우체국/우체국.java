import java.io.*;
import java.util.*;


public class Main {
    static class Village implements Comparable<Village>{
        int index;
        int people;

        public Village(int index, int people){
            this.index = index;
            this.people = people;
        }

        @Override
        public int compareTo(Village o){
            return this.index - o.index;
        }

    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Village arr[] = new Village[n];
        long total_sum = 0;
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int index = Integer.parseInt(st.nextToken());
            int people = Integer.parseInt(st.nextToken());

            arr[i] = new Village(index, people);
            total_sum += people;
        }

        Arrays.sort(arr);
        long temp = 0;
        for (int i = 0;i<n;i++){
            temp += arr[i].people;

            if (temp >= (total_sum + 1) / 2){
                System.out.println(arr[i].index);
                break;
            }
        }

    }
}