#include<iostream> 
#include<stack> 
#include<string> 
using namespace std; 
string s; 
int main()
{ 
	char ch; 
	cout<<"Initial state: s0\nFinal state: s3\n\n"; 
	do
	{ 
		int i,st=0,flag=0; 
		stack<int> stk; 
		cout<<"Enter string: ";
		cin>>s; 
		for(i=0;i<s.size();i++)
		{ 
			if(st==0)
			{ 
				if(s[i]=='a')
				{ 
					stk.push(0); 
					cout<<"s0->"; 
				} 
				else if(s[i]=='b')
				{ 
					st=1; 
					cout<<"s1->"; 
				} 
			} 
			else if(st==1)
			{ 
				if(s[i]=='b')
				{ cout<<"s1->"; } 
				else if(s[i]=='a')
				{ st=2; stk.pop(); } 
			} 
			else
			{ 
				if(s[i]=='a') 
				stk.pop(); 
				cout<<"s2->"; 
			} 
		}
		if(i==s.size() && stk.empty())
		{ 
			cout<<"s3"; 
			cout<<"\nFinal state reached\nString is accepted by pda"; 
		} 
		else 
		cout<<"\nFinal state not reached\nString is not accepted by pda"; 
		cout<<"\n\nWants to enter more?(y/n) "; 
		cin>>ch; 
	}while(ch=='y' || ch=='Y'); 
	cout<<"...\n"; 
	cout<<"\nProgram terminated\n\n"; 
}

