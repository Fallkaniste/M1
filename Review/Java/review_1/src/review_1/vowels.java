package review_1;

import java.util.Scanner;

public class vowels {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter somthing to remove the vowels from");
	String str = sc.nextLine();
	System.out.println("You entered " + str);
	
	String strNew = str.replaceAll("[a,e,i,o,u,y]", "");

	System.out.println("THis is what you entered withour vowels : "+strNew);
	}
}
