import java.io.IOException;
import java.util.*;





public class OddLinks {
	public static void main(String args[]) throws IOException
	{
		 final int x =30;
		 final int y= 30;



		char [][] a = new char[x][y];
		int [][] b= new int[100][100];



		for(int i = 0;i<=x-1;i++)
			for(int j =0;j<=y-1;j++)
		{
			a[i][j] = '-';
		}


	for(int i = 0;i<=x-1;i++)
		for(int j =0;j<=y-1;j++)
			b[i][j] = 0;

	System.out.println("INSTRUCTIONS---");
	System.out.println("PLAYER1 TAKES X");
	System.out.println("PLAYER2 TAKES O");

	System.out.println("10 is represented by 01 10");
	System.out.println("ex->- - - - - - - - - 10");
	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");

	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");
	System.out.println("ex->- - - - - - - - - -");

	System.out.println("here the third square is marked 10");
	System.out.println("Player1's turn");

	int n;
	Scanner stdin = new Scanner(System.in);

	System.out.println("Press odd number links to connect ");
	n = stdin.nextInt();

//	System.out.println("\0333[2J\033[1;1H");
final String ANSI_CLS = "\u001b[2J";
final String ANSI_HOME = "\u001b[H";
System.out.print(ANSI_CLS + ANSI_HOME);
System.out.flush();
	int chance1,chance2;

	for(int i =0;i<=x*y-1;i++)
	{
		chance1 = stdin.nextInt();
		chance2 = stdin.nextInt();

		int k,j;

		j = chance1-1;
		k = chance2-1;

		if(i%2 == 0)
		{
			if(b[j][k] !=0)
			{
				System.out.println("enter another index");
				i--;

			}
			else
			{
				a[j][k] = 'X';
				b[j][k] = n+1;
				display(a,x,y);
			}
		}
		else
		{
			if(b[j][k]!=0)
			{
				System.out.println("enter another index");
				i--;
			}
			else
			{
				a[j][k]='O';
				b[j][k]=1;
				display(a,x,y);
			}
		}
		check(b,n,x,y);
	}

	for(int i =0;i<=x-1;i++)
	{
		for(int j =0;j<=y-1;j++)
		{
			System.out.print(a[i][j]+" ");

		}
		System.out.println("");
	}


}



	private static void check(int[][] b, int n,int x,int y) {
		// TODO Auto-generated method stub

		int l,m;
		//checking for column
		for(l = (n-1)/2;l<=x-(n-1)/2;l++)
		{
			for(m=0;m<=y-1;m++)
			{
				int row_sum = 0;
				for(int a = -(n-1)/2;a<=(n-1)/2;a++)
				{
					row_sum += b[l+a][m];
				}

				if(row_sum == n || row_sum == n*(n+1))
				{
					if(row_sum == n)
					{
						System.out.println("Player2 wins by column");

					}
					else
						System.out.println("Player1 wins by column");
				}
			}
		}

	//checking for row
		for(l=0;l<=x-1;l++)
		{
			for(m = (n-1)/2;m<=y-(n-1)/2;m++)
			{
				int col_sum = 0;
				for(int a = -(n-1)/2;a<=(n-1)/2;a++)
				 {
					col_sum += b[l][m+a];
				 }


			if(col_sum == n || col_sum == n*(n+1))
			{
				if(col_sum == n)
					{
						System.out.println("Player2 wins by row");
					}
				else
					{
						System.out.println("Player1 wins by row");
					}

			}
			}
		}

		//check for fdiagonal
		//
		for(l = (n-1)/2;l<=x-(n-1)/2;l++)
		{
			for(m = (n-1)/2;m<=y-(n-1)/2;m++)
			{
				int fd_sum = 0;

				for(int a = -(n-1)/2;a<=(n-1)/2;a++)
				{
					fd_sum += b[l+a][m+a];
				}

				if(fd_sum == n || fd_sum == n*(n+1))
				{
					if(fd_sum == n)
					{
						System.out.println("Player2 wins by front diagonal");
					}
					else
					{
						System.out.println("Player1 wins by front diagonal");
					}
				}
			}

		}

		//check for bdiagonal

		for(l= (n-1)/2;l<=x-(n-1)/2;l++)
		{
			for(m = (n-1)/2;m<=y-(n-1)/2;m++)
			{
				int bd_sum = 0;

				for(int a= -(n-1)/2;a<=(n-1)/2;a++)
				{
					bd_sum += b[l-a][m+a];
				}
				if(bd_sum == n || bd_sum == n*(n+1))
				{
					if(bd_sum == n)
					{
						System.out.println("Player2 wins by back diagonal");
					}

				else
				{
					System.out.println("Player1 wins by back diagonal");
				}
			}
			}
		}



	}

	private static void display(char[][] a,int x,int y) {
		// TODO Auto-generated method stub
	//	System.out.println("\0333[2J\033[1;1H");
	final String ANSI_CLS = "\u001b[2J";
final String ANSI_HOME = "\u001b[H";
System.out.print(ANSI_CLS + ANSI_HOME);
System.out.flush();
		for(int i=0;i<=(x-1);i++)
		{
			if(i<9)
			{
				System.out.print("0"+(i+1)+"  ");
			}
			else
				System.out.print((i+1)+"  ");

			for(int j=0;j<=y-1;j++)
			{
				System.out.print(a[i][j]+"  ");
			}
			System.out.println("");
}

		for(int i =0;i<=(y-1);i++)
		{
			if(i<=9)
				System.out.print("0"+i+" ");
			else
				System.out.print(i+" ");
		}
		System.out.print(y);
		System.out.println("");

}

}
