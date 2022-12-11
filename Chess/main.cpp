#include"Play.cpp"



void controller()
{
	
	Play play;
	int flag=0;
	repeat:
	if(flag==0)
	{
		play.whitePlay();
		flag=1;
	}else if(flag==1)
	{
		play.blackPlay();
			flag=0;
	}
	goto repeat;
	//play.whitePlay("P3->c3");
	//play.blackPlay("P4->d5");
	

	//play.whitePlay("Q->a4");
	//play.blackPlay("Q->a4");
	//play.whitePlay("P7->g3");
	//play.blackPlay("P4->d6");
	//play.whitePlay("P5->e3");
	//play.blackPlay("P4->d4");

	
	
	
	
	
	
	


}

int  main()
{
   // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	controller();
		
	
	
		// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	

	
	//chessboard.change("b","1","b","3");

	
}