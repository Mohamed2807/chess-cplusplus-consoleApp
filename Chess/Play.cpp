#include"Board.cpp"
class Play{
	ChessBoard chessboard;
	string previousPiece;
	string whiteprevIndex;
	string blackPrevIndex;
	
	
	public:
				Play()
				{
					chessboard.set();
				}
				void whitePlay()
				{
					string movePieces;
					string piece="",index="";
					int flag=0;
					int i;
						int check;
				
					
						repeat1:
						check=0;
						chessboard.whiteShow();
						
						cout<<"\n\n\n";
						
						
							 check=lookForCheck(findKing("wK"),'b',"this is for checking");
							if(check==1){check+=checkMate(previousPiece,"wK",'w');
								if(check==2){cout<<"Check!!!!!!!!!!!!";}
							else cout<<"Checkmate!!!!!!!!!";}
							cout<<"\nWHITE TURN !!!!!!\n\nEnter the move with P->index format=";
							//cin.ignore();
							cin>>movePieces;
							
							
						
						
							flag=0;
							 piece="w";
							 index="";
							for(i=0;i<movePieces.length();i++)
							{
								if(movePieces[i]=='-')
								{
									flag=1;i+=2;
								}
								if(flag==0)
								{
									piece+=movePieces[i];
								}
								if(flag==1)
								{
									index+=movePieces[i];
								}
								
							}
							
							//cout<<piece;
							//cout<<"      |"<<index;
							
							if(piece[1]=='P'){chessboard.pawn(piece,index);}
							else if(piece[1]=='R'){chessboard.rookie(piece,index);}
							else if(piece[1]=='K')
							{
								if(piece[2]=='n'){cout<<"knight";
								chessboard.knight(piece,index);}
								else{cout<<"king";cout<<piece[2];
								chessboard.kings(piece,index);}
							}
							else if(piece[1]=='B'){chessboard.bishop(piece,index);}
							else if(piece[1]=='Q'){chessboard.queens(piece,index);}
							check=lookForCheck(findKing("wK"),'b',"this is for checking");
								
							if(check==1)
							{	
								check+=checkMate(previousPiece,"wK",'w');
								if(check==2){
								cout<<"\nInvalid Move!!!!!!!\nYou got check in a game";
								chessboard.undo(piece,whiteprevIndex);
								goto repeat1;
								}
								else
								{
									cout<<"CheckMate!!!!!!!!!!!!!";
								}
								
							}
						whiteprevIndex=index;
						
						
				}
				
				void blackPlay()
				{
					string movePieces;
					string piece="",index="";
					int flag=0;
					int i;
						int check;
				
					
						repeat1:
						check=0;
						chessboard.blackShow();
						
						cout<<"\n\n\n";
						
						
							 check=lookForCheck(findKing("bK"),'w',"this is for checking");
							 //cout<<"\nprevius piece="<<previousPiece;
							if(check==1){check+=checkMate(previousPiece,"bK",'b');
								if(check==2){cout<<"Check!!!!!!!!!!!!";}
							else cout<<"Checkmate!!!!!!!!!";}
							cout<<"\nBLACK TURN !!!!!!\n\nEnter the move with P->index format=";
							//cin.ignore();
							cin>>movePieces;
						
						
							flag=0;
							 piece="b";
							 index="";
							for(i=0;i<movePieces.length();i++)
							{
								if(movePieces[i]=='-')
								{
									flag=1;i+=2;
								}
								if(flag==0)
								{
									piece+=movePieces[i];
								}
								if(flag==1)
								{
									index+=movePieces[i];
								}
								
							}
							
						
							
							if(piece[1]=='P'){chessboard.pawn(piece,index);}
							else if(piece[1]=='R'){chessboard.rookie(piece,index);}
							else if(piece[1]=='K')
							{
								if(piece[2]=='n'){
								chessboard.knight(piece,index);}
								else{cout<<piece[2];
								chessboard.kings(piece,index);}
							}
							else if(piece[1]=='B'){chessboard.bishop(piece,index);}
							else if(piece[1]=='Q'){chessboard.queens(piece,index);}
							check=lookForCheck(findKing("bK"),'w',"this is for checking");
							
							if(check==1)
							{	
								check+=checkMate(previousPiece,"bK",'b');
								if(check==2){
								cout<<"\nInvalid Move!!!!!!!\nYou got check in a game";
								chessboard.undo(piece,blackPrevIndex);
								goto repeat1;}
								else
								{
									cout<<"CheckMate!!!!!!!!!!!!!";
								}
								
							}
						blackPrevIndex=index;
							
							
						}
						
