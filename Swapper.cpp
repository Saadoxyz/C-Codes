#include <iostream> 
using namespace std; 
  

template <typename T> 
int swaping(T &a, T &b) 
{ 
    T temp; 
    temp = a; 
    a = b; 
    b = temp; 
    return 0; 
} 

int main() 
{ 
int c,d;
double e,f;
char g,h;
    string a, b; 
    a = "saad", b = "khan"; 
  
   int k;
   cout<< "enter :";
   cin>> k;
   
   switch (k)
   {
   	case 0:
   		cin>>c>>d;
   		swaping(c, d); 
    cout << c << " " << d << endl; 
    break;
    
    case 1:
    		cin>>e>>f;
   		swaping(e, f); 
    cout << e << " " << f << endl;
    break;
    
    case 2:
    		cin>>g>>h;
   		swaping(g, h); 
   		
    cout << g << " " << h << endl;
    break;
    
    case 3:
   		swaping(a, b); 
    cout << a << " " << b << endl;
    break;
    
    default:
    	break;
    	
    	return 0;
   }
   
   
    
    return 0; 
}

