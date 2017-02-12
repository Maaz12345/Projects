#include <iostream>
#include <fstream>

#include<conio.h>
using namespace std;
int main ()

{
    string line;
  char array [10][5],i,j;
    ifstream myfile;
  myfile.open ("A1P1-in1.txt");
  for (i=1;i<=10;i++)
  {
   for (j=1;j<=5;j++)
       {
       myfile >> array[i][j];
       cout << array[i][j];
      
       }
       cout<< '\n';
   }
       myfile.close();
       
   fstream outputfile;
   outputfile.open ("A1P1sol1.txt");
   
   for (i=10;i>=1;i--)
  {
   for (j=1;j<=5;j++)
       {
       outputfile << array[i][j];
       outputfile << " ";
       }
       
       outputfile<< '\n';
   }
       outputfile.close();
       
       getch();
       return 0;
    }