		int findKing(string kingPiece)
		{
			int king=chessboard.findPieces(kingPiece);
			return king;
		}
		
				int lookForCheck(int king,char color,string Heading)
				{
				
					char pieceCheck[]={'R','K','B','Q','P'};
					int indexCheck=0;
					
				
					string indexPieces="";
					
					//int king=chessboard.findPieces(piece);
					string IndexKing=chessboard.checkPiece(king);
						cout<<endl<<IndexKing;
					int i;
					char oppositeColor;
					if(color=='b'){oppositeColor='w';}
					else if(color=='w'){oppositeColor='b';}
					
					
					for(i=king+10;i<100;i+=10)
					{
						
						cout<<"lookForCheck 1 Outside king "<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck[0]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 1 inside king "<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 1 inside king "<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
							indexCheck=1;}}
						
					}
					
					
					
					for(i=king-10;i>=0;i-=10)
					{
						cout<<"lookForCheck 2 Outside king"<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck[0]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 2 inside king "<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 2 inside king "<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
							indexCheck=1;}}
					}
					
					
					for(i=king+11;i<100;i+=11)
					{		
						cout<<"lookForCheck 3 Outside king "<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck[2]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 3 inside king "<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 3 inside king "<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
							indexCheck=1;}}
					}
					
					
					
					for(i=king-11;i>=0;i-=11)	
					{
						cout<<"lookForCheck 4 Outside king "<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck[2]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 4 inside king "<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 4 inside king "<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
							indexCheck=1;}}
					}
					
					
					for(i=king+9;i<100;i+=9)
					{	
						cout<<"lookForCheck 5 Outside king "<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck[2]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 5 inside king "<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 5 inside king "<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
							indexCheck=1;}}
					}
					
					
					for(i=king-9;i>=0;i-=9)	
					{	
						cout<<"lookForCheck 6 Outside king -9="<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck[2]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 6 inside king "<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 6 inside king"<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
							indexCheck=1;}}
					}
					
					
					for(i=king+1;i<abs(((king%10)-10))+king;i+=1)
					{	
						cout<<"lookForCheck 7 Outside king "<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(IndexKing[0]==color){break;}
						if(pieceCheck[0]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						cout<<"lookForCheck 7 inside king "<<king<<"->"<<i<<endl;
						 
						
						if(indexPieces[0]==color){
							cout<<"lookForCheck 7 inside king "<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
						indexCheck=1;}}
					}
					
					
					for(i=king-1;i>=king-10;i-=1)	
					{		
						cout<<"lookForCheck 8 Outside king"<<king<<"->"<<i<<endl;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(IndexKing[0]==color){break;}
						if(pieceCheck[0]==indexPieces[1]||pieceCheck[3]==indexPieces[1]){
						
						cout<<"lookForCheck 8 inside king is"<<king<<"->"<<i<<endl;
						if(indexPieces[0]==color){
							cout<<"lookForCheck 8 inside king"<<king<<"->||"<<i<<endl;
							previousPiece=indexPieces;
						 indexCheck=1;}}
					} 
					int knightPossible=0;
										
					knightPossible=knightCheck(king,color);
					if(knightPossible==1){
						indexCheck=1;
					}
				return indexCheck;
				
				}
				int pawnCheck(int piece,char color)
				{
					int indexCheck=0;
					char pieceCheck='P';
					string indexPieces="";
				
					
						
					int i;
					char oppositeColor;
					if(color=='b'){oppositeColor='w';}
					else if(color=='w'){oppositeColor='b';}
					int cond=0;
				
					if(color=='b'){
					if(piece>40&&piece<50){cond=piece-20;}
					else cond=piece-10;
					
					for(i=piece-10;i>=cond;i-=10)
					{
						
						cout<<"pawn Check "<<piece<<"->"<<i;
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						
						if(indexPieces[0]==oppositeColor){
							break;
						}
			
						if(indexPieces[1]==pieceCheck){
							cout<<"Demort";
							
							if(indexPieces[0]==color){
								
								indexCheck=1;
							}
						}
						
					}
						
				}else if (color=='w')
				{
					if(piece<60&&piece>50){cond=piece+20;}
					else cond=piece+10;
					for(i=piece+10;i<=cond;i+=10)
					{
						
					
						indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
						if(indexPieces[0]==oppositeColor){break;}
						if(pieceCheck==indexPieces[1]){
					
						if(indexPieces[0]==color){indexCheck=1;}}
					
					}
				}
					
					return indexCheck;
					
					
				
			}
				
				int checkMate(string piece,string king,char color)
				{
					int expression=0;
					string indexPieces="";
					int choice=0;
					int kingIndex=chessboard.findPieces(king);
					int pieceIndex=chessboard.findPieces(piece);
					int diff=kingIndex-pieceIndex;
					if(diff%10==0){expression=10;}
					else if(diff%11==0){expression=11;}
					else if(diff%9==0){expression=9;}
					else if(diff<=7&&diff>0){expression=1;cout<<"setup!!!!!1";}
					else if(diff>=-7&&diff<0){expression=-1;cout<<"setup!!!!!2";}
					else if(diff%10==8||diff%10==-8){choice=1;}
					else if(diff%10==7||diff%10==-7){choice=1;}
					else if(diff%10==1||diff%10==-1){choice=1;}
					else if(diff%10==2||diff%10==-2){choice=1;}
					char oppositeColor;
					if(color=='b'){oppositeColor='w';}
					else if(color=='w'){oppositeColor='b';}
					
					
					int lookCheckMate=0;
					
					
					
					
					
					
					
					
					if(choice ==1){
						cout<<"Accepted!!!!!!!";
						
								cout<<"checkmate  1 inside Knight is"<<kingIndex<<"diff is"<<diff;
							lookCheckMate=	lookForCheck(pieceIndex,color,"This is from checkmate");
							
					}
					
					
					
					
					else if(diff>0&&diff!=1){
					for(int i=kingIndex-expression;i>=pieceIndex;i-=expression)
						{
								cout<<"checkmate  1 outside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
							indexPieces=chessboard.checkPiece(i);
							if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
							lookCheckMate=pawnCheck(i,color);
							if(lookCheckMate==0)
							{
								cout<<"checkmate  1 inside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
							lookCheckMate=	lookForCheck(i,color,"This is from checkmate");
							}
						}
						
					}
					else if(diff<0&&diff!=-1)
					{
						
						for(int i=kingIndex+expression;i<=pieceIndex;i+=expression)
						{
							cout<<"checkmate  2 outside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
							indexPieces=chessboard.checkPiece(i);
						
							if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
							lookCheckMate=pawnCheck(i,color);
							if(lookCheckMate==0)
							{
								cout<<"checkmate  2 inside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
						lookCheckMate=	lookForCheck(i,color,"This is from checkmate");
							}
						}
					}
					else if(diff==1)
					{
						for(int i=kingIndex;i<abs(((kingIndex%10)-10))+kingIndex;i+=expression)
						{
							cout<<"checkmate  3 outside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
							indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
							lookCheckMate=pawnCheck(i,color);
							if(lookCheckMate==0)
							{
								cout<<"checkmate  3 inside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
								lookCheckMate=lookForCheck(i,color,"This is from checkmate");
							}
						}
					}
					else if(diff==-1)
					{
						for(int i=kingIndex;i>=kingIndex-10;i-=expression)
						{
							cout<<"checkmate  4 outside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
							indexPieces=chessboard.checkPiece(i);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){break;}
							lookCheckMate=pawnCheck(i,color);
							if(lookCheckMate==0)
							{	cout<<"checkmate  4 inside king is"<<kingIndex<<"diff is"<<diff<<"->"<<i<<endl;
								lookCheckMate=lookForCheck(i,color,"This is from checkmate");
							}
						}
					}
					int kingPosibility[]={-10,10,9,-9,11,-11,1,-1};
					int checkColor;
					if(lookCheckMate==0)
					{
						
						for(int i=0;i<8;i++)
						{
							cout<<"checkmate  5 outside king is"<<kingIndex<<"diff is"<<diff<<"->"<<kingIndex+kingPosibility[i]<<endl;
							indexPieces=chessboard.checkPiece(kingIndex+kingPosibility[i]);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){continue;}
							if(indexPieces.length()==1&&indexPieces[0]=='X')
							{
								cout<<"checkmate  5 inside king is"<<kingIndex<<"diff is"<<diff<<"->"<<kingIndex+kingPosibility[i]<<endl;
							
							checkColor=lookForCheck(kingIndex+kingPosibility[i],oppositeColor,"This is from checkmate");
							if(checkColor==0){lookCheckMate=1;}
							
							}
							
							
						}
					}
					if(lookCheckMate==0)
					{
						for(int i=0;i<8;i++)
						{
							cout<<"checkmate  6 outside king is"<<kingIndex<<"diff is"<<diff<<"->"<<kingIndex+kingPosibility[i]<<endl;
							
							indexPieces=indexPieces=chessboard.checkPiece(kingIndex+kingPosibility[i]);
							if(indexPieces.length()==1&&indexPieces[0]!='X'){continue;}
							if(indexPieces.length()!=1&&indexPieces[0]==oppositeColor)
							{
								cout<<"checkmate  6 inside king is"<<kingIndex<<"diff is"<<diff<<"->"<<kingIndex+kingPosibility[i]<<endl;
							
							checkColor=kingCheck(kingIndex+kingPosibility[i],color);
							lookCheckMate+=checkColor;
							
							}
							
							
						}
					}
					if(lookCheckMate==1){
						int checkMateposiible;
						cout<<"the checking check piece"<<pieceIndex;
						checkMateposiible=lookForCheck(pieceIndex,oppositeColor,"This is from checkmate");
						if(checkMateposiible==1)
							lookCheckMate=0;
					}
					
					
					return  lookCheckMate;	
				}
				
				int kingCheck(int index,char color){
					int check=0;
					string indexPieces;
					int kingPosibility[]={-10,10,9,-9,11,-11,1,-1};
					for(int i=0;i<8;i++)
						{
							
							indexPieces=indexPieces=chessboard.checkPiece(index+kingPosibility[i]);
							if(indexPieces.length()==1&&indexPieces[0]!='X'){continue;}
							if(indexPieces[1]=='K'&&indexPieces[0]==color)
							{
							check=1;
							}
					
						}
						return check;
				}

				int knightCheck(int king,char color){
						int knightAvailability[]={12,-12,21,-21,19,-19,8,-8};
					int i=0, knightLength=8,indexCheck=0;
					char pieceCheck[]={'R','K','B','Q','P'};
					string indexPieces;
					char oppositeColor;
					if(color=='b'){oppositeColor='w';}
					else if(color=='w'){oppositeColor='b';}
					if(king%10==8){i=4;}
					else if(king%10==7){i=2;}
					else if(king%10==1){knightLength=4;}
					else if(king%10==2){knightLength=6;}
					for(;i<knightLength;i++)
					{
						cout<<"lookForCheck 9 Outside king"<<knightAvailability[i]<<"=="<<king+knightAvailability[i]<<endl;
						if((king+knightAvailability[i])>99||(king+knightAvailability[i])<0){continue;}
					
						indexPieces=chessboard.checkPiece(king+knightAvailability[i]);
						if(indexPieces.length()==1&&indexPieces[0]!='X'){continue;}
						if(indexPieces[0]==oppositeColor){continue;}
						cout<<"lookForCheck 9 inside king" <<knightAvailability[i]<<"=="<<king+knightAvailability[i]<<endl;
						if(pieceCheck[1]==indexPieces[1]&&indexPieces.length()==4){
								if(indexPieces[0]==color){
									cout<<"lookForCheck 9 inside king" <<knightAvailability[i]<<"++=="<<king+knightAvailability[i]<<endl;
						previousPiece=indexPieces;
						 indexCheck=1;}}
						
					}
					return indexCheck;
				}
};