package review_1;

import java.util.Scanner;

public class Conditional {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("How old are you ? Please enter a number");
		String str = sc.nextLine();
		
		Integer age =Integer.parseInt(str);

		if(age<18)
		{
			System.out.println("You can't vote.");
		}
		else {
			System.out.println("You can vote.");
		}
		
		System.out.println("Please enter a number");
		str = sc.nextLine();
		Integer number =Integer.parseInt(str);
		
		if(number%2==0)
		{
			System.out.println("Your number is even");
		}
		else
		{
			System.out.println("Your number is not even");
		}
		  
		sc.close();
	}
}
