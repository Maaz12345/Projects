
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<conio.h>
#include<vector>
#include<string>
int prin=0;
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
				
				
	
		
	
	
				ofstream myfile1 ;
	 			myfile1.open("bestpath.txt",std::fstream::app);
	 			myfile1<<"----------------Initial Matrix----------------"<<"\n";
	 			print(n1,"bestpath.txt");
				myfile1.close();
  				myfile1.open("tree.txt",std::fstream::app);
	 			myfile1<<"----------------Initial Matrix----------------"<<"\n";
	 			print(n1,"tree.txt");
				myfile1.close();
	 			myfile1.open("minmax.txt",std::fstream::app);
	 			myfile1<<"----------------Initial Matrix----------------"<<"\n";
	 			print(n1,"minmax.txt");
				myfile1.close();
				  
				  if (myfile1.is_open())
  				{
					myfile1<<"Best Move of Level " << n1->level << " : "<<endl;
				}
			
	            
	            
	            
				n1->level=0;
	            n1->parent=NULL;
	            n1->next=NULL;
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
				V.push_back(ptr);
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
	myfile.close();	}
		
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
    void recursive(node *ptr)
		{
		
					if(ptr->parent==NULL)
					{
						nul++;
						cout <<"level is ="<< ptr->level<<"valus is ="<<ptr->valu<<"\n"<<endl;
						}
					
					
					if(ptr->parent!=NULL)
					{	
						recursive(ptr->parent);
						cout <<"level is ="<< ptr->level<<"valus is ="<<ptr->valu<<"\n"<<endl;

							
						
			  		}	
	
		}
	    void minmax(node *ptr)
		{
				
					if(ptr->parent==NULL)
					{
						
						
						print(ptr,"tree.txt");
					}
					
					
					if(ptr->parent!=NULL)
					{	
						node *temp=new node;
						temp=ptr->parent;
					
						if (temp->level%2!=0)
							{
								if (t==1)
								{
								temp->valu=ptr->valu;
								t++;
								}
								if((temp->valu)>(ptr->valu))
									temp->valu=ptr->valu;
							}
						if (temp->level%2==0)
							{
								
								
								if((temp->valu)<(ptr->valu))
									temp->valu=ptr->valu;
							}
							
						minmax(V[V.size()-(nus++)]);
						
						print(ptr,"tree.txt");
							
						
			  		}	
					
		}	
		
		
	void bestpath(node *ptr,int i)
	{
		node *n1=new node;
		int a;
		
		while (ptr->level==V[i]->level)
		i++;
		
		if (ptr->level%2==0)
		{
				while(V[i]->level==V[i+1]->level )
				{
				if( equal(V[i]->parent,V[i+1]->parent,ptr)==true)
				
				
				{

				if(V[i]->valu<V[i+1]->valu)
					{

						for(int x=0;x<3;x++){
								for(int y=0;y<3;y++)
									{
										n1->array[x][y]=V[i+1]->array[x][y] ;
									
									}
							}

							
							n1->parent=V[i+1]->parent;
							
							n1->level=V[i+1]->level;
							n1->valu=V[i+1]->valu;
							a=i+1;
							
							
					}
					if(V[i]->valu>=V[i+1]->valu)
					{

						for(int x=0;x<3;x++){
								for(int y=0;y<3;y++)
									{
										n1->array[x][y]=V[i]->array[x][y] ;
									
									}
							}

							
							n1->parent=V[i]->parent;
							
							n1->level=V[i]->level;
							n1->valu=V[i]->valu;
							a=i+1;
							
							
					}
					}	i++;
					if(i+2<V.size())
						{
						if (V[i+2]->level>V[i+1]->level)
						break;
						}
					else if (i+1==V.size())
						break;
					
					
				}
				ofstream myfile1 ;
	 	
		 		myfile1.open("bestpath.txt",std::fstream::app);
  				if (myfile1.is_open())
  				{
					myfile1<<"Best Move of Level " << n1->level << " : "<<endl;
				}
				print(n1,"bestpath.txt");
				if (n1->level==3 )//////////////if you want best for level 3 replace 2 with 3
			return;
			
			else 
			bestpath(n1,a);

			
					
		}
		
	if (ptr->level%2!=0)
		{

			
	while(V[i]->level==V[i+1]->level )
				{
				
					 	if( equal(V[i]->parent,V[i+1]->parent,ptr)==true) 
					 {
						if(V[i]->valu>V[i+1]->valu)	 
					{

							n1->parent=V[i+1]->parent;
							for(int x=0;x<3;x++)for(int y=0;y<3;y++)n1->array[x][y]=V[i+1]->array[x][y];
							n1->level=V[i+1]->level;
							n1->valu=V[i+1]->valu;
							a=i+1;
							
							
					}
					if(V[i]->valu<=V[i+1]->valu)
					{

						for(int x=0;x<3;x++){
								for(int y=0;y<3;y++)
									{
										n1->array[x][y]=V[i]->array[x][y] ;
									
									}
							}

							
							n1->parent=V[i]->parent;
							
							n1->level=V[i]->level;
							n1->valu=V[i]->valu;
							a=i+1;
							
							
					}
					
					 }
					i++;
				if (i+1==V.size())
					break;
				}
				ofstream myfile ;
	 	
		 		myfile.open("bestpath.txt",std::fstream::app);
  				if (myfile.is_open())
  				{
					myfile<<"Best Move of Level " << n1->level << " : "<<endl;
				}
			print(n1,"bestpath.txt");

			if (n1->level==3 )//////////////if you want best for level 3 replace 2 with 3
			return;
			
			else 
			bestpath(n1,a);
		}
			
			
			
				
			
	}
	bool equal(node *e0,node *e1,node *e2)
	{
	
		for(int x=0;x<3;x++){
								for(int y=0;y<3;y++)
									{
										if(e1->array[x][y]!=e2->array[x][y] || e0->array[x][y]!=e2->array[x][y] )
										return false;
										
										
										
									}
							}
		return true;					
		
			
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
 			if (TMM.V[i]->level<3)//////////////if you want best for level 3 replace 2 with 3
   				TMM.NodeGen(TMM.V[i]);
			else  	
   				break;
		}

