//
//  main.cpp
//  QuickSort
//
//  Created by Rumeysa Bulut on 17.10.2017.
//  Copyright © 2017 Rumeysa Bulut. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int Partition(vector<int>& array, int p, int r){
    int x = array[r], temp;
    int i = p-1;
    for(int j = p; j <= r-1; j++){
        if(array[j] <= x){
            i=i+1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[r];
    array[r] = temp;
    
    return i+1;
}

void QuickSort(vector<int>& array, int p, int r ){
    int q;
    if( p < r){
        q = Partition(array, p, r);
        QuickSort(array, p, q-1);
        QuickSort(array, q+1, r);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> A;
    int size,element;
    cout << "Enter the array size:"<<endl;
    cin >> size;
    cout << "Enter the elements of array:"<<endl;
    for(int i = 0; i < size; i++){
        cin >> element;
        A.push_back(element);
    }
    for(int i=0; i < size; i++)
        cout << A[i] <<" ";
    cout << endl;
    
    QuickSort(A, 0, size-1);
    
    cout<< "Sorted array:"<<endl;
    for(int i=0; i < size; i++)
        cout << A[i] <<" ";
    return 0;
}
