package review_1;
import java.util.Scanner; 

public class Keyboard_input {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("What's your name ?");
		String str = sc.nextLine();
		
		System.out.println("Hello " + str+"!");
		
		System.out.println("Give an index (int) :");
		String index = sc.nextLine();
	
		char ch = str.charAt(Integer.parseInt(index));
		System.out.println("The character at index "+str+" is " +ch);
		
		sc.close();
		}
}






