#ifndef SORT_TEST_H
#define SORT_TEST_H
#include<iostream>
#include<vector>
#include<cassert>
#include<ctime>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
namespace SortTestArray{
     int *generateRandomArray(int n,int rangel,int ranger){
         assert(ranger>=rangel);
         int*arr=new int [n];
         srand(time(NULL));
         for(int i=0;i<n;i++)
            arr[i]=rangel+rand()%(ranger-rangel+1);
        return arr;   //调用处delete[]arr;
     }
     template<typename T>
     void printArray(T arr[],int n){
         for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
     }

     template<typename T>
     bool isSorted(T arr[],int n){
         for(int i=0;i<n-1;i++)
              if(arr[i]>arr[i+1])
                  return false; 
        return true;
     }

     template<typename T>
     void testSort(const string&sortName,void(*sort)(T arr[],int n),T arr[],int n){
         clock_t startTime=clock();
         sort(arr,n);
         clock_t endTime=clock();
         assert(isSorted(arr,n));
         cout<<sortName<<" "<<"sortTime："<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
         return;
     }

     int* copyIntArray(int a[],int n){
         int*arr=new int[n];
         copy(a,a+n,arr);
         return arr;//函数调用处delete[]arr
     }
     
     int*generateNearlySortedArray(int n, int swapTime){
          int*arr=new int[n];
          for(int i=0;i<n;i++)
             arr[i]=i;
         srand(time(NULL));
         for(int i=0;i<swapTime;i++){
             int posx=rand()%n;
             int posy=rand()%n;
             swap(arr[posx],arr[posy]);
         }
         return  arr;
     }

}
#endif