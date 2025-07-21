#include<iostream>
using namespace std;
char array[3][3]={{'o','o','x'},{'x','x','x'},{'x','o','o'}};
void diagnol()
{
	if(array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[2][2] == array[0][0])
	{
		cout<<"you win"<<endl;
	}
	else if(array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] == array[2][0] )
	{
		cout<<"you win"<<endl;
	}
}
void vertical()
{
	if(array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][0]== array[0][2])
	{
		cout<<"you win"<<endl;
	}
	else if(array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][0]== array[1][2])
	{
		cout<<"you win"<<endl;
	}
	else if(array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][0]== array[2][2])
	{
		cout<<"you win"<<endl;
	}
}
void horizontal()
{
    if(array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0]== array[2][0])
	{
		cout<<"you win"<<endl;
	}
	else if(array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[0][1]== array[2][1])
	{
		cout<<"you win"<<endl;
	}
	else if(array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[0][2]== array[2][2])
	{
		cout<<"you win"<<endl;
	}
}
int main()
{
	for(char i=0;i<3;i++)
	{
		for(char j=0;j<3;j++)
		{
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	}
	diagnol();
	horizontal();
	vertical();
}
