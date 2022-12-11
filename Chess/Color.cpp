#include<iostream>
#include <windows.h>
using namespace std;
int main()
{
	for(int i=0;i<256;i++){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	
	cout<<i<<endl;
	}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}