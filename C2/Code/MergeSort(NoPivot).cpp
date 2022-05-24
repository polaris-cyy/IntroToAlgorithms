#include<bits/stdc++.h>
using namespace std;

void Merge(int*, int, int, int);
void MergeSort(int* array, int begin, int end){
	if(end > begin){
		int mid = (end+begin+1)/2;
		MergeSort(array, begin, mid-1);
		MergeSort(array, mid, end);
		Merge(array, begin, mid, end);
	}
}

void Merge(int* array, int begin, int mid, int end){
	int p = mid - begin, q = end - mid + 1;
	int* left = new int[p], * right = new int[q];
	for(int i = 0; i < p; ++i)
		left[i] = array[i+begin];
	for(int i = 0; i < q; ++i)
		right[i]= array[i+mid];
	int p1 = 0, p2 = 0;
	for(int i = begin; i <= end; ++i){
		if(p1 == p){
			while(p2 < q)
				array[i++] = right[p2++];
		}else if(p2 == q){
			while(p1 < p)
				array[i++] = left[p1++];
		}else if(left[p1] < right[p2]){
			array[i] = left[p1++];
		}else{
			array[i] = right[p2++];
		}
	}
}

int main(){
	int a[5] = {53,62,72,1,4};
	MergeSort(a, 0, 4);
	for(int i = 0; i < 5; ++i){
		cout << a[i] << ' '; 
	}
	return 0;
} 
