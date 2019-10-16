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
		for (int i = 0; i < 50; ++i) System.out.println();	
		Scanner sc = new Scanner(System.in);
		int rand = (int)Math.floor(Math.random() * ( 10 - 0 ));
		int life = 10;
		String word = array[rand];
		String display="";
		char letter ;
		char[] displayChar;
		for (int i = 0; i< word.length(); i++)
		{
			display = display +"_";
		}
		displayChar = display.toCharArray();
		
		while(life>0 && !word.equals(display))
		{
			System.out.println("WORD :  "+display);
			System.out.println();
			System.out.println("You have "+life+" remaining lives");
			System.out.println("Please make a guess :");
			letter = sc.nextLine().charAt(0);
			for (int i = 0; i < 50; ++i) System.out.println();	
			if(word.indexOf(letter)>=0)
			{
				System.out.println("You found a letter !");
				for (int i = 0; i< word.length(); i++)
				{
					if(word.charAt(i)==letter)
						{
							displayChar[i] = letter;
							display = String.valueOf(displayChar);		
						}
				}
			}
			else {
				System.out.println(letter +" is not in the word, you lose a life !");
				life--;
				System.out.println();
			}	
		}
		if(word.equals(display))
		{
			System.out.println("You won ! ");
		}
		else {
			System.out.println("You lost.. ");
		}
		System.out.println();	
    }
	public static void riceBags() 
    { 
		boolean again = true;
		while(again)
		{
			again =false;
		}
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
