/*
*Evaluate Reverse Polish Notation
*2018��7��16�� 18:29:45 
*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Note:
	Division between two integers should truncate toward zero.
	The given RPN expression is always valid. That means the expression would always evaluate to a result 
	and there won't be any divide by zero operation.
Example 1:
	Input: ["2", "1", "+", "3", "*"]
	Output: 9
	Explanation: ((2 + 1) * 3) = 9

Example 2:
	Input: ["4", "13", "5", "/", "+"]
	Output: 6
	Explanation: (4 + (13 / 5)) = 6
Example 3:
	Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
	Output: 22
	Explanation: 
	  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
	= ((10 * (6 / (12 * -11))) + 17) + 5
	= ((10 * (6 / -132)) + 17) + 5
	= ((10 * 0) + 17) + 5
	= (0 + 17) + 5
	= 17 + 5
	= 22
*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cctype>
using std::stack;	using std::cin;	using std::cout;	using std::string;	using std::vector;	using std::endl;
int calcu(int i,char m,int j){		//���� 
	switch(m)
	{
		case'+':return (i+j); break;
		case'-':return (i-j); break;
		case'*':return (i*j); break;
		case'/':return (i/j); break;
	}
}
void arith(char m,stack<int> &s){	//�������� 
	int j=s.top();
	s.pop();
	int i=s.top();
	s.pop(); 
	s.push(calcu(i,m,j));			//����������ʱע���������		
}
int Evaluate_RPN(vector<string> &t){			
	stack<int> s;
	char sym;
	for(size_t st=0;st<t.size();++st)			//���������vector�����е�stringԪ�� 
	{
		for(size_t it=0;it<t[st].size();++it)	//��ÿһ�ַ������д��� 
		{
			if(isdigit(t[st][it]))				//�޷��Ŵ��� 
			{
				int N1=t[st][it]-'0';
				int number=N1;
			//	char dec;
				while(isdigit(t[st][++it]))		//��λ������
				{
					N1=N1*10+(t[st][it]-'0');	 
					number=N1;
				}
				/*if((dec=t[st][it])=='.')		//С��ʱ 
				{
					int N2=0;
					float fraction=1;			
					while(isdigit(t[st][++it]))
					{
						N2+=((t[st][it]-'0')*(fraction/=10));	//С������ 
					}
					number+=N2;
					s.push(number);
				}
				else*/
					s.push(number);	
			}else if((sym=t[st][it])=='-')		//��"-"�жϣ��京���Ǹ��š����Ǽ��� 
			{
				if(isdigit(t[st][++it]))		//-Ϊ���� 
				{
					int N1=t[st][it]-'0';
					int number=N1;
				//	char dec;
					while(isdigit(t[st][++it]))
					{
						N1=N1*10+(t[st][it]-'0');	//��λ��ʱ���� 
						number=N1;
					}
				/*	if((dec=t[st][it])=='.')
					{
						int N2=0;
						float fraction=1;			
						while(isdigit(t[st][++it]))
						{
							N2+=((t[st][it]-'0')*(fraction/=10));	//С������ 
						}
						number+=N2;
						s.push(-number);
					}
					else
						*/
						s.push(-number);		
				}else						//Ϊ���� 
				{
					arith(sym,s);
				}
			}
			else if(sym=='+'||sym=='*'||sym=='/')
			{
				arith(sym,s);		
			}
		}	
	}
	return s.top();
}
int main(){
	vector<string>  t;
	string test;
	while(cin>>test){
		t.push_back(test);
	}	
	int j= Evaluate_RPN(t);
	cout<<j;
}
