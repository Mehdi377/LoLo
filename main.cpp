#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std; 
int Board[5][5]={{0}};
int target[5][5]={{0}};
int checkx=0, checky=0; 
int sizex=5 , sizey=5;
bool lose , FirstRun; 

int check(int board[5][5] , int x , int y)
{
	
for (int i = x - 1; i <= x + 1 ; i++)
	{
		for (int j = y - 1; j <= y + 1 ; j++)
		{
			target[i][j]=1;
			if(board[i][j]==-1)
				continue;
			if (i < 0)
				continue;
			if (i >= 5)
				continue;
			if (j < 0)
				continue;
			if (j >= 5)
				continue;
			if (i==x-1 && j==y-1)
				continue;
			if (i==x-1 && j==y+1)
				continue;
			if (i==x+1 && j==y-1)
				continue;
			if (i==x+1 && j==y+1)
				continue;
			if (i==x && j==y)
				continue;
		
			if(board[i][j]==board[x][y])
				board[i][j]=-1;

			if(target[i][j]!=1)
				check(board , i , j);
		}
	}
	
}


void drawBoad() 
{ 
	int r1=rand() % 5 ,r2=4;  //for one 6
	
	int firstboard[5][5]={{rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1},
						 {rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1},
						 {rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1},						
						 {rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1},						
						 {rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1}};
						 
		firstboard[r1][r2]=6;  //for one 6
			 				
	if (FirstRun==false)  //for first run
	{
	memcpy(Board, firstboard, sizeof(Board));  //copy firstboard to Board
	}
 
	cout << " _"; //This draws the top line

	for (int i = 0; i < sizex; i++) 
	{ 
		cout << i << "_"; 
	} 
	cout << endl; 

	for (int y = 0; y < sizey; y++) 	//This draws the body 
	{ 
		cout << y << "|"; 
		for (int x = 0; x < sizex; x++) 
		{ 
			cout <<Board[x][y]<< "|";
		}
		cout << endl; 
	}
}




int main() 
{ 
	
FirstRun=false;
srand ( time(NULL) );
lose = false;

 
 
drawBoad(); 
FirstRun=true;
cout << endl; 
while (lose != true) 

	{ 
		
		cout << "Input x grid to check." << endl; 
		cin >> checkx; 
		cout << endl << "Input y grid to check." << endl; 
		cin >> checky; 
	 	
		check(Board , checkx , checky);

		drawBoad(); 
		cout << endl; 
 	} 
 	
 return 0;
}
