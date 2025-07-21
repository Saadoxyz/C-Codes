#include<iostream>
using namespace std;
struct Movies{
	string title;
	int year;
};
void printmovie(Movies movie);

int main()
{
	Movies mine,yours;
	mine.title="2001 A space Odysessy";
	mine.year=1968;
	cout<<"Enter your Movie title: ";
	cin>>yours.title;
	cout<<"Enter movie year: ";
	cin>>yours.year;
	
	cout<<"My favourite movie is:\n";
	printmovie(mine);
	cout<<"and yours is: \n";
	printmovie(yours);
	return 0;
}
void printmovie(Movies movie)
{
	cout<<"Movie Title: "<<movie.title<<endl;
	cout<<"movie Year :"<<movie.year<<endl;
}
