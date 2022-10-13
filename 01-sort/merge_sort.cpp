#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& ary) {
	for (int& num : ary)
		cout << num << " ";
	cout << endl;
}

void merge(vector<int>& temp,vector<int>& ary,int left,int mid,int right) {
	int lpos = left,rpos=mid+1,pos=left;
	while (lpos <= mid && rpos <= right) {
		if (ary[lpos] < ary[rpos])
			temp[pos++] = ary[lpos++];
		else
			temp[pos++] = ary[rpos++];
	}
	while (lpos <= mid)
		temp[pos++] = ary[lpos++];
	while (rpos <= right)
		temp[pos++] = ary[rpos++];
	//copy(temp.begin(),temp.end(),ary.begin());

	while (left <= right) {
		ary[left] = temp[left];
		left++;
	}
}

void merge_sort(vector<int>& temp,vector<int>& ary,int left,int right) {
	//vector<int> temp(ary.size(),0);
	if (left < right) {
		int mid = left + right >> 1;
		merge_sort(temp,ary, left, mid);
		merge_sort(temp,ary, mid + 1, right);
		merge(temp,ary, left, mid, right);
	}
}

int main() {
	vector<int>ary{ 1,2,3,10,20,4,5,2,15 };
	vector<int>temp(ary.size(), 0);
	print(ary);
	merge_sort(temp,ary,0,ary.size()-1);
	print(ary);
}