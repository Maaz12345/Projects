#include <iostream>
#include <fstream>

#include<conio.h>
#include<vector>
#include<string>
using namespace std;
int x=0;
int move=0;
ofstream file;

 struct node 
       {
       	char array [5][5];
		char M;
       	int cost;
       	node *parent=NULL;
	   }n1;
class GreedyBest
{
     private:
       char array1[5][5];
       int i ,j;
      public:
       GreedyBest(){};
    
		
      vector<node*> V;
      vector<node *> VE;
      	//file.open ("MOVES.txt");
    void enque (char arrayM[5][5])
    {
     	node *ptrarray=new node;
      	for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
       			{
       				
       				ptrarray->array[i][j]=arrayM[i][j];
       				//ptrarray->parent=NULL;
       				
				}
			}
			
			ptrarray->parent=NULL;
		
		V.push_back(ptrarray);
		
		if(Goal_testing(ptrarray->array))
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
		char Dtemp[5][5];
		      	for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
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
		   for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
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
      	
      	node *ptrd=new node;
      	node *ptrl=new node;
      	node *ptrr=new node;
      	ptru->parent=temp;
      	ptrd->parent=temp;
		ptrl->parent=temp;
      	ptrr->parent=temp;
//		  		cout<< '\n';
//		   for (i=0;i<=6;i++)
//  			{
//   				for (j=0;j<=6;j++)
//       			{
//       		
//       			cout <<temp->array[i][j];
//       			cout << " ";
//      			}
//      		cout<< '\n';
//			  }
//		
       		
		     for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
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
      	
      	
      	if (x > 0)
      	ttry();
      	else
      	x++;
      }
      	node * up(node *ptru) 
      	{
      		char temp;
      		      		node *upp=new node;
      		upp->parent=ptru;
      		  for (i=0;i<5;i++)
  		    	{
   					for (j=0;j<5;j++)
       				{
					upp->array[i][j]=ptru->array[i][j];
		
					}
				}
		  for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
       			{
       				if (upp->array[i][j]=='B')
       				{	
					   
					   if(i-1>0)
					   {
					   
							temp=upp->array[i-1][j];
       						upp->array[i-1][j]=upp->array[i][j];
       						upp->array[i][j]=temp;
       						upp->M='U';
       						upp->cost=price(upp->array);
       						return upp;
       					}
       					else
       						return NULL;
       											  		 	
       	        	}
       			}

			}
		}
      	node * down(node *ptru) 
      	{
      		char temp;
      	      		node *upp=new node;
      		upp->parent=ptru;
      		  for (i=0;i<5;i++)
  		    	{
   					for (j=0;j<5;j++)
       				{
					upp->array[i][j]=ptru->array[i][j];
		
					}
				}
		  for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
       			{
       				if (upp->array[i][j]=='B')
       				{	
					   
					   if(i+1<5)
					   {
					   
							temp=upp->array[i+1][j];
       						upp->array[i+1][j]=upp->array[i][j];
       						upp->array[i][j]=temp;
       						upp->M='D';
       						upp->cost=price(upp->array);
							   return upp;
       					}
       					else
       						return NULL;
       											  		 	
       	        	}
       			}

			}
	
								
	
	}		
	
      	node * left(node *ptru) 
      	{
      		char temp;
      	      		node *upp=new node;
      		upp->parent=ptru;
      		  for (i=0;i<5;i++)
  		    	{
   					for (j=0;j<5;j++)
       				{
					upp->array[i][j]=ptru->array[i][j];
		
					}
				}
		  for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
       			{
       				if (upp->array[i][j]=='B')
       				{	
					   
					   if(j-1>0)
					   {
					   
							temp=upp->array[i][j-1];
       						upp->array[i][j-1]=upp->array[i][j];
       						upp->array[i][j]=temp;
       						upp->M='L';
       						upp->cost=price(upp->array);
       						return upp;
       					}
       					else
       						return NULL;
       											  		 	
       	        	}
       			}

			}
	
								
	
	}	
	      	node * right(node *ptru) 
      	{
      		char temp;
      		node *upp=new node;
      		upp->parent=ptru;
      		  for (i=0;i<5;i++)
  		    	{
   					for (j=0;j<5;j++)
       				{
					upp->array[i][j]=ptru->array[i][j];
		
					}
				}
		  for (i=0;i<5;i++)
  			{
   				for (j=0;j<5;j++)
       			{
       				if (upp->array[i][j]=='B')
       				{	
					   
					   if(j+1<5)
					   {
					   
							temp=upp->array[i][j+1];
       						upp->array[i][j+1]=upp->array[i][j];
       						upp->array[i][j]=temp;
       						upp->M='R';
       						upp->cost=price(upp->array);
       						return upp;
       					}
       					else
       						return NULL;
       											  		 	
       	        	}
       			}

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
//      	void down (node *ptrd)
//		{
//char temp,l;
//		  for (i=0;i<5;i++)
//  			{
//   				for (j=0;j<5;j++)
//       			{
//       				if (ptrd->array[i][j]=='B')
//       				{	
//					   -------
//							temp=ptrd->array[i+1][j];
//       						ptrd->array[i+1][j]=ptrd->array[i][j];
//       						ptrd->array[i][j]=temp;
//       						l=1;
//       						break;
//       						
//       						else
//							return;
//					  		 	
//       	        	}
//       	        
//       			}
//       				if (l==1)
//       	        	break;
//
//			}
//
//			  	char Dtemp[5][5];
//			  	int k=0,flag;
//			  	
//				for(k=0;k<VE.size();k++)
//			 {
//		 string str,str1;
//			    for (i=0;i<5;i++)
//  		    	{
//   					for (j=0;j<5;j++)
//       				{
//					Dtemp[i][j]=VE[k]->array[i][j];
//				//	str = str + Dtemp[i][j];
//				//	str1=str1 + ptru->array[i][j];
//					}
//				}
//				
//				
//					if(exploring(ptrd->array,Dtemp)==0)
//						{
//						 return;
//						
//						}
//						
//				}
//		 				
//						V.push_back(ptrd);
//						ptrd->M='D';
//						move++;
//						print(ptrd);
//							if(Goal_testing(ptrd->array))
//							{
//								print(ptrd);
//				cout<<"SUCCESS PATH";
//									recursive(ptrd);
//								exit(1);
//						
//						}
//								
//			
//						
//		
//	}
//      	
//       void left (node *ptrl)
//       {
//char temp,l;
//		  for (i=0;i<5;i++)
//  			{
//   				for (j=0;j<5;j++)
//       			{
//       				if (ptrl->array[i][j]=='B')
//       				{	
//					   
//							temp=ptrl->array[i][j-1];
//       						ptrl->array[i][j-1]=ptrl->array[i][j];
//       						ptrl->array[i][j]=temp;
//       					
//       						break;
//       						
//       						else
//							return;
//					  		 	
//       	        	}
//       	        
//       			}
//       			
//
//			}
//
//			  	char Dtemp[5][5];
//			  	int k=0,flag;
//			  	
//				for(k=0;k<VE.size();k++)
//			 {
//		 string str,str1;
//			    for (i=0;i<5;i++)
//  		    	{
//   					for (j=0;j<5;j++)
//       				{
//					Dtemp[i][j]=VE[k]->array[i][j];
//					}
//				}
//				
//				
//					if(exploring(ptrl->array,Dtemp)==0)
//						{
//						 return;
//						
//						}
//						
//				}
//		 				
//						V.push_back(ptrl);
//						ptrl->M='L';
//						move++;
//						print(ptrl);
//							if(Goal_testing(ptrl->array))
//							{
//								print(ptrl);
//								cout<<"SUCCESS PATH";
//									recursive(ptrl);
//								exit(1);
//						
//						}
//								
//			
//						
//		   
//}
//	//   bool check()
//	  // {
//	   	
//	   //}
//      	void right (node *ptrr)	
//      	{
//		  char temp,l;
//		  for (i=0;i<5;i++)
//  			{
//   				for (j=0;j<5;j++)
//       			{
//       				if (ptrr->array[i][j]=='B')
//       				{	
//					   ////////////
//					   					   							temp=ptrr->array[i][j+1];
//       						ptrr->array[i][j+1]=ptrr->array[i][j];
//       						ptrr->array[i][j]=temp;
//       						l=1;
//       						break;
//       						
//       						else
//							return;
//					  		 	
//       	        	}
//       	        
//       			}
//       				if (l==1)
//       	        	break;
//
//			}
//
//			  	char Dtemp[5][5];
//			  	int k=0,flag;
//			  	
//				for(k=0;k<VE.size();k++)
//			 {
//		 string str,str1;
//			    for (i=0;i<5;i++)
//  		    	{
//   					for (j=0;j<5;j++)
//       				{
//					Dtemp[i][j]=VE[k]->array[i][j];
//
//					}
//				}
//				
//				
//					if(exploring(ptrr->array,Dtemp)==0)
//						{
//						 return;
//						
//						}
//						
//				}
//		 				
//						V.push_back(ptrr);
//						ptrr->M='R';
//						move++;
//						print(ptrr);
//							if(Goal_testing(ptrr->array))
//							{
//								print(ptrr);
//								cout<<"SUCCESS PATH";
//								recursive(ptrr);
//								exit(1);
//						
//						}
//								
//			
//						
//										cout<<"\n";
//
//		
//}

int price(char array1[5][5])
	   {
	   	char array[5][5];
	    
	    ifstream myfile;
		myfile.open ("A1P1-out1.txt");
  		 
  		for (i=0;i<5;i++)
  		{
  			for (j=0;j<5;j++)
       		{
       		
       		
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




       int check ()
       {
       	return VE.size();
	   }
	          int check1 ()
       {
       	return V.size();
		}	
      
	   bool exploring(char arraym[5][5],char arraye[5][5])
       {
       	 int flag;

  		for (int i=0;i<5;i++)
 		{
   		for (int j=0;j<5;j++)
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
	   
	   
	   bool Goal_testing(char array1[5][5])
	    {
	    char array[5][5];
	    
	    ifstream myfile;
		myfile.open ("A1P1-out1.txt");
  		 
  		for (i=0;i<5;i++)
  		{
  			for (j=0;j<5;j++)
       		{
       			
       			myfile >> array[i][j];
       			

       		}
       	
  		}
  
	    
	    
	    int flag;

  		for (int i=0;i<5;i++)
 		{
   		for (int j=0;j<5;j++)
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
		
		
		
	node* Run(node* initial)
	{
		node* temp=NULL;
		node* temp1=NULL;
		if(Goal_testing(initial->array))
			return initial;
		else
		{
			Push(initial);
			while(!V.empty())
			{
				temp=V[0];
				V.erase(V.begin());
				if((temp1=up(temp))!=NULL&& !IsExist(temp1))
				{
					if(Goal_testing(temp1->array))
						return temp1;
					
						else{
						Explore(temp1);
					Push(temp1);
						}
				}
				if((temp1=down(temp))!=NULL && !IsExist(temp1))
				{
					if(Goal_testing(temp1->array))
						return temp1;
						else{
						Explore(temp1);
					Push(temp1);
						}
					
				}
				if((temp1=left(temp))!=NULL && !IsExist(temp1))
				{
					if(Goal_testing(temp1->array))
						return temp1;
						else{
						Explore(temp1);
					Push(temp1);
						}
				}
				if((temp1=right(temp))!=NULL && !IsExist(temp1))
				{
					if(Goal_testing(temp1->array))
						return temp1;
						else{
						Explore(temp1);
					Push(temp1);
						}
				}
			}
			return NULL;
		}
		//return  NULL;
	}
	
	string toString(char arr[5][5])
	{
		string temp="";
			for(int j=0;j<5;j++)
			{
				for(int k=0;k<5;k++)
				{
					temp+=arr[j][k];
					
				}
			}
			return temp;
		
	}
	bool IsExist(node* test)
	{
		string result=toString(test->array);
		string temp="";
		//char temp[][]=NULL;
		for(int i=0;i<V.size();i++)
		{
			temp=toString(V[i]->array);
			if(temp.compare(result)==0)
			{
				return true;
			}
//			for(int j=0;j<arr.size();j++)
//			{
//				for(int k=0;k<arr[j].size();k++)
//				{
//					if(arr[j][k]==temp[j][k])
//					
//				}
//			}
		}
			for(int i=0;i<V.size();i++)
		{
			temp=toString(VE[i]->array);
			if(temp.compare(result)==0)
			{
				return true;
			}
//			for(int j=0;j<arr.size();j++)
//			{
//				for(int k=0;k<arr[j].size();k++)
//				{
//					if(arr[j][k]==temp[j][k])
//					
//				}
//			}
		}
		
	}
	bool Explore(node* ptr)
	{
		VE.push_back(ptr);
		return true;
	}
	
	bool Push(node* ptru) // Priority Queue Over Here 
	{
			bool flag1=false;
			
			int value=ptru->cost;
			
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
		return true;
	}
		
};


int main()
{
GreedyBest b1;
 int i,j;
 node* initial=new node;
  ifstream myfile;
  char array[5][5],array1[5][5];
  myfile.open ("CS401-AI-A1P2-in1.txt");
  
  for (i=0;i<5;i++)
  {
   for (j=0;j<5;j++)
       {
       
       myfile >> array[i][j];
       initial->array[i][j]=array[i][j];
       }
   }
  
    myfile.close();
    b1.recursive(b1.Run(initial));
    //b1.enque(array);
    //b1.ttry();

 return 0;       
}
