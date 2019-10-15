package review_1;

import java.io.IOException;
import java.util.Scanner;

public class Advanced_exercises {
	
	public static final String[] array= {"name","best","word","turned","kind","cried","since","anything","next","find","half"};
	
	public static void numberGuessing() 
    { 
		int rand = (int)Math.floor(Math.random() * ( 100 - 0 ));
		for (int i=0; i<5;i++)
		{
			Scanner input = new Scanner(System.in);
			System.out.println("Please enter your guess :");
			String str = input.nextLine();
			Integer guess =Integer.parseInt(str);
			if(guess > rand){
				System.out.println("Too high !");
			}
			if(guess < rand){
				System.out.println("Too low !");
			}
			if (rand==guess) {
				System.out.println("You won !");
				break;
			}			
		}
		System.out.println("You lost :c");
    }
	
	public static void hangman() 
    { 
		
    }
	public static void riceBags() 
    { 
		
    }
	public static void RPS() 
    { 
		
    }
	public static void main(String[] args) {
		boolean again=true;
		while(again)
		{
			for (int i = 0; i < 50; ++i) System.out.println();
			System.out.println("Please choose a game :");
			System.out.println("1- Number Guessing Game");
			System.out.println("2- Hangman");
			System.out.println("3- Rice Bags");
			System.out.println("4- Rock-Paper-Scissors");
			System.out.println();
			
			Scanner sc = new Scanner(System.in);
			char choice = sc.nextLine().charAt(0);
			switch(choice)
			{
			case '1':
				numberGuessing();
				break;
			case '2':
				hangman();
				break;
			case '3':
				riceBags();
				break;
			case '4':
				RPS();
				break;
			default:
			    System.out.println("Not a good entry");
			}
			System.out.println("Continue ? (y/n)");
			choice = sc.nextLine().charAt(0);
			if (choice=='n')
			{
				again=false;
			}
		}	
	}
}