for( i=0;i<TMM.V.size();i++)  
 {
 	if (TMM.V[i]->level==3)//////////////if you want tree for level 3 replace 2 with 3
 	{
	TMM.V[i]->valu=TMM.Goodness(TMM.V[i]);
	}
}


//TMM.recursive(TMM.V[TMM.V.size()-1]);
TMM.V[0]->valu=-9;
//cout<<"Vector size ="<<TMM.V.size();
TMM.minmax(TMM.V[TMM.V.size()-1]);


//TMM.recursive(TMM.V[TMM.V.size()-1]);

cout<<"Root  value= "<<TMM.V[0]->valu<<"\n";
for (i=1;i<TMM.V.size();i++)
{
	if (TMM.V[i]->level==1)
	cout<<"\n"<<"Child  "<<i<<" value = "<<TMM.V[i]->valu;
	else
	break;
}
node *n=new node;
for(i=0;i<TMM.V.size();i++)
TMM.V1.push_back(TMM.V[i]);


for(i=0;i<TMM.V.size();i++)
{
ofstream myfile ;
	 	
		 		myfile.open("minmax.txt",std::fstream::app);
  				if (myfile.is_open())
  				{
					myfile<<"level =" << TMM.V[i]->level << "value= "<<TMM.V[i]->valu <<"\n";
				}
TMM.print(TMM.V[i],"minmax.txt");
}
ofstream myfile ;
myfile.open("bestpath.txt",std::fstream::app);
myfile<<"Selected Path "<< "\n";
TMM.bestpath(TMM.V1[0],0);

cout<<"\n\n"<<"Three Files namely"<<"\n\n"<<"1.tree.txt"<<"\n"<<"2.minmax.txt"<<"\n"<<"3.bestpath.txt"<<"\n\n"<<"These Files are of append type ..."<<"\n"<<"Please  delete all three files before executing the program "<<endl;

	return 0;
}
