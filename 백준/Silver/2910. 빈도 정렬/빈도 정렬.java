import java.io.*;
import java.util.*;

public class Main {
    static class Sort implements Comparable<Sort>{
        int index;
        int k;
        int cnt;

        public Sort(int index, int cnt, int k){
            this.index = index;
            this.cnt = cnt;
            this.k = k;
        }

        @Override
        public int compareTo(Sort o){
            if (this.cnt == o.cnt) return this.index - o.index;
            else return o.cnt - this.cnt;
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        Map<Integer, Sort> map = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0;i<n;i++){
            int k = Integer.parseInt(st.nextToken());

            if (map.containsKey(k)) map.get(k).cnt++;
            else map.put(k,new Sort(i,1,k));
        }
        List<Sort> list = new ArrayList<>();
        for (Sort s: map.values()){
            list.add(s);
        }
        Collections.sort(list);
        for (Sort s : list){
            for (int i = 0;i<s.cnt;i++){
                System.out.print(s.k + " ");
            }
        }
    }
}