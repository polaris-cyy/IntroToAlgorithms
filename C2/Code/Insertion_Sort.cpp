#include<bits/stdc++.h>
using namespace std;

template<class T>
void Ins_up(T* array, int length){
	for(int i = 1; i < length; ++i){
		T pivot = array[i];
		int j;
		for(j = i - 1; j >= 0; --j){
			if(array[j] > pivot)
				array[j+1] = array[j];
			else
				break;
		}
		array[j+1] = pivot;
	}
}

template<class T>
void Ins_down(T* array, int length){
	for(int i = 1; i < length; ++i){
		T pivot = array[i];
		int j;
		for(j = i - 1; j >= 0; --j){
			if(array[j] < pivot)
				array[j+1] = array[j];
			else
				break;
		}
		array[j+1] = pivot;
	}
}

int* binary_add(int* a, int* b, int n){
	int* r = new int[n+1];
	memset(r, 0, n+1);
	int flag = 0, i;
	for(i = n-1; i >= 0; --i){
		r[i+1] = (a[i] + b[i] + flag) % 2; 
		flag = (a[i] + b[i] + flag >= 2) ? 1 : 0;
	}
	r[i+1] = flag;
	return r;
}

int main()
{
	int a[6] = {31,41,59,26,41,58};
	Ins_up<int>(a, 6);
	for(auto val : a){
		cout<< val << " "; 
	}
	int b[10] = {1,0,1,0,1,0,1,0,1,0};
	int c[10] = {0,1,1,1,1,1,1,1,1,1};
	int* r = binary_add(b, c, 10);
	for(int i = 0; i < 11; ++i){
		cout << r[i];
	}
	return 0;
}
