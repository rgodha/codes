#include<iostream>
#include<stdlib.h>
 
using namespace std;
 
const int HIGH = 19;
const int LOW = 0;
 
void graph(int a[HIGH], int lo, int hi)
{
   int x,y;
    
   for(y=(hi-1); y>=0; y--)
   {
      if(y%2==0)
      {
         cout <<y<<"+";
      }
      else
      {
         cout<<" "<<"|";
      }
      for(x=lo; x<hi; x++)
      {
         if(a[x]>= y)
            cout<<" X ";
         else
            cout<<"   ";
      }
      cout << "\n";
   }
}
 
 
int main()
{
 
    int a[HIGH] = {2, 5, 9, 15, 3, 7, 12, 4, 0, 2, 14, 3, 12, 9, 6, 13, 1, 8, 3};
    int lo = LOW;
    int hi = HIGH;
 
    graph(a, lo, hi);
 
return 0;
}
