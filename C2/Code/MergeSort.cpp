#include<bits/stdc++.h>
using namespace std;

void Merge(int* array, int begin, int mid, int end){
	int* left = new int[mid - begin + 1];
	int i = 0, p1 = 0, p2 = 0;
	for(i = begin; i <= mid; ++i, ++p1)
		left[p1] = array[i];
	left[p1] = 0x7fffffff;
	int* right = new int[end - mid];
	for(i = mid+1; i <= end; ++i, ++p2)
		right[p2] = array[i];
	right[p2] = 0x7fffffff;
	p1 = 0, p2 = 0;
	for(int k = begin; k <= end; ++k){
		if(left[p1] <= right[p2])
			array[k] = left[p1++];
		else
			array[k] = right[p2++];
	}
}

void MergeSort(int* array, int begin, int mid, int end){
	if(begin < end){
		MergeSort(array, begin, (begin+mid)/2, mid);
		MergeSort(array, mid+1, (mid+1+end)/2, end);
		Merge(array, begin, mid, end);
	}
}

int main(){
	int a[6] = {39, 27, 51, 23, 33, 43};
	MergeSort(a, 0, 2, 5);
	for(int i = 0; i < 6; ++i){
		cout << a[i] << " ";
	}
}
