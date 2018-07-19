/*
*N_Quenns
*2018��7��19�� 15:49:41 
*Input: 4
*Output: [
	 [".Q..",  // Solution 1
	  "...Q",
	  "Q...",
	  "..Q."],
	
	 ["..Q.",  // Solution 2
	  "Q...",
	  "...Q",
	  ".Q.."]
*	]
*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using std::stack;using std::vector; using std::string;using std::cout;
struct Queen{
	int x,y;
	Queen(int xx, int yy){
		x=xx;
		y=yy;
	}
	bool operator ==(Queen const &q) const{					//�������������Դ��ж��Ƿ��ͻ 
		return (y==q.y)||(x+y==q.x+q.y)||(x-y==q.x-q.y);	//ͬһ���Լ��Խ��ߣ� 
	}
	bool operator !=(Queen const &q) const{return !(*this==q);}
};
template <typename T>
class Stack_1{						//����vectorʵ����һ��ջ�����Խ���find������ 
public:
	vector<T> temp;
	int find(T const& e){			//�����ж��Ƿ�����ͻ 
		for(size_t i=0;i!=temp.size();++i)	//��Ҫʹ��temp.size()-1���ֲ��������±�Խ�磨sizeΪ0ʱ�� 
		{
			if(e==temp[i])
				return i;
		}
		return -1;
	}
	void push(T const& e){temp.push_back(e);}
	T &top(){ return temp.back();}
	void pop(){temp.pop_back();}
	int size(){return temp.size();}
	bool empty(){return temp.empty();}
}; 
vector<vector<string> > placeQueens(int N){
	Stack_1<Queen> solu;
	Queen q(0,0);
	Queen print_q(0,0);
	int nSolu=0;
	
	vector<vector<string> > pt;		//������ս�� 
	vector <string> s1,s1_copy,L,R,com;		//����һ���������丱������ʼ������ 

	string s2;
	char Q='Q';
	char point='.';
	for(int x=0;x<N;++x)
		s2.push_back(point);
	for(int y=0;y<N;++y)
	{
		s1.push_back(s2);	
	}
	s1_copy=s1;

	do{//������̽���� 
		if(N<=solu.size()||N<=q.y)		//���ѳ�������γ�һ��ȫ�ֽ�ʱ 
		{
			q=solu.top();				//���ݣ���������̽��һ�� 
			solu.pop();
			q.y++;
		}else
		{
			while((q.y<N)&&(!solu.empty())&&(0<=solu.find(q)))	//�ȶ����лʺ� 
			{
				q.y++;					//������ͻ���Ƶ���һ�� 
			}
			if(N>q.y)					//�����ڿɰڷŵ��� 
			{
				solu.push(q);
				if(N<=solu.size())		//�����ֽ��Ϊȫ�ֽ⣬��ͨ��ȫ�ֱ������� 
				{
				//	nSolu++;
					for(size_t j=0;j!=solu.temp.size();++j)
					{
						print_q=solu.temp[j];
						s1[print_q.x][print_q.y]=Q;
					}
					pt.push_back(s1);
					s1=s1_copy;
				}	
				q.x++;					//�Ƶ���һ�п�ͷ 
				q.y=0;
			}
		}
	}while(0<q.x||q.y<N);				//���з�֧���Ѽ�֦֮���㷨���� 
	return pt;
	//	return nSolu;
}
int main(){
	vector<vector<string> > pt=placeQueens(4);
	for(vector<vector<string> >::iterator it_pt=pt.begin();it_pt!=pt.end();++it_pt)	//������ 
	{
		cout<<"[";
		for(size_t i=0;i<(*it_pt).size();++i)
		{
			if(i==0)
			{
				cout<<"\"";
				cout<<(*it_pt)[i];
				cout<<"\"";
			}else
			{
				cout<<","<<"\"";
				cout<<(*it_pt)[i];
				cout<<"\"";
			}	
		}
			
		cout<<"]";
	}
	return 0;
}
