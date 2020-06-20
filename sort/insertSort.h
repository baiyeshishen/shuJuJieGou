/*
 * @Author: your name
 * @Date: 2020-06-04 14:32:46
 * @LastEditTime: 2020-06-06 09:21:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \shu_ju_jie_gou\sort\insertSort.h
 */ 

#ifndef INSERT_SORT
#define INSERT_SORT

#include<iostream>
template<typename T>
void insertSort(T arr[],int n){
     for(int i=1;i<n;i++){
         T e=arr[i];
         int j;
         for(j=i;j>0&&arr[j-1]>e;j--){
             arr[j]=arr[j-1];
         }
         arr[j]=e;
     }
}

template<typename T>
void insertSort2(T arr[],int n){
    for(int i=1;i<n;i++){
         T e=arr[i];
         int j;
         for(j=i;j>0;j--){
             if(arr[j-1]>e)
                  arr[j]=arr[j-1];
             else
                break;             
         }
         arr[j]=e;
    }
}
#endif