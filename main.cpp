#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std; 
int Board[5][5]={{0}};
int checkx=0, checky=0; 
int sizex=5 , sizey=5;
bool lose , FirstRun; 

/*int checkBoard(int board[5][5] , int x , int y , int n)
{
	
	int i=1 , X=x;
	if(n>=0)
	{
		if (board[x][y]==board[x][y-1])
		{
			board[x][y-1]=board[x][y-2];
		}
		return(board[x][y],x,y-1,n);
		n--;
	}
	else
		return 1;

	
	
	
	if (board[x][y]==board[x][y-1] || board[x][y]==board[x][y+1] || board[x][y]==board[x+1][y] || board[x-1][y]==board[x][y])
	{
		board[x][y]=board[x][y]+1;
	}

}*/


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
	 	
		//checkBoard(Board , checkx , checky , Board[checkx][checky]);

		drawBoad(); 
		cout << endl; 
 	} 
 	
 return 0;
}

