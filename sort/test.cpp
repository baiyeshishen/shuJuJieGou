/*
 * @Author: your name
 * @Date: 2020-06-04 15:39:46
 * @LastEditTime: 2020-06-06 09:25:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \shu_ju_jie_gou\sort\test.cpp
 */ 
#include"sortTest.h"
#include<iostream>
#include<vector>
#include"mergeSort.h"
#include"selectionSort.h"
#include"insertSort.h"
#include"quickSort.h"
int main(){
    int a, rangel,ranger;
    cout<<"input size of arr:";
    cin>>a;
    cout<<endl;
    cout<<"input rangel and ranger:";
    cin>>rangel;
    cin>>ranger;
    int*arr=SortTestArray::generateRandomArray(a,rangel,ranger);

    int *arr2 = SortTestArray::copyIntArray(arr, a);
    SortTestArray::testSort("quickSort", quickSort, arr2, a);
    delete [] arr2;

    int*arr1=SortTestArray::copyIntArray(arr,a);
    SortTestArray::testSort("SelectionSort",selectionSort,arr1,a);
    delete[] arr1;
    
     int *arr3 = SortTestArray::copyIntArray(arr, a);
    SortTestArray::testSort("insertSort", insertSort2, arr3, a);
    delete [] arr3;

    // int *arr4 = SortTestArray::copyIntArray(arr, a);
    // SortTestArray::testSort("mergesort", mergSortBu, arr4, a);
    // delete[] arr4;

    // SortTestArray::printArray(arr1,a);
    return 0;
}