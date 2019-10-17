package review_1;

import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class Advanced_exercises {
	
	public static final String[] array= {"name","best","word","turned","kind","cried","since","anything","next","find","half"};
	
	public static void numberGuessing() 
    { 
		int rand = (int)Math.floor(Math.random() * ( 100 - 0 ));
		Integer guess = -1;
		for (int i=0; i<5;i++)
		{
			Scanner input = new Scanner(System.in);
			System.out.println("Please enter your guess :");
			String str = input.nextLine();
			guess =Integer.parseInt(str);
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
		if(guess!=rand)
		{
			System.out.println();
			System.out.println("You lost :c");
			System.out.println("The number was "+rand);
		}
		System.out.println();
    }
	
	public static void hangman() 
    { 
		for (int i = 0; i < 30; ++i) System.out.println();	
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
			for (int i = 0; i < 30; ++i) System.out.println();	
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
			System.out.println("You won !");
		}
		else {
			System.out.println("You lost :'c");
		}
		System.out.println();	
    }
	
	public static int riceBags (int big, int small, int kg)
    { 
		int nbSmall=0;
		while(kg!=0&&(big!=00||small!=0))
		{			
			if(kg>5&&big>0)
			{
				kg=kg-5;
				big--;
			}
			else if((kg>0&&small>0)||big==0)
			{
				kg--;
				small--;
				nbSmall++;
			}
		}
		if(kg==0)
		{
			return nbSmall;
		}
		else {
			return -1;
		}
    }
	
	public static void numberOfBags()
	{
		Scanner sc = new Scanner(System.in);
		int big, small, quantity;
		System.out.println("How many big bags do you have ?");
		big = Integer.parseInt(sc.nextLine());
		System.out.println("How many small bags do you have ?");
		small = Integer.parseInt(sc.nextLine());
		System.out.println("How much rice do you want to pack ?");
		quantity = Integer.parseInt(sc.nextLine());
		int needed =riceBags(big,small,quantity);
		if(needed==-1)
		{
			System.out.println("Impossible to package.");
		}
		else {
			System.out.println("You will need "+needed+" small bags.");
		}
	}
	
	
	public static void RPS() 
    { 
		
		char again = 'y';
		Scanner sc = new Scanner(System.in);
		int weapon=0;
		int weaponC=0;
		int matches=0;
		int score=0;
		Random rand = new Random();
		while(again=='y')
		{
			for (int i = 0; i < 30; ++i) System.out.println();
			while(!((weapon==1)||(weapon==2)||(weapon==3)))
			{
				System.out.println("Choose your weapon!");
				System.out.println("1. Paper");
				System.out.println("2. Scissors");
				System.out.println("3. Rock");
				weapon = Integer.parseInt(sc.nextLine());
			}
			if (weapon==1)
				System.out.println("You chose paper!");
			if (weapon==2)
				System.out.println("You chose scissors!");
			if (weapon==3)
				System.out.println("You chose rock!");
			weaponC = rand.nextInt(3)+1;
			if (weaponC==1)System.out.println("I chose paper!");
			if (weaponC==2)System.out.println("I chose scissors!");
			if (weaponC==3)System.out.println("I chose rock!");
			
			if(weapon==weaponC)
			{
				System.out.println("We are equally matched, You are a worthy adversary.");
			}
			else
			{
				if((weapon==1&&weaponC==3)||(weapon==2&&weaponC==1)||(weapon==3&&weaponC==2))
				{
					System.out.println("I have been vanquished !");
					score++;
				}
				else {
					System.out.println("You have been vanquished !");
				}
			}
			matches++;
			System.out.println("We have matched wits "+matches+" times, and your score is "+score);
			weapon=0;
			weaponC=0;
			System.out.println("Do you want to play again (y or n) ? ");
			sc = new Scanner(System.in);
			again = sc.nextLine().charAt(0);
		}
    }
	
	
	
	
	
	public static void main(String[] args) {
		boolean again=true;
		while(again)
		{
			for (int i = 0; i < 30; ++i) System.out.println();
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
				numberOfBags();
				break;
			case '4':
				RPS();
				break;
			default:
			    System.out.println("Not a good entry");
			}
			System.out.println("Play another game (y or n)? ");
			choice = sc.nextLine().charAt(0);
			if (choice=='n')
			{
				again=false;
			}
		}	
	}
}
