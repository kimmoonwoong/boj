import java.util.*;
import java.io.*;

public class Main {
    static class Sort implements Comparable<Sort>{
        int solve;
        String name;

        public Sort(int solve, String name){
            this.solve = solve;
            this.name = name;
        }

        @Override
        public int compareTo(Sort o){
            return o.solve - this.solve;
        }
    }
    public static void main(String args[]) throws IOException, NumberFormatException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int y[] = new int[3];
        Sort sort[] = new Sort[3];
        for(int i = 0;i<3;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int solve = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            String name = st.nextToken();
            sort[i] = new Sort(solve, name);
        }

        Arrays.sort(y);
        Arrays.sort(sort);

        System.out.println(y[0] % 2000 + "" + y[1] % 2000 + "" + y[2] % 2000);
        System.out.println(sort[0].name.charAt(0) + "" + sort[1].name.charAt(0) + "" + sort[2].name.charAt(0));
    }
}