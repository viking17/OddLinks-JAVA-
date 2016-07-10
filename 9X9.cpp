#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define x 30
#define y 30
//connect first to win the game
using namespace std;




void display(char a[x][y])
{

    printf("\033[2J\033[1;1H");

  for(int i =0;i<=x-1;i++)
  {
      if(i<9)
      cout<<"0"<<i+1<<" ";
      else
      cout<<i+1<<" ";
    for(int j =0;j<=y-1;j++)
    {
      cout<<a[i][j]<<"  ";
    }

    cout<<endl;
  }
  for(int i =0;i<=y-1;i++)
  {
    if(i<=9)
    cout<<"0"<<i<<" ";
    else
    cout<<i<<" ";
  }

  cout<<y<<endl;
}
void check(int b[x][y],int n)
{
  int l,m;
  for(l =(n-1)/2;l<=x-(n-1)/2;l++)
  {
    for(m=0;m<=y-1;m++)
    {//checking for column
      int row_sum = 0;// b[l][m]+b[l-1][m]+b[l-2][m]+b[l+1][m]+b[l+2][m];
      for(int a = -(n-1)/2;a<=(n-1)/2;a++)
      {
        row_sum += b[l+a][m];
      }
      if(row_sum == n*1||row_sum == n*(n+1))
      {
        if(row_sum == n*1)
        {
          cout<<"Player1 wins by column"<<endl;
        }

        else
        {
          cout<<"Player2 wins by column"<<endl;
        }

      }

    }
  }

  for(l =0;l<=x-1;l++)
  {
    for(m=(n-1)/2;m<=y-(n-1)/2;m++)
    {//checking for row
    int col_sum = 0;//b[l][m]+b[l][m-1]+b[l][m-2]+b[l][m+1]+b[l][m+2];
      for(int a = -(n-1)/2;a<=(n-1)/2;a++)
      {
        col_sum += b[l][m+a];
      }
      if(col_sum == n*1||col_sum == n*(n+1))
      {
        if(col_sum == n)
        {
          cout<<"Player1 wins by row"<<endl;
        }

        else
        {
          cout<<"Player2 wins by row"<<endl;
        }

      }

    }
  }

  for(l =(n-1)/2;l<=x-(n-1)/2;l++)
  {
    for(m=(n-1)/2;m<=y-(n-1)/2;m++)
    {//checking for fdiagonal

      int fd_sum=0;// = b[l][m]+b[l-1][m-1]+b[l-2][m-2]+b[l+1][m+1]+b[l+2][m+2];
      for(int a = -(n-1)/2;a<=(n-1)/2;a++)
      {
        fd_sum += b[l+a][m+a];
      }
      if(fd_sum == n||fd_sum == n*(n+1))
      {
        if(fd_sum == n)
        {
          cout<<"Player1 wins by frontdiagonal"<<endl;
        }

        else
        {
          cout<<"Player2 wins by frontdiagonal"<<endl;
        }

      }

    }
  }

  for(l =(n-1)/2;l<=x-(n-1)/2;l++)
  {
    for(m=(n-1)/2;m<=y-(n-1)/2;m++)
    {//checking for bdiagonal
      int bd_sum = 0;
      //b[l][m]+b[l-1][m+1]+b[l-2][m+2]+b[l+1][m-1]+b[l+2][m-2];
      for(int a = -(n-1)/2;a<=(n-1)/2;a++)
      {
        bd_sum += b[l-a][m+a];
      }
      if(bd_sum == n||bd_sum == n*(n +1))
      {
        if(bd_sum== n)
        {
          cout<<"Player1 wins by backdiagonal"<<endl;
        }

        else
        {
          cout<<"Player2 wins backdiagonal"<<endl;
        }

      }

    }
  }
}





int main()
{

  char a[x][y];
  int b[x][y];

    for(int i =0;i<=x-1;i++)
    {
      for(int j =0;j<=y-1;j++)
      {
          a[i][j] = '-';
      }

    }

      for(int i =0;i<=x-1;i++)
        for(int j =0;j<=y-1;j++)
        b[i][j] = 0;

      cout<<"INSTRUCTIONS__"<<endl;
      cout<<"Player 1 takes O"<<endl;
      cout<<"Player 2 takes X"<<endl;

      cout<<"10 is represented by 01 10"<<endl;
      cout<<"ex -> - - - - - - - - - 10"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"      - - - - - - - - - -"<<endl;
      cout<<"here the third square is marked 10"<<endl;
      cout<<"Player1's turn"<<endl;
      int n;
      printf("Press odd number links to connect\n");
      cin>>n;
        printf("\033[2J\033[1;1H");
  int chance1;
  int chance2;
  for(int i =1;i<=x*y; i++)
  {
    cin>>chance1>>chance2;
  /*  if(chance1 <1 || chance1>x)
    {
      cout<<"enter again"<<endl;
      cin>>chance1;
    }

    if(chance2 <1 || chance2>x)
    {
      cout<<"enter again"<<endl;
      cin>>chance2;
    }*/
    int k,j;
    //j = (chance-1)/y;
    //k = (chance-1)%y;
    j = chance1-1;
    k = chance2 - 1;


    if(i%2==0)
    {
      if(b[j][k] != 0 )
      {

        cout<<"enter another index"<<endl;
        i--;
      }
      else
      {
        a[j][k] = 'X';
        b[j][k] = n+1;
        display(a);
      }
    }
    else
    {
      if(b[j][k] != 0 )
      {

        cout<<"enter another index"<<endl;
        i--;
      }
      else
      {
        a[j][k] = 'O';
        b[j][k] =1;
        display(a);
      }
    }
    check(b,n);

  }
  for(int i =0;i<=x-1;i++)
  {
    for(int j =0;j<=y-1;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}
