package review_1;

import java.util.Scanner;

public class Loop {
	
	public static void print2D(int matrix[][]) 
    { 
        for (int i = 0; i < matrix.length; i++) 
        {
        	for (int j = 0; j < matrix[i].length; j++) 
        	{
        		System.out.print(matrix[i][j] + " "); 
        	}
            System.out.println();
        }
    }
	
	public static void triangle() 
    { 
		Scanner sc = new Scanner(System.in);
		System.out.println("Number of lines ?");
		String str = sc.nextLine();
		
		Integer n =Integer.parseInt(str);
		int test=1;
		for(int i=1;i<n+1;i++)
		{
			for(int j=n-i;j>0;j--)
				System.out.print(" ");
			for(int j=0;j<test;j++)
				System.out.print("*");	
			System.out.println();	
			test=test+2;
		}
    }
    public static void transpose2D(int matrix[][]) 
    { 
    	int transpose[][]=new int[3][3];
        for (int i = 0; i < matrix.length; i++) 
        {
        	for (int j = 0; j < matrix[i].length; j++) 
        	{
        		transpose[i][j]=matrix[j][i];  
           	}
        }     
        for (int i = 0; i < transpose.length; i++) 
        {
        	for (int j = 0; j < transpose[i].length; j++) 
        	{
        		System.out.print(transpose[i][j] + " "); 
        	}
            System.out.println();
        }
  
    } 
	
	public static void main(String[] args) {
		
		for (int i=1;i<100 ;i=i+2)
		{
			System.out.println(i);
		}
		
		int matrix[][] = {{ 1, 2, 3},{5, 6, 7},{ 9, 10, 11}}; 
		print2D(matrix);
		System.out.println();
		transpose2D(matrix);
		System.out.println();
		triangle();
	}
}
