/*
 * @Author: your name
 * @Date: 2020-06-04 15:18:51
 * @LastEditTime: 2020-06-07 18:55:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \shu_ju_jie_gou\sort\mergeSort.h
 */ 
#ifndef MERGE_SORT
#define MERGE_SORT
#include<algorithm>
#include<iostream>
template<typename T>
class MergeSort{
    private:
    T*item;

    void merge(T arr[],int left,int mid, int right){
        int i=left,j=mid+1;
        for(int k=left;k<=right;k++){
              if(i>mid){
                  arr[k]=item[j];
                  j++;
              }
              else if(j>right){
                  arr[k]=item[i];
                  i++;
              }
              if(item[i]<item[j]){
                  arr[k]=item[i];
                  i++;
              }
              else{
                  arr[k]=item[j];
                  j++;
              }
        }
          for(int l=left;l<=right;l++)
              item[l]=arr[l];
    }
    
    void merge2(T arr[],int left,int mid,int right){
        int i=left,j=mid+1;
        int k=left;
        while(i<=mid&&j<=right){
            if(item[i]<item[j]){
                arr[k++]=item[i];
                i++;
            }
            else
            {
                 arr[k++]=item[j];
                 j++;
            }
        }
        while (i <= mid)
        {
            arr[k++] = item[i];
            i++;
        }
        while(j<=right){
            arr[k++]=item[j++];
        }
        for(int l=left;l<=right;l++){
            item[l]=arr[l];
        }
    }
    void merge_sort(T arr[], int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge2(arr, left, mid, right);
        return;
    }

    public:
    void mergeSort(T arr[],int n){
        item=new T[n];
        for(int i=0;i<n;i++)
             item[i]=arr[i];
        merge_sort(arr,0,n-1);
        delete [] item;
    }
    //自底向上的归并排序
    // T* item = new T[n];
    // for (int i = 0; i < n; i++)
    //     item[i] = arr[i];
    // for (int sz = 1; sz <= n; sz += sz)
    // {
    //     for (int i = 0; i + sz <= n; i += sz * 2)
    //         merge2(arr, i, i + sz - 1, std::min(i + sz * 2 - 1, n - 1));
    // }
    // delete[] item;
};
#endif