#include <iostream>
#include <fstream>

#include<conio.h>
#include<vector>
#include<string>
using namespace std;
int x=0;
int move=0;
ofstream file;

class BFS 
{
     private:
       char array1[7][7];
       int i ,j;
      public:
       BFS(){};
     struct node 
       {
       	char array [7][7];
       	node *ptr=NULL;
		char M;
       	
       	node *parent=NULL;
	   }n1;
		
      vector <node*> V;
      vector<node *> VE;
      	//file.open ("MOVES.txt");
      void enque (char arrayM[7][7])
     {
     	node *ptrarray=new node;
      	for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       				
       				ptrarray->array[i][j]=arrayM[i][j];
       				ptrarray->ptr=NULL;
       				
				}
			}
			ptrarray->parent=NULL;
		V.push_back(ptrarray);
		if(Goal_testing(arrayM))
		cout<<"FINISHED";
		else
		{
		
		V.erase(V.begin());
		VE.push_back(ptrarray);
		UDLR(ptrarray);

		}
	}
	void ttry()
	{
		char Dtemp[7][7];
		      	for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
				Dtemp[i][j]=V[0]->array[i][j];
			
				}
			}
		node *temp1=new node;
		temp1=V[0];
		V.erase(V.begin());
		if (x>=1)
		VE.push_back(temp1);

		UDLR(temp1);

	
	
	 }

      void print(node *ptr)
      {
      			cout<< '\n';
		   for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       			cout <<ptr->array[i][j];
       			cout << " ";
      			}
       		cout<< '\n';
       	}
     
   			
	  }
      	
      void UDLR (node *temp)
      {
      	
      	node *ptru=new node;
      	ptru->parent=temp;
      	node *ptrd=new node;
      	node *ptrl=new node;
      	node *ptrr=new node;
      	
      	ptrd->parent=temp;
		ptrl->parent=temp;
      	ptrr->parent=temp;
		  		cout<< '\n';
		   for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       		
       			cout <<temp->array[i][j];
       			cout << " ";
      			}
      		cout<< '\n';
			  }
		
       		
		     for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       			ptru->array[i][j]=temp->array[i][j];
       			ptrd->array[i][j]=temp->array[i][j];
       			ptrl->array[i][j]=temp->array[i][j];
       			ptrr->array[i][j]=temp->array[i][j];
       			}
       		}
       		
     	up(ptru);
      	down(ptrd);
      	left(ptrl);
      	right(ptrr);
      	
      	
      	if (x>=1)
      	ttry();
      	else
      	x++;
      }
      	void up(node *ptru) 
      	{
      		char temp;
		  for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       				if (ptru->array[i][j]=='B')
       				{	
					   if (ptru->array[i-1][j]!='*')
       						{
							temp=ptru->array[i-1][j];
       						ptru->array[i-1][j]=ptru->array[i][j];
       						ptru->array[i][j]=temp;
       						}
       						else
							return;
					  		 	
       	        	}
       			}

			}

			  	char Dtemp[7][7];
			  	int k=0,flag;
			  	
				for(k=0;k<VE.size();k++)
			 {
		 string str,str1;
			    for (i=0;i<=6;i++)
  		    	{
   					for (j=0;j<=6;j++)
       				{
					Dtemp[i][j]=VE[k]->array[i][j];
				//	str = str + Dtemp[i][j];
				//	str1=str1 + ptru->array[i][j];
					}
				}
				
				
					if(exploring(ptru->array,Dtemp)==0)
						{
						 return;
						
						}
						
				}
		 				
						V.push_back(ptru);
						ptru->M='U';
						move++;
						print(ptru);
							if(Goal_testing(ptru->array))
							{
								print(ptru);
								cout<<"SUCCESS PATH";
							recursive(ptru);
								exit(1);
						
						}
								
			
	
	}					
		void recursive(node *ptr)
		{
			
					if(ptr->parent==NULL)
						cout << ptr->M<<endl;
					else{
						recursive(ptr->parent);
							cout << ptr->M<<endl;
					}	
		}
      	void down (node *ptrd)
		{
char temp,l;
		  for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       				if (ptrd->array[i][j]=='B')
       				{	
					   if (ptrd->array[i+1][j]!='*')
       						{
							temp=ptrd->array[i+1][j];
       						ptrd->array[i+1][j]=ptrd->array[i][j];
       						ptrd->array[i][j]=temp;
       						l=1;
       						break;
       						}
       						else
							return;
					  		 	
       	        	}
       	        
       			}
       				if (l==1)
       	        	break;

			}

			  	char Dtemp[7][7];
			  	int k=0,flag;
			  	
				for(k=0;k<VE.size();k++)
			 {
		 string str,str1;
			    for (i=0;i<=6;i++)
  		    	{
   					for (j=0;j<=6;j++)
       				{
					Dtemp[i][j]=VE[k]->array[i][j];
				//	str = str + Dtemp[i][j];
				//	str1=str1 + ptru->array[i][j];
					}
				}
				
				
					if(exploring(ptrd->array,Dtemp)==0)
						{
						 return;
						
						}
						
				}
		 				
						V.push_back(ptrd);
						ptrd->M='D';
						move++;
						print(ptrd);
							if(Goal_testing(ptrd->array))
							{
								print(ptrd);
				cout<<"SUCCESS PATH";
									recursive(ptrd);
								exit(1);
						
						}
								
			
						
		
	}
      	
       void left (node *ptrl)
       {
char temp,l;
		  for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       				if (ptrl->array[i][j]=='B')
       				{	
					   if (ptrl->array[i][j-1]!='*')
       						{
							temp=ptrl->array[i][j-1];
       						ptrl->array[i][j-1]=ptrl->array[i][j];
       						ptrl->array[i][j]=temp;
       					
       						break;
       						}
       						else
							return;
					  		 	
       	        	}
       	        
       			}
       			

			}

			  	char Dtemp[7][7];
			  	int k=0,flag;
			  	
				for(k=0;k<VE.size();k++)
			 {
		 string str,str1;
			    for (i=0;i<=6;i++)
  		    	{
   					for (j=0;j<=6;j++)
       				{
					Dtemp[i][j]=VE[k]->array[i][j];
					}
				}
				
				
					if(exploring(ptrl->array,Dtemp)==0)
						{
						 return;
						
						}
						
				}
		 				
						V.push_back(ptrl);
						ptrl->M='L';
						move++;
						print(ptrl);
							if(Goal_testing(ptrl->array))
							{
								print(ptrl);
								cout<<"SUCCESS PATH";
									recursive(ptrl);
								exit(1);
						
						}
								
			
						
		   
}
	//   bool check()
	  // {
	   	
	   //}
      	void right (node *ptrr)	
      	{
		  char temp,l;
		  for (i=0;i<=6;i++)
  			{
   				for (j=0;j<=6;j++)
       			{
       				if (ptrr->array[i][j]=='B')
       				{	
					   if (ptrr->array[i][j+1]!='*')
       						{
							temp=ptrr->array[i][j+1];
       						ptrr->array[i][j+1]=ptrr->array[i][j];
       						ptrr->array[i][j]=temp;
       						l=1;
       						break;
       						}
       						else
							return;
					  		 	
       	        	}
       	        
       			}
       				if (l==1)
       	        	break;

			}

			  	char Dtemp[7][7];
			  	int k=0,flag;
			  	
				for(k=0;k<VE.size();k++)
			 {
		 string str,str1;
			    for (i=0;i<=6;i++)
  		    	{
   					for (j=0;j<=6;j++)
       				{
					Dtemp[i][j]=VE[k]->array[i][j];

					}
				}
				
				
					if(exploring(ptrr->array,Dtemp)==0)
						{
						 return;
						
						}
						
				}
		 				
						V.push_back(ptrr);
						ptrr->M='R';
						move++;
						print(ptrr);
							if(Goal_testing(ptrr->array))
							{
								print(ptrr);
								cout<<"SUCCESS PATH";
								recursive(ptrr);
								exit(1);
						
						}
								
			
						
										cout<<"\n";

		
}
       int check ()
       {
       	return VE.size();
	   }
	          int check1 ()
       {
       	return V.size();
		}	
      
	   bool exploring(char arraym[7][7],char arraye[7][7])
       {
       	 int flag;

  		for (int i=0;i<=6;i++)
 		{
   		for (int j=0;j<=6;j++)
       {
     
       if(arraym[i][j]!=arraye[i][j])
       {
	   flag=0;
	   return (true);
   	   }
   	   else
   	   flag=1;
	   
	   }
   }
   return(false);
		}
	   
	   
	   bool Goal_testing(char array1[7][7])
	    {
	    char array[7][7];
	    
	    ifstream myfile;
		myfile.open ("A1P1-out1.txt");
  		 
  		for (i=0;i<=6;i++)
  		{
  			for (j=0;j<=6;j++)
       		{
       			if (i==6 || j==0 || j==6 || i==0)
       			array[i][j]='*';
       			else
       			myfile >> array[i][j];
       			

       		}
       	
  		}
  
	    
	    
	    int flag;

  		for (int i=0;i<=6;i++)
 		{
   		for (int j=0;j<=6;j++)
       {
     
       if(array1[i][j]!=array[i][j])
       {
	   flag=0;
	   return (false);
   	   }
   	   else
   	   flag=1;
	   
	   }
   }
   return(true);
		}
		
		
		
};


int main()
{
BFS b1;
 int i,j;
  ifstream myfile;
  char array[7][7],array1[7][7];
  myfile.open ("CS401-AI-A1P2-in1.txt");
  
  for (i=0;i<=6;i++)
  {
   for (j=0;j<=6;j++)
       {
       	if (i==6 || j==0 || j==6 || i==0)
       	array[i][j]='*';
       	else
       myfile >> array[i][j];
       array1[i][j]=array[i][j];
       }
   }
  
    myfile.close();
    b1.enque(array);
    b1.ttry();

 return 0;       
}
