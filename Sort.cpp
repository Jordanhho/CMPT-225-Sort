//============================================================================
// Name        : sort.cpp
// Author      : Jordan Ho
// Version     :
// Copyright   : All Rights Reserved
//============================================================================

#include <iostream>
#include "sort.h"

int insertionSort(Container& arr, Iter start, Iter end) {
	Val count = 0;
	Val current;
	Iter i, j;
	Iter arr_size = arr.size();
	for (i = 1; i < arr_size; i++) {
		current = arr[i];
		j = i - 1;
		count++;
		while (j >= 0 && arr[j] > current) {
			arr[j + 1] = arr[j];
			j = j - 1;
			arr[j + 1] = current;
			count++;
		}
	}
	return count;
}


//Based my code off of http://www.cplusplus.com/forum/general/123961/ for shellsort
int shellSort(Container& arr, Iter start, Iter end) {
	Val count = 0;
	Val temp;
	Iter gap, i, j;

	for (gap = end/2; gap > 0; gap /= 2) {
		count++;
		for (i = gap; i < end; i++) {
			count++;
			for (j = (i - gap); j >= start && arr[j] > arr[j+gap]; j-=gap) {
				temp = arr[j];
				arr[j] = arr[j+gap];
				arr[j+gap] = temp;
				count++;
			}
		}
	}

	return count;
}




int merge(Container& left_arr, Iter left_elements, Container& right_arr, Iter right_elements, Container& arr, Iter arr_elements, Iter count) {
	Iter i = 0, j = 0, k = 0;
	Iter L_sizet = left_arr.size();
	Iter R_sizet = right_arr.size();
	while (i < L_sizet && j < R_sizet) {
		count++;
		if (left_arr[i] <= right_arr[j]) {
			arr.erase(arr.begin() + k);
			arr.insert(arr.begin() + k, left_arr[i]);
			i++;
			count++;
		}
		else {
			arr.erase(arr.begin() + k);
			arr.insert(arr.begin() + k, right_arr[j]);
			j++;
		}
		k++;
	}

	Iter L_sizett = left_arr.size();
	Iter R_sizett = right_arr.size();
	while (i < L_sizett) {
		arr.erase(arr.begin() + k);
		arr.insert(arr.begin() + k, left_arr[i]);
		i++;
		k++;
		count++;
	}
	while (j < R_sizett) {
		arr.erase(arr.begin() + k);
		arr.insert(arr.begin() + k, right_arr[j]);
		j++;
		k++;
		count++;
	}

	return count;
}




int mergeSort(Container& arr, Iter start, Iter end) {
	Val count = 0;
	if (end < 2) {
		count++;
		return count;
	}
	Iter mid = end / 2;

	Container L_arr;
	Container R_arr;

	for (Iter i = start; i < mid; i++) {
		L_arr.push_back(arr[i]);
	}
	for (Iter i = mid; i < end; i++) {
		R_arr.push_back(arr[i]);
	}
	mergeSort(L_arr, start, mid);
	mergeSort(R_arr, start, (end - mid));
	count = count + merge(L_arr, (end - mid), R_arr, mid, arr, end, count);

	return count;
}









int quickSort(Container& arr, Iter start, Iter end) {
	Val count = 0;
	Iter arr_size = arr.size();

	if (arr_size <= 1) {
		count++;
		return count;
	}

	Val pivot = arr[arr_size - 1];
	Container L;
	Container E;
	Container G;
	Iter i = arr_size - 1;

	while (arr.empty() != true && i >= 0) {
		count++;
		if (arr[i] < pivot) {
			L.push_back(arr[i]);
			arr.erase(arr.begin() + i);
			i--;
		}

		else if (arr[i] == pivot) {
			E.push_back(arr[i]);
			arr.erase(arr.begin() + i);
			i--;
		}

		else {
			G.push_back(arr[i]);
			arr.erase(arr.begin() + i);
			i--;
		}
	}

	count = count + quickSort(L, start, end);
	count = count + quickSort(G, start, end);

	Iter L_sizett = L.size();
	Iter E_sizett = E.size();
	Iter G_sizett = G.size();

	for (Iter i = start; i < L_sizett; i++) {
		arr.push_back(L[i]);
	}
	for (Iter i = start; i < E_sizett; i++) {
		arr.push_back(E[i]);
	}
	for (Iter i = start; i < G_sizett; i++) {
		arr.push_back(G[i]);
	}

	return count;
}



int main(){
	return 0;
}