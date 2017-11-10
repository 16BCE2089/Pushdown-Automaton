#include<iostream>
#include<stdlib.h> 
using namespace std; 
//define variables 
int top=0,stack[1000],n=0,m=0,state[1000],d=0; 
// function to push 1's into the stack for each a 
void push() { stack[top]=1; top++; } 
// function to pop one 1 from the stack for each b 
void pop() { top--; } 
int main() 
{
	char a[2000]; 
	int i,j,s=0,x=1; 
	while(x)
	{ 
		d=0; top=0; s=0; m=0; n=0; 
		cout<<"Enter the string \n"; 
		cin>>a; 
		//to calculate the string length 
		for(i=0;a[i]!='\0';i++) 
		s++; 
		cout<<"string length = "<<s<<endl; 
		for(i=0;i<s;i++) 
		{ 
			//to count the number of a's 
			if(a[i]=='a') 
			{ 
				if(m==0 && n==0) 
				{ 
					state[d++]=0; 
					push(); 
				} 
				else if(m==1 && n==0) 
				state[d++]=4; 
			}
			//to check when the first b occurs
			else if(a[i]=='b') 
			{ 
				j=i; 
				break; 
			} 
			//to check if any other charcter than a or occurs 
			else if(a[i]!='a' && a[i]!='b') 
			{ n=1; } 
		} 
		for(i=j;i<s;i++) 
		{
			 //to count the number of b's 
			 if(a[i]=='b') 
			 { 
			 	pop(); 
				if(top<0) 
				{ 
					state[d++]=6; 
				} 
				else 
				{ 
					if(m==0 && n==0) 
					state[d++]=1; 
					else if(m==1 && n==0) 
					state[d++]=4;
				} 
			}
			//to check if any a comes after b 
			else if(a[i]=='a') 
			{
				 m=1; 
				 if(m==1 && n==0) 
				 state[d++]=4;
			} //to check if any other character than a or b occurs
			else if(a[i]!='a' && a[i]!='b') 
			{ n=1; state[d++]=5; } 
		}
		//display the result 
		cout<<"Transitions:"<<endl; 
		for(int t=0;t<d;t++) 
		{
			if(t!=d-1) 
			cout<<"s"<<state[t]<<"->"; 
			if(t==d-1) 
			cout<<"s"<<state[t]; 
			if(state[t]==4 || state[t]==6) 
			break; 
		}
		if(top==0 && n==0 && m==0)
		cout<<"->s3"<<endl<<"final state reached"; 
		else if((top!=0 && n==0)||(n==0 && m==1)) 
		cout<<endl<<"final state not reached"; 
		else if(n==1) 
		cout<<endl<<"error in input"; 
		cout<<endl; 
		cout<<"press 0 to exit"<<endl; 
		cout<<"press any other number to continue"<<endl; 
		cin>>x; 
	} 
	return 0; 
}

