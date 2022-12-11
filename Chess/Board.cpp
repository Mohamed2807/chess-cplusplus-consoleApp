#include<iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;

class ChessBoard
{
	string row[8]={"8","7","6","5","4","3","2","1"};
	string column[8]={"a","b","c","d","e","f","g","h"};
	string whitePieces[8]={"wR1","wKn1","wB1","wQ","wK","wB2","wKn2","wR2"};
	string blackPieces[8]={"bR1","bKn1","bB1","bQ","bK","bB2","bKn2","bR2"};
	string whitepan[8]={"wP1","wP2","wP3","wP4","wP5","wP6","wP7","wP8"};
	string blackpan[8]={"bP1","bP2","bP3","bP4","bP5","bP6","bP7","bP8"};
	
	int count1;
	public:
	string board[10][10];
	ChessBoard()
	{
		
	}
	void set()
	{
		char symbol='X';
		for(int i=0;i<10;i++)
		{
			if(i<9)
			{
				if(0<i)
					{
					board[i][0]=row[i-1];
					board[i][9]=row[i-1];
					}
			}
			count1=0;
			for(int j=1;j<9;j++)
			{
				if(i==0)
				{
					board[i][j]=column[count1];count1++;
				}
				else if(i==9)
				{
					board[i][j]=column[count1];count1++;
				}
				else if(i==8)
				{
					
					
					board[i][j]=whitePieces[count1];count1++;
				}else
				if(i==2)
				{
					board[i][j]=blackpan[count1];count1++;
				}else
				if(i==7)
				{
					board[i][j]=whitepan[count1];count1++;
				}else
				if(i==1)
				{
					board[i][j]=blackPieces[count1];count1++;
				}else
				board[i][j]=symbol;
			}
		}
	}
	
	void whiteShow()
	{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
 
	/*	for(int i=0;i<10;i++)
		{
			
			
			cout<<"\n\n\n";
			for(int j=0;j<10;j++)
			{	
				if(i==0){
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout<<"\t"<<board[i][j];
				}else if(i==9){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout<<"\t"<<board[i][j];
					}else if(i%2==0)
					{ 
					cout<<"\t"<<board[i][j];j++;
				
					for(int k=0;k<8;k++)
						{
							if(board[i][j]==whitePieces[k])
							{
						
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout<<"\t"<<board[i][j];
							}else if(board[i][j]==blackPieces[k])
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout<<"\t"<<board[i][j];
							}
							
							
							
						}
						if(board[i][j]==pan[0])
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
								cout<<"\t"<<board[i][j];
							}
							else if(board[i][j]==pan[1])
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
								cout<<"\t"<<board[i][j];
							}
							else if(j%2==1)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout<<"\t"<<board[i][j];
							}else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
							cout<<"\t"<<board[i][j];
							}
						//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						//cout<<"\t"<<board[i][j];j++;
				
						
						
					}
			
					else if(i%2==1)
					{
						cout<<"\t"<<board[i][j];j++;
						 
							for(int k=0;k<8;k++)
						{
							if(board[i][j]==whitePieces[k])
							{
						
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout<<"\t"<<board[i][j];
							}else if(board[i][j]==blackPieces[k])
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
							cout<<"\t"<<board[i][j];
							}
							
							
							
						}
						if(board[i][j]==pan[0])
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
								cout<<"\t"<<board[i][j];
							}
							else if(board[i][j]==pan[1])
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
								cout<<"\t"<<board[i][j];
							}
							else if(j%2==1)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						cout<<"\t"<<board[i][j];
							}
							else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
							cout<<"\t"<<board[i][j];j++;
							}
						
						//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						//cout<<"\t"<<board[i][j];
						
					} 
					
			
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					
			}
			
		}	*/
		cout<<"\n\n\n\n\n";

				for(int i=0;i<10;i++)
				{
					cout<<"\n\n\n\n";
					for(int j=0;j<10;j++)
					{
						cout<<"\t"<<board[i][j];
					}
				}
	}
	void blackShow()
	{
		
		cout<<"\n\n\n\n\n";

				for(int i=9;i>=0;i--)
				{
					cout<<"\n\n\n\n";
					for(int j=0;j<10;j++)
					{
						cout<<"\t"<<board[i][j];
					}
				}
	}
	
