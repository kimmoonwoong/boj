    import java.util.*;
    import java.io.*;

    public class Main {
        public static void main(String args[]) throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String s = br.readLine();
            String se[] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
            for(int i =0; i<se.length;i++){
                if(s.contains(se[i])){
                    s = s.replace(se[i], "!");
                }
            }
            System.out.println(s.length());
         }
    }
