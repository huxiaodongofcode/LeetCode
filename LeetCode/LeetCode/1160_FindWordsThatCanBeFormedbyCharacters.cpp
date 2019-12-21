/*
ʱ�䣺2019��12��21�� 20:36:26
��Ŀ������һ���ַ������顢���ʺ��ַ����ַ���
����ַ����������ַ����(ÿ���ַ�ֻ��ʹ��һ��)����ô������һ�����ַ�����
���������ַ������ȵ��ܺ͡�
*/
#include<iostream>
#include<vector>
#include<algorithm>
/*
Runtime: 88 ms, faster than 53.06% of C++ online submissions for Find Words That Can Be Formed by Characters.
Memory Usage: 17.6 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.
*/
#define MAX 102
using namespace std;
bool vis[MAX];
int countCharacters(vector<string>& words, string chars) {
	int len = 0;
	for (auto elem : words) {
		for (size_t i = 0; i < chars.size(); i++)//������飬���ʹ���Ϊfalse��
			vis[i] = true;
		//ÿ������
		size_t j = 0;
		for (; j < elem.size();j++) {
			//�鿴chars���Ƿ�������ַ�
			size_t k = 0;
			for (; k < chars.size(); k++) {
				if (chars[k] == elem[j]&&vis[k]) {//����ҵ��������������Ϊfalse����ʾ�ѷ���
					vis[k] = false;
					break;
				}		
			}
			if (k == chars.size())break;//��ʾδ���ҵ��ַ�
		}
		if (j == elem.size())len += elem.size();//��ʾ�õ��ʵ������ַ�������chars���ҵ�����ʱ��¼����
	}
	return len;
}
/*
Runtime: 84 ms, faster than 57.59% of C++ online submissions for Find Words That Can Be Formed by Characters.
Memory Usage: 15 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.
����std::count�������ú�������һ�Ե�������һ��ֵ���������������ֵ���ֵ�ͳ�ƴ�����ͷ�ļ�Ϊalgorithm
�жϵ�����ÿ���ַ����ֵĴ����Ƿ����chars�е��ַ��������ڣ���ʧ��
*/
int countCharacters_2(vector<string>& words, std::string chars) {
	int res = 0;
	for (const auto & w : words)
	{
		bool flg = true;
		for (const auto & c : w)
		{
			if (std::count(w.begin(), w.end(), c) > std::count(chars.begin(), chars.end(), c))
			{
				flg = false;
				break;
			}
		}
		if (flg) res += w.size();
	}
	return res;
}
int main() {
	vector<string> words = { "cat","bt","hat","tree" };
	vector<string> words2 = { "hello","world","leetcode" };

	string chars = "atach";
	string c = "welldonehoneyr";
	int i = countCharacters(words, chars);
	int j= countCharacters(words2, c);
	int k = countCharacters_2(words2, c);
	cout << k << endl;
}