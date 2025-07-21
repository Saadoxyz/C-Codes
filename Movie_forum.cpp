#include<iostream>
#include<iostream>
using namespace std;
struct Movies{
	string title;
	int year;
};
int main()
{
	Movies amovie;
	Movies* pmovie;
	pmovie = &amovie;
	cout<<"Enter title: ";
	cin>>pmovie->title;
	cout<<"Enter Year: ";
	cin>>pmovie->year;
	cout<<"\nYou have entered:\n";
	cout<<pmovie->title<<endl;
	cout<<pmovie->year<<endl;
	cout<<"\nAddress are :\n";
	cout<<pmovie<<endl;
	cout<<pmovie<<endl;
	return 0;
}
