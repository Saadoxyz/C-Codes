#include<iostream>
using namespace std;
struct Movies{
	string title;
	int year;
};
void printmovie(Movies movie);

int main()
{
	const int num=3;
	Movies films[num];
	int n;
	for(n=0;n<num;n++)
	{
		cout<<"Enter title: ";
		cin>>(films[n].title);
		cout<<"Enter year: ";
		cin>>films[n].year;
	}
	cout<<"\nYou have entered these movies:\n";
	for(int n=0;n<num;n++)
	{
		cout<<n+1<<":";
		printmovie(films[n]);
	}
	return 0;
}

void printmovie(Movies movie)
{
	cout<<"Movie Title: "<<movie.title<<endl;
	cout<<"movie Year :"<<movie.year<<endl;
}
