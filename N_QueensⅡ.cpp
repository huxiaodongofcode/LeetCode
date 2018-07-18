/*
*N_Quenns
*2018��7��18�� 21:57:58 
*/
#include<iostream>
#include<stack>
#include<vector>
using std::stack;using std::vector;
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
int placeQueens(int N){
	Stack_1<Queen> solu;
	Queen q(0,0);
	int nSolu=0;
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
					nSolu++;
				q.x++;					//�Ƶ���һ�п�ͷ 
				q.y=0;
			}
		}
	}while(0<q.x||q.y<N);				//���з�֧���Ѽ�֦֮���㷨���� 
	return nSolu;
}
int main(){
	std::cout<<placeQueens(8);
	return 0;
}
