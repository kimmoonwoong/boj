    import java.util.*;
    import java.io.*;

    public class Main {
        static class Sort implements Comparable<Sort>{
            int index;
            int value;

            public Sort(int index, int value){
                this.index = index;
                this.value = value;
            }

            @Override
            public int compareTo(Sort o){
                return this.value - o.value;
            }
        }
        public static void main(String args[]) throws IOException, NumberFormatException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());
            int arr[] = new int[n];
            Sort sort[] = new Sort[n];
            Map<Integer, Integer> map = new HashMap<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0;i<n;i++){
                int k = Integer.parseInt(st.nextToken());

                arr[i] = k;
                sort[i] = new Sort(i, k);
                map.put(k, 0);
            }

            Arrays.sort(sort);
            int distance[] = new int[n];
            int ans[] = new int[n];
            for(int i = 0;i<n;i++) distance[i] = Math.abs(i - sort[i].index);
            for(int i = 0;i<n;i++){
                if(sort[i].value == arr[i]) continue;

                else{
                    ans[sort[i].value - 1] += distance[i];
                    ans[arr[i] - 1] += distance[i];

                    arr[sort[i].index] = arr[i];
                    sort[arr[i] - 1].index = sort[i].index;
                    distance[arr[i] - 1] = Math.abs(arr[i] - 1 - sort[arr[i] - 1].index);
                }
            }
            for(int k: ans){
                System.out.print(k + " ");
            }
        }
    }