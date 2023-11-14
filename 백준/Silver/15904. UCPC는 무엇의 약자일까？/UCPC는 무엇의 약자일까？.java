    import java.io.*;
    import java.util.*;

    public class Main {
        public static void main(String[] args) throws NumberFormatException, IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String s = br.readLine();

            String se[] = s.split("");
            int in = 0;
            for (String s1 : se){
                if (in == 0 && s1.equals("U")) in++;
                else if ((in == 1 || in == 3) && s1.equals("C")) in++;
                else if (in == 2 && s1.equals("P")) in++;
            }

            if (in == 4) System.out.println("I love UCPC");
            else System.out.println("I hate UCPC");
        }
    }