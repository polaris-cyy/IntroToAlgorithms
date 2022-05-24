#include<bits/stdc++.h>
using namespace std;

int Inversion(int* array, int begin, int end){
	//�����array�ֳ�������������left��right
	//Inversion��Ӱ���������������ڲ�in1��in2�������ǻ����Ӱ��mut��
	//�������ڲ�����Ԫ�ز��ı�mut
	//���left��right������ô��ʱin1=in2=0 
	int mid = (begin+end+1)/2;
	int count = 0;
	if(end > begin){
		int p = mid - begin, q = end - mid + 1, i = 0;
		count = Inversion(array, begin, mid-1) + Inversion(array, mid, end);
		int* left = new int[p+1];
		int* right= new int[q+1];
		for(i = 0; i < p; ++i)
			left[i] = array[i+begin];
		left[i] = 0x7fffffff;
		for(i = 0; i < q; ++i)
			right[i]= array[i+mid];
		right[i]= 0x7fffffff;
		int p1 = 0, p2 = 0;
		for(int i = begin; i <= end; ++i){
			if(left[p1] < right[p2])
				array[i] = left[p1++];
			else{
				array[i] = right[p2++];
				count += p - p1;
			}
		}
	}
	return count;
}

int main(){
	int array[5] = {1,4,2,5,3};//count = 7
	cout << Inversion(array, 0, 4) << endl;
	return 0; 
}
//4 1 5 6 3 2
