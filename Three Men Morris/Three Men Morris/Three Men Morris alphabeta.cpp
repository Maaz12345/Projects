
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<conio.h>
#include<vector>
#include<string>
int prin=0;
int q=0,j=0;
int t=1;
	int nul=0,nnull=0,nus=2;
using namespace std;
struct node 
       {
       	node *parent=NULL;
       	char array [3][3];
       	node *next=NULL;
       	int level=0;
		int valu=0;
		int alpha=-100;
		int beta=100;
	   }n1;
class ThreeMenMorris
{
	private:
       char array1[7][7];
       int i ,j;
    public:
       ThreeMenMorris(){};
    
	vector <node*> V;
	vector <node*> V1;
	node * RandomPlace()
		{
		int *array1=new int[18];
		int k=0,l=0,m=0,i=0;
		node *n1=new node;
		for (i=0;i<3;i++)
	  	{
	  		for(int j=0;j<3;j++)
				{	
				n1->array[i][j]='_';
				}
				
		}	
				n1->array[0][0]='O';
				n1->array[1][0]='O';
				n1->array[1][1]='O';
				n1->array[1][2]='X';
				n1->array[2][2]='X';
				n1->array[2][1]='X';

				for (i=0;i<3;i++)
				{
					while (n1->array[l][m]!='_')
						{
						l=rand() % 3;
						m=rand() % 3;
						
						}
					
					while (n1->array[l][m]!='_')
						{
						l=rand()%3;
						m=rand()%3;
						}
					
										
					
				}
				
				
	
		
	           // print(n1,);
	            n1->level=0;
	            n1->parent=NULL;
	            n1->next=NULL;
	            n1->alpha=-100;
	            n1->beta=100;
	            V.push_back(n1);
				return n1;
			  
			
		}
	
	void NodeGen(node *parentnode)
	{
		
		node *ptr=new node;
      	ptr=parentnode;
		int i=0;j=0;
	
      	for ( i=0;i<3;i++)
	  		{
	  			for( j=0;j<3;j++)
					{
      				ptr->array[i][j]=parentnode->array[i][j];
					
					}
			}
			ptr->level=parentnode->level;
		for ( i=0;i<3;i++)
	  		{
	  			for( j=0;j<3;j++)
				{	
			
					if(evenodd(ptr->level )==0 && ptr->array[i][j]=='X')
					{

					up(ptr,i,j,'X');
					down(ptr,i,j,'X');
					left(ptr,i,j,'X');
					right(ptr,i,j,'X');	
					
					}
					if(evenodd(ptr->level )==1 && ptr->array[i][j]=='O')
					{
					
					up(ptr,i,j,'O');
					down(ptr,i,j,'O');
					left(ptr,i,j,'O');
					right(ptr,i,j,'O');	
					}	
					
				}
			
		}

		   }
   		
   	void up(node * ptru,int i ,int j , char XorO)
	   {
	   		   	node *ptr=new node;
	   	      	for (int  l=0;l<3;l++)
	  		{
	  			for(int  m=0;m<3;m++)
					{
      				ptr->array[l][m]=ptru->array[l][m];
      				}
      		}
	   		if (ptr->array[i-1][j]=='_' && i-1>=0)
	   		{
		   		ptr->array[i-1][j]=XorO;
	   			ptr->array[i][j]='_';
	   			ptr->parent=ptru;
				ptr->level=ptru->level+1;
				if(ptr->level%2!=0)
				ptr->valu=9;
				if(ptr->level%2==0)
				ptr->valu=-9;
				if (ptr->level==ptru->level+1)
				V.push_back(ptr);
				if(ptru->level>=1)
				V1.push_back(ptr);
			}
		
				
		}
   	void down(node * ptrd,int i ,int j , char XorO)
	   {
	  
	   	node *ptr=new node;
	   	      	for (int  l=0;l<3;l++)
	  		{
	  			for(int  m=0;m<3;m++)
					{
      				ptr->array[l][m]=ptrd->array[l][m];
      				}
      		}
	   		if (ptr->array[i+1][j]=='_' && i+1<=2)
	   		{
			ptr->array[i+1][j]=XorO;
			ptr->array[i][j]='_';
			ptr->parent=ptrd;
			ptr->level=ptrd->level+1;
							if(ptr->level%2!=0)
				ptr->valu=9;
					if(ptr->level%2==0)
				ptr->valu=-9;
				if(ptrd->level>=1)
				V1.push_back(ptr);
				else if (ptr->level==ptrd->level+1)
				V.push_back(ptr);
				
			}
		
		}
	void left(node * ptrl,int i ,int j , char XorO)
	   {
	   	node *ptr=new node;
	   	      	for (int  l=0;l<3;l++)
	  		{
	  			for(int  m=0;m<3;m++)
					{
      				ptr->array[l][m]=ptrl->array[l][m];
      				}
      		}
	   		if (ptr->array[i][j-1]=='_' && j-1>=0)
	 	  	{
			ptr->array[i][j-1]=XorO;
			ptr->array[i][j]='_';
			ptr->parent=ptrl;
			ptr->level=ptrl->level+1;
							if(ptr->level%2!=0)
				ptr->valu=9;
					if(ptr->level%2==0)
				ptr->valu=-9;
				if(ptrl->level>=1)
				V1.push_back(ptr);
				else
				if (ptr->level==ptrl->level+1)
	   		V.push_back(ptr);
			}
		
		}
	void right(node * ptrr,int i ,int j , char XorO)
	   {
	   	node *ptr=new node;
	   	      	for (int  l=0;l<3;l++)
	  		{
	  			for(int  m=0;m<3;m++)
					{
      				ptr->array[l][m]=ptrr->array[l][m];
      				}
      		}
      	
	   		if (ptr->array[i][j+1]=='_' && j+1<=2 )
	   		{
				ptr->array[i][j+1]=XorO;
				ptr->array[i][j]='_';
				ptr->parent=ptrr;
				ptr->level=ptrr->level+1;
				if(ptr->level%2!=0)
				ptr->valu=9;
				if(ptr->level%2==0)
				ptr->valu=-9;
				if(ptrr->level>=1)
				V1.push_back(ptr);
				else
				if (ptr->level==ptrr->level+1)
	   			V.push_back(ptr);
			}
	
		}
 	int evenodd(int level)
 	{
 		if (level % 2==0)
	 	return 0;
		else 
		return 1;				
	 }
	
	 void print(node *ptr,string s)
	 {
	 	ofstream myfile ;
	 	
		 myfile.open(s.c_str(),std::fstream::app);
  		if (myfile.is_open())
  		{
 
    	
  		
	  for (int i=0;i<3;i++)
	  	{
	  		for(int j=0;j<3;j++)
				{	
				myfile <<ptr->array[i][j];
				}
			myfile<<"\n";
		}
		prin+=1;
	  myfile<<"\n";
	  myfile<<"-----------";
	 myfile<<"\n";
	}	
}
	int Goodness(node *ptr)
	{
		int x2=0,x1=0,o1=0,o2=0,blank=0,x=0,o=0;
				for (int i=0;i<3;i++)
	  		{
				for (int j=0;j<3;j++)	
					{
		 		
					  if (ptr->array[i][j]=='X')
			  		  x++;
			  		  if(ptr->array[i][j]=='_')
					  blank++;
					  if(ptr->array[i][j]=='O')
					  o++;		  	
	  				}
	  				
	  		
	  		if (blank==2 && x==1)
	  			x1++;
	  		if (blank==1 && x==2)
	  			x2++;
	  		if (blank==2 && o==1)
	  			o1++;
	  		if (blank==1 && o==2)
	  			o2++;
			blank=0;
			o=0;
			x=0;	  	  	
	  	}
	  		
	  		
	x2=3*x2;
	o2=3*o2;
	int output=(x2+x1)-(o2+o1);

	return output;	
	}		  
	   
void alphabeta(node *parent,node *current,int i  )
{
	 
	if ((parent->level)%2==1)
	 	{
	 		if (parent->beta>parent->alpha)
			{
				if (current->valu<parent->beta)
				parent->beta=current->valu;
				i++;
				if(i<V1.size())
				{
					if (V1[i]->level%2==0 && i<V1.size())		
				alphabeta(V1[i]->parent,V1[i],i);
				else
				{
				j--;
				
				alphabeta(V1[j-1]->parent,V1[j-1],j-1);
				}
			}
				
			}
			else 
			{
				i++;
				while (V1[i]->level==current->level)
				
				{
					
					V1.erase(V1.begin()+i);
					i++;
				}
				
			}
		 }
		 if ((parent->level)%2==0)
	 	{
	 		if (parent->beta>parent->alpha)
			{
				if (current->beta>parent->alpha)
				parent->alpha=current->beta;
			}
			else 
			{
				
				i++;
				if (i<V1.size())
				{
					while (V1[i]->level==current->level)
				
				{
					
					V1.erase(V1.begin()+i);
					i++;
				}
				
				}
			}
		 }
	
		j=i;
		
		
	return ; 

}

	 void print1(node *ptr)
	 {
	  for (int i=0;i<3;i++)
	  	{
	  		for(int j=0;j<3;j++)
				{	
				cout <<ptr->array[i][j];
				}
			cout<<"\n";
		}
		prin+=1;
	  cout<<"\n";
	  cout<<"-----------";
	  cout<<"\n";
		}










};












int main()
{
	ThreeMenMorris TMM;
	node *ptrm=new node;
	int *array1=new int [18];
	int i=0;

   ptrm=TMM.RandomPlace();

for( i=0;i<TMM.V.size();i++)  
 {

 if (TMM.V[i]->level<2)
   	{
   	TMM.V1.push_back(TMM.V[i]);
	TMM.NodeGen(TMM.V[i]);
	
	}
	else  	
   	break;
}

for( i=0;i<TMM.V1.size();i++)  
 {
 	if (TMM.V1[i]->level==2)
 	{
	TMM.V1[i]->valu=TMM.Goodness(TMM.V1[i]);
	}
}







for( i=1;i<TMM.V1.size();i++)  
 {

 if (TMM.V1[i]->level==2)
   	{
   		
   		j=i;
   		TMM.alphabeta(TMM.V1[i]->parent,TMM.V1[i],i);
		i=j;
		
		
		while(TMM.V1[i]->level!=1 && i<TMM.V1.size()-1)
		{

		i++;
		}
	
		
	}
	}
	
	
	ofstream myfile ;
	 	
		 		myfile.open("alphabeta.txt",std::fstream::app);

	
	
	
	  for(i=0;i<TMM.V1.size();i++)
	{
		  				if (myfile.is_open())
  				{
						if (TMM.V1[i]->level!=2)
						{
						myfile<<"Parent ----"<<"alpha =" << TMM.V1[i]->alpha <<"  beta = "<<TMM.V1[i]->beta <<"\n";
						cout<<"Parent ----"<<"alpha =" << TMM.V1[i]->alpha <<"  beta = "<<TMM.V1[i]->beta <<"\n";
						}
						else
						{
						myfile<<"Child-------"<<"value= "<<TMM.V1[i]->valu<<"\n";
						cout<<"Child-------"<<"value= "<<TMM.V1[i]->valu<<"\n";
						}
						TMM.print(TMM.V1[i],"alphabeta.txt");		
						TMM.print1(TMM.V1[i]);
				}

    }
	
	return 0;
}
