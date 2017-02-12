#include <iostream>
#include <fstream>
#include<conio.h>
#include<vector>
#include<string>
using namespace std;
int x=0;
int move=0;
ofstream file;

class Greedy 
{
     private:
	       char array1[7][7];
	       int i ,j;
	public:
	       Greedy(){};
    struct node 
    	{
	       	char array [7][7];
	       	node *ptr=NULL;
	       	int cost;
			char M;
	       	node *parent=NULL;
	   }n1;
		
      vector <node*> V;
      vector<node *> VE;
      	
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
		ptrarray->cost=0;
		ptrarray->parent=NULL;
		V.push_back(ptrarray);
		if(Goal_testing(arrayM)==-1)
		cout<<"!!!FINISHED!!!";
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
		int value;
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
       		
     	int R=up(ptru);
      	R=down(ptrd,R);
      	R=left(ptrl,R);
      	R=right(ptrr,R);
      	
      	
      	if (x>=1)
      	ttry();
      	else
      	x++;
	}
	int up(node *ptru) 
    {
      	char temp,G=0;
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
							return 100;
					  		 	
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
				if(exploring(ptru->array,Dtemp)==0)
						{
						 return 100;
						}
						
			}
			bool flag1=false;
			int value=price(ptru->array);
			if(V.empty())
					V.push_back(ptru);
						else
						{
							for (i=0;i<V.size() && !flag1 ;i++)
							{
								
									if (value<=V[i]->cost)
									{
										V.insert(V.begin()+i,ptru);
										flag1=true;
									}	
								
								
			 				
							}
							if(!flag1)
							{
								V.push_back(ptru);
							}
						}
				
						
			ptru->M='U';
			move++;
			print(ptru);
			G=Goal_testing(ptru->array);
			if(G==-1)
				{
				cout<<"!!!FINISHED!!!";
				cout<<"\n";
				cout<<"SUCCESS PATHS";
				recursive(ptru);
				exit(1);
						
				}
				
			
				return value;	
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
    int down (node *ptrd,int R)
		{
		char temp,l,G=0;
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
						return R;
					  		 	
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
		if(exploring(ptrd->array,Dtemp)==0)
		{
		 return R;
		}
						
	 }
	bool flag1=false;
	int value=price(ptrd->array);
		if(value<=R)
			{
				if(V.empty())
				V.push_back(ptrd);
				else
				{
					for (i=0;i<V.size() && !flag1 ;i++)
						{
						if (value<V[i]->cost)
							{
								V.insert(V.begin()+i,ptrd);
								flag1=true;
							}	
								
								
			 				
						}
							if(!flag1)
							{
								V.push_back(ptrd);
							}
						}
						ptrd->M='D';
						move++;
						print(ptrd);
						R=value;
						}
						 G=Goal_testing(ptrd->array);
							if(G==-1)
							{
							cout<<"!!!FINISHED!!!";
							cout<<"\n";
								cout<<"SUCCESS PATHS";
								recursive(ptrd);
							
								exit(1);
						
						}
							
							return R;	
			
						
		
	}
      	
       int left (node *ptrl,int R)
       {
char temp,l,G=0;
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
							return R;
					  		 	
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
						 return R;
						
						}
						
				}
						bool flag1=false;
						int value=price(ptrl->array);
						if(value<=R)
						{
						
						if(V.empty())
							V.push_back(ptrl);
						else
						{
							for (i=0;i<V.size() && !flag1 ;i++)
							{
								
									if (value<V[i]->cost)
									{
										V.insert(V.begin()+i,ptrl);
										flag1=true;
									}	
								
								
			 				
							}
							if(!flag1)
							{
								V.push_back(ptrl);
							}
						}
						ptrl->M='L';
						move++;
						print(ptrl);
						R=value;
						}
						 G=Goal_testing(ptrl->array);
							if(G==-1)
							{
								cout<<"!!!FINISHED!!!";
								cout<<"\n";
									cout<<"SUCCESS PATHS";
								recursive(ptrl);
								exit(1);
						
						}
					
							
								return R;
			
						
		   
}

      	int right (node *ptrr,int R)
		{
char temp,l=0,G=0;
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
							return R;
					  		 	
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
						 return R;
						
						}
						
				}
						bool flag1=false;
						int value=price(ptrr->array);
					if (value<=R)
						{
						
						if(V.empty())
							V.push_back(ptrr);
						else
						{
							for (i=0;i<V.size() && !flag1 ;i++)
							{
								
									if (value<V[i]->cost)
									{
										V.insert(V.begin()+i,ptrr);
										flag1=true;
									}	
								
				
							}
							if(!flag1)
							{
								V.push_back(ptrr);
							}
						}
						ptrr->M='D';
						move++;
						print(ptrr);
						R=value;
					}
						 G=Goal_testing(ptrr->array);
							if(G==-1)
							{
								cout<<"!!!FINISHED!!!";
								cout<<"\n";
								cout<<"SUCCESS PATHS";
								recursive(ptrr);
								exit(1);
						
						}
					
					
								
			return R;
						
		
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
	   
	   int price(char array1[7][7])
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
	int price=0;
  		for (int i=0;i<=6;i++)
 		{
   		for (int j=0;j<=6;j++)
       {
     
       if(array1[i][j]!=array[i][j])
       {
	   flag=0;
	   price++;
	   
   	   }
   	   else
   	   flag=1;
	   
	   }
   }
 return price;
	   	
	   	
	   	
	   }
	   int Goal_testing(char array1[7][7])
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
	   return 0;
   	   }
   	   else
   	   flag=1;
	   
	   }
   }
   return -1;
		}
		
	    
	    
		
		
		
};


int main()
{
Greedy b1;
 int i,j;
  ifstream myfile;
  char array[7][7],array1[7][7];
  myfile.open ("CS401-AI-A1P5-in1.txt");
  
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