	void change(int initial,int end,int check)
	{
		string temp;
		int inicol;
		int inirow;
		int endcol;
		int endrow;
		
		int indexcount=0;
	    int endcount=0;
	
	string indexPieces="";
	string movepieces="";
	for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
				
				if(initial==indexcount)
				{
					indexPieces=board[i][j];
				}
				if(end==endcount)
				{
					movepieces=board[i][j];
				}
				indexcount++;endcount++;
			}
		}
		/*for(int i=0;i<10;i++)
		{
			if(column[i]==inicols){inicol=i+1;cout<<i+1;}
			if(column[i]==endcols){endcol=i+1;cout<<i+1;}
			if(row[i]==inirows){inirow=i+1;cout<<i+1;}
			if(row[i]==endrows){endrow=i+1;cout<<i+1;}
		}
		temp=board[inirow][inicol];
		board[inirow][inicol]=board[endrow][endcol];
		board[endrow][endcol]=temp;*/
		if(check==0){movepieces="X";}
		else{}
		indexcount=0;endcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
				
				if(initial==indexcount)
				{
					board[i][j]=movepieces;
				}
				if(end==endcount)
				{
					board[i][j]=indexPieces;
				}
				indexcount++;endcount++;
			}
		}
		cout<<endl<<movepieces<<indexPieces;
		//system("cls");
		 

		
		
	}
	
	int findPieces(string piece)
	{
		int count1=0;
		int flag=0;
	
		for(int i=0;i<10;i++)
		{
			
			for(int j=0;j<10;j++)
			{
				
				if(board[i][j]==piece)
				{
					flag=1;
				
							
				}
				if(flag==0)
				count1++;
						
						
			}
		}
				
				//cout<<count1;
				return count1;
	}
	int movecheck(string index)
	{
		int count1=0;
		int row=0,col=0;
		int flag=0;
		string demo="";
		
		
		for(int i=0;i<10;i++)
		{
				
			for(int j=0;j<10;j++)
			{
				demo="";
				demo+=index[0];
				if(board[i][j]==demo){
					row=j;}
				demo="";
				demo+=index[1];
				if(board[i][j]==demo){
					
					col=i*10;}
						
			}
		}
		
		return col+row;
		
	}
	
	
	void pawn(string piece,string move)
	{
	
	int initialIndex=0;
	int index=findPieces(piece);
	int end=movecheck(move);
	int endcount=0;
	int indexcount=0;
	int check = end-index;
	string movepieces="";
	string type="";

	endcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
					if(index==indexcount)
				{
					type=board[i][j];
				}
				
				
				if(end==endcount)
				{
					movepieces=board[i][j];
				}
				endcount++;indexcount++;
			}
		}
		if(type[0]=='w'){
			
				if(check==-20)
				{
					if(index>70)
					{	if(movepieces=="X")
					change(index,end,1);
					else 
					cout<<"invalid move";
					}
				else{cout<<"invalid move";}
			}else if(check==-10)
			{
				if(movepieces=="X")
				change(index,end,1);
			else 
				cout<<"invalid move";
		
			}
			else if(check==-9)
			{
				if(movepieces!="X")
				change(index,end,0);
			else 
				cout<<"invalid move";
			
			}
				else if(check==-11)
				{
				if(movepieces!="X")
				change(index,end,0);
					else
					cout<<"invalid move";
				}
			else 
			{
			cout<<"invalid move";
			}
			}else
			
			if(type[0]=='b'){
				if(check==20)
				{
					if(index<30)
					{if(movepieces=="X")
					change(index,end,1);
					else 
					cout<<"invalid move";
					}
				else{cout<<"invalid move";}
			}else
		
			if(check==10)
			{
				if(movepieces=="X")
				change(index,end,1);
			else 
				cout<<"invalid move";
		
			}
			else if(check==9)
			{
				if(movepieces!="X")
				change(index,end,0);
			else 
				cout<<"invalid move";
			
			}
				else if(check==11)
				{
				if(movepieces!="X")
				change(index,end,0);
					else
					cout<<"invalid move";
				}
			else 
			{
			cout<<"invalid move";
			}
			}
	
	
	
	
	
	}
	
	void knight(string piece,string move)
	{
	
	int initialIndex=0;
	int index=findPieces(piece);
	int end=movecheck(move);
	int endcount=0;
	int indexcount=0;
	int check = end-index;
	string movepieces="";
	string type="";

	endcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
					if(index==indexcount)
				{
					type=board[i][j];
				}
				
				
				if(end==endcount)
				{
					movepieces=board[i][j];
				}
				endcount++;indexcount++;
			}
		}
		if(type[0]=='w'){
			
							if(check==-21)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else if(movepieces!="X")
									change(index,end,0);
		
									}
									else if(check==-19)
										{
										if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else if(movepieces!="X")
									change(index,end,0);
									
			
									}
									else if(check==21)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
												else
									if(movepieces!="X")
									change(index,end,0);}
									else if(check==19)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else
									if(movepieces!="X")
									change(index,end,0);
									
									}else if(check==-12)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else if(movepieces!="X")
										change(index,end,0);
							
									}else if(check==-8)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else if(movepieces!="X")
										change(index,end,0);
					
									}else if(check==12)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else if(movepieces!="X")
										change(index,end,0);
							
									}else if(check==8)
									{
									if(movepieces=="X")
									change(index,end,1);
									else if(movepieces[0]=='w')
									cout<<"invalid move";
									else if(movepieces!="X")
										change(index,end,0);
					
									}
									else 
									{
									cout<<"invalid move";
									}
				}
				
				else if(type[0]=='b'){
				
						
								if(check==21)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else
								if(movepieces!="X")
								change(index,end,0);
								else 
								cout<<"invalid move";
						
							}
							else if(check==19)
							{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else
								if(movepieces!="X")
								change(index,end,0);
							else 
								cout<<"invalid move";
							
							}
								else if(check==-21)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else
								if(movepieces!="X")
								change(index,end,0);
									else
									cout<<"invalid move";
								}
								else if(check==-19)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else
								if(movepieces!="X")
								change(index,end,0);
									else
									cout<<"invalid move";
								}else if(check==-12)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else if(movepieces!="X")
									change(index,end,0);
						
							}else if(check==-8)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else if(movepieces!="X")
									change(index,end,0);
						
							}else if(check==12)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else if(movepieces!="X")
									change(index,end,0);
						
							}else if(check==8)
								{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move";
								else if(movepieces!="X")
									change(index,end,0);
						
							}
								
							else 
							{
							cout<<"invalid move";
							}
			}
		}
	
	
	string checkPiece(int index)
	{
		string type;
		int indexcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
					if(index==indexcount)
				{
					type=board[i][j];
				}
				
				indexcount++;
			}
		}return type;
	}
	
	void rookie(string piece,string move)
	{
	
	int initialIndex=0;
	int index=findPieces(piece);
	int end=movecheck(move);
	int endcount=0;
	int indexcount=0;
	int check = end-index;
	string movepieces="";
	string type="";
	int indexCheck;
	string indexPieces="";

	endcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
					if(index==indexcount)
				{
					type=board[i][j];
				}
				
				
				if(end==endcount)
				{
					movepieces=board[i][j];
				}
				endcount++;indexcount++;
			}
		}
	
		if(type[0]=='w')
		{
				
			int indexCheck=0;
				if(check%10==0)
				{
				if(check>0)
				{		
					cout<<"The check is "<<check;
					indexCheck=0;
					cout<<"check f for loop";
					cout<<index+10 <<(index+(check-10));
					for(int i=index+10;i<=(index+(check-10));i+=10)
					{
						
						indexPieces=checkPiece(i);
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
					}
					else 
					{cout<<"invalid move2";}
				}

					
				else if(check<0)
				{
					cout<<"The check is "<<check<<"i is "<<(index+(check+10))<<"aaa"<<index-10;
					
					indexCheck=0;
					
					for(int i=(index+(check+10));i<=index-10;i+=10)
					{
						
						indexPieces=checkPiece(i);
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move3";
						else if(movepieces!="X")
						change(index,end,0);
					}
					else 
					{	cout<<"invalid move4";}
				}
			
			
			}	
			if(check<10)
					{
				 
					if(check>0){
						
					indexCheck=0;
					cout<<index+1<<" Hello "<<index+(check-1);
					for(int i=index+1;i<=(index+(check-1));i+=1)
					{
						
						indexPieces=checkPiece(i);
						cout<<"Hello";
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move5";
						else if(movepieces!="X")
						change(index,end,0);
					}
					else 
					{cout<<"invalid move6";}
					}
			
			}
			if(check>-10)
			    {	
		
				if(check<0){
				indexCheck=0;
				cout<<"\ncheck 10 for loop"<<index-1 <<(index+(check+1));
				
					for(int i=(index+(check+1));i<=index-1;i++)
					{
							cout<<"check 2 for loop";
						indexPieces=checkPiece(i);
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move7";
						else if(movepieces!="X")
						change(index,end,0);
						 
					}
					else 
					{cout<<"invalid move8";}
				}
				
			}	
		}
				
		else if(type[0]=='b')
				{
				int indexCheck=0;
				if(check%10==0)
				{
				if(check>0)
				{		
					cout<<"The check is "<<check;
					indexCheck=0;
					cout<<"check f for loop";
					cout<<index+10 <<(index+(check-10));
					for(int i=index+10;i<=(index+(check-10));i+=10)
					{
						
						indexPieces=checkPiece(i);
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
					}
					else 
					{cout<<"invalid move2";}
				}

					
				else if(check<0)
				{
					cout<<"The check is "<<check<<"i is "<<(index+(check+10))<<"aaa"<<index-10;
					
					indexCheck=0;
					
					for(int i=(index+(check+10));i<=index-10;i+=10)
					{
						
						indexPieces=checkPiece(i);
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move3";
						else if(movepieces!="X")
						change(index,end,0);
					}
					else 
					{	cout<<"invalid move4";}
				}
			
			
			}	
			if(check<10)
					{
				 
					if(check>0){
						
					indexCheck=0;
					cout<<index+1<<" Hello "<<index+(check-1);
					for(int i=index+1;i<=(index+(check-1));i+=1)
					{
						
						indexPieces=checkPiece(i);
						cout<<"Hello";
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move5";
						else if(movepieces!="X")
						change(index,end,0);
					}
					else 
					{cout<<"invalid move6";}
					}
			
			}
			if(check>-10)
			    {	
		
				if(check<0){
				indexCheck=0;
				cout<<"\ncheck 10 for loop"<<index-1 <<(index+(check+1));
				
					for(int i=(index+(check+1));i<=index-1;i++)
					{
							cout<<"check 2 for loop";
						indexPieces=checkPiece(i);
						
						if(indexPieces!="X"){indexCheck=1;}
					
					}
					if(indexCheck==0)
					{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move7";
						else if(movepieces!="X")
						change(index,end,0);
						 
					}
					else 
					{cout<<"invalid move8";}
				}
				
			}	
			
		
	}
}
	
	
	void bishop(string piece,string move)
	{
		int initialIndex=0;
	int index=findPieces(piece);
	int end=movecheck(move);
	int endcount=0;
	int indexcount=0;
	int check = end-index;
	string movepieces="";
	string type="";
	int indexCheck;
	string indexPieces="";

	endcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
					if(index==indexcount)
				{
					type=board[i][j];
				}
				
				
				if(end==endcount)
				{
					movepieces=board[i][j];
				}
				endcount++;indexcount++;
			}
		}
	
		if(type[0]=='w')
		{
				
			int indexCheck=0;
				if(check%11==0)
				{
					if(check>0)
					{		
						cout<<"The check is "<<check;
						indexCheck=0;
						cout<<"check f for loop";
						cout<<index+10 <<(index+(check-10));
						for(int i=index+11;i<=(index+(check-11));i+=11)
						{
							
							indexPieces=checkPiece(i);
							
							if(indexPieces!="X"){indexCheck=1;}
						
						}
						if(indexCheck==0)
						{
							if(movepieces=="X")
							change(index,end,1);
							else if(movepieces[0]=='w')
							cout<<"invalid move1";
							else if(movepieces!="X")
							change(index,end,0);
						}
						else 
						{cout<<"invalid move2";}
					}

					
						else if(check<0)
						{
							cout<<"\nThe check is "<<check<<"i is "<<(index+(check+10))<<"aaa"<<index-10;
							
							indexCheck=0;
							
							for(int i=(index+(check+11));i<=index-11;i+=11)
							{
								cout<<"hello";
								indexPieces=checkPiece(i);
								
								if(indexPieces!="X"){indexCheck=1;}
							
							}
							if(indexCheck==0)
							{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='w')
								cout<<"invalid move3";
								else if(movepieces!="X")
								change(index,end,0);
							}
							else 
							{	cout<<"invalid move4";}
						}
			
			
				
			
				}
				else if(check%9==0)
				{
					if(check>0)
					{		
						cout<<"The check is "<<check;
						indexCheck=0;
						cout<<"check f for loop";
						cout<<index+9 <<(index+(check-9));
						for(int i=index+9;i<=(index+(check-9));i+=9)
						{
							
							indexPieces=checkPiece(i);
							
							if(indexPieces!="X"){indexCheck=1;}
						
						}
						if(indexCheck==0)
						{
							if(movepieces=="X")
							change(index,end,1);
							else if(movepieces[0]=='w')
							cout<<"invalid move1";
							else if(movepieces!="X")
							change(index,end,0);
						}
						else 
						{cout<<"invalid move2";}
					}

					
						else if(check<0)
						{
							cout<<"The check is "<<check<<"i is "<<(index+(check+9))<<"aaa"<<index-9;
							
							indexCheck=0;
							
							for(int i=(index+(check+9));i<=index-9;i+=9)
							{
								
								indexPieces=checkPiece(i);
								
								if(indexPieces!="X"){indexCheck=1;}
							
							}
							if(indexCheck==0)
							{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='w')
								cout<<"invalid move3";
								else if(movepieces!="X")
								change(index,end,0);
							}
							else 
							{	cout<<"invalid move4";}
						}
			
			
				
			
				}else
				{
					cout<<"Invalid move";
				}
				
		}	
		
				
				else if(type[0]=='b')
				{
					int indexCheck=0;
				if(check%11==0)
				{
					if(check>0)
					{		
						cout<<"The check is "<<check;
						indexCheck=0;
						cout<<"check f for loop";
						cout<<index+10 <<(index+(check-10));
						for(int i=index+11;i<=(index+(check-11));i+=11)
						{
							
							indexPieces=checkPiece(i);
							
							if(indexPieces!="X"){indexCheck=1;}
						
						}
						if(indexCheck==0)
						{
							if(movepieces=="X")
							change(index,end,1);
							else if(movepieces[0]=='b')
							cout<<"invalid move1";
							else if(movepieces!="X")
							change(index,end,0);
						}
						else 
						{cout<<"invalid move2";}
					}

					
						else if(check<0)
						{
							cout<<"\nThe check is "<<check<<"i is "<<(index+(check+10))<<"aaa"<<index-10;
							
							indexCheck=0;
							
							for(int i=(index+(check+11));i<=index-11;i+=11)
							{
								cout<<"hello";
								indexPieces=checkPiece(i);
								
								if(indexPieces!="X"){indexCheck=1;}
							
							}
							if(indexCheck==0)
							{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move3";
								else if(movepieces!="X")
								change(index,end,0);
							}
							else 
							{	cout<<"invalid move4";}
						}
			
			
				
			
				}
				else if(check%9==0)
				{
					if(check>0)
					{		
						cout<<"The check is "<<check;
						indexCheck=0;
						cout<<"check f for loop";
						cout<<index+9 <<(index+(check-9));
						for(int i=index+9;i<=(index+(check-9));i+=9)
						{
							
							indexPieces=checkPiece(i);
							
							if(indexPieces!="X"){indexCheck=1;}
						
						}
						if(indexCheck==0)
						{
							if(movepieces=="X")
							change(index,end,1);
							else if(movepieces[0]=='b')
							cout<<"invalid move1";
							else if(movepieces!="X")
							change(index,end,0);
						}
						else 
						{cout<<"invalid move2";}
					}

					
						else if(check<0)
						{
							cout<<"The check is "<<check<<"i is "<<(index+(check+9))<<"aaa"<<index-9;
							
							indexCheck=0;
							
							for(int i=(index+(check+9));i<=index-9;i+=9)
							{
								
								indexPieces=checkPiece(i);
								
								if(indexPieces!="X"){indexCheck=1;}
							
							}
							if(indexCheck==0)
							{
								if(movepieces=="X")
								change(index,end,1);
								else if(movepieces[0]=='b')
								cout<<"invalid move3";
								else if(movepieces!="X")
								change(index,end,0);
							}
							else 
							{	cout<<"invalid move4";}
						}
			
			
				
			
				}else
				{
					cout<<"Invalid move";
				}
				}
				
			
		
	}

	 void queens(string piece,string move)
	 {
		 int initialIndex=0;
	int index=findPieces(piece);
	int end=movecheck(move);
	int endcount=0;
	int indexcount=0;
	int check = end-index;
	cout<<piece<<move;

	
	
		cout<<"its called method \n";
		cout<<check<<"  "<<index<<"  "<<end ;
		
		if(check%10==0){cout<<"its called 1";rookie(piece,move);}
		if(check%11==0){cout<<"its called2 ";bishop(piece,move);}
		if(check%9==0){cout<<"its called 3";bishop(piece,move);}
		if(check<10) { if(check>0){cout<<"its called 4";rookie(piece,move);}}
		if(check>-10)  {if(check<0){cout<<"its called 5";rookie(piece,move);}}
		
		 
	 }

	void kings(string piece,string move)
	{
		int initialIndex=0;
	int index=findPieces(piece);
	int end=movecheck(move);
	int endcount=0;
	int indexcount=0;
	int check = end-index;
	string movepieces="";
	string type="";

	endcount=0;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
					if(index==indexcount)
				{
					type=board[i][j];
				}
				
				
				if(end==endcount)
				{
					movepieces=board[i][j];
				}
				endcount++;indexcount++;
			}
		}
		if(type[0]=='w'){
			
				 if(check==-10)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
		
			}
			else if(check==-9)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
			
			}
				else if(check==-11)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}else if(check==10)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
		
			}
			else if(check==9)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
			
			}
				else if(check==11)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}
				else if(check==-1)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}
				else if(check==1)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='w')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}
				
			else 
			{
			cout<<"invalid move";
			}
			}else
			
			if(type[0]=='b'){
				
		
			 if(check==-10)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
		
			}
			else if(check==-9)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
			
			}
				else if(check==-11)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}else if(check==10)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
		
			}
			else if(check==9)
			{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
			
			}
				else if(check==11)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}else if(check==-1)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}
				else if(check==1)
				{
						if(movepieces=="X")
						change(index,end,1);
						else if(movepieces[0]=='b')
						cout<<"invalid move1";
						else if(movepieces!="X")
						change(index,end,0);
				}
			else 
			{
			cout<<"invalid move";
			}
			}
	}

	void undo(string piece,string move)
	{
		
	int index=findPieces(piece);
	int end=findPieces(move);
	cout<<"the name is "<<move;
	cout<<"initial is "<<end;
	cout<<"end is "<<index;
	
	change(end,index,1);
	
	}
	

};