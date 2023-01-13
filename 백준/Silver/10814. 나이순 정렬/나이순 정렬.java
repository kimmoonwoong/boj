import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;
	public class Main {
		public static void main(String[] args) throws NumberFormatException, IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			Scanner s = new Scanner(System.in);
			ArrayList<ArrayList<String>> list = new ArrayList<>();
			int n = Integer.parseInt(br.readLine());
			for(int i = 0; i<n; i++) {
				String name =  br.readLine();
				String [] sa = name.split(" ");
				String age = sa[0];
				String p = sa[1];
				ArrayList<String> ag = new ArrayList<>();
				ag.add(age);
				ag.add(p);
				ag.add(String.valueOf(i));
				list.add(ag);
			}
			list.sort(new Comparator<ArrayList<String>>() {

				@Override
				public int compare(ArrayList<String> o1, ArrayList<String> o2) {
					// TODO Auto-generated method stub
					if(Integer.parseInt(o1.get(0)) == Integer.parseInt(o2.get(0))) {
						if(Integer.parseInt(o1.get(2)) == Integer.parseInt(o2.get(2))) {
							return 0;
						}
						else if(Integer.parseInt(o1.get(2)) > Integer.parseInt(o2.get(2))) {
							return 1;
						}
						else return -1;
					}
					else if(Integer.parseInt(o1.get(0)) > Integer.parseInt(o2.get(0)))
						return 1;
					else return -1;
				}
			});
			
			for(int i =0 ;i<list.size(); i++) {
				System.out.println(list.get(i).get(0) + " " + list.get(i).get(1));
			}
		}
}