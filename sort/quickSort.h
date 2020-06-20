/*
 * @Description: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-06-04 14:45:25
 * @lastEditors: sueRim
 * @LastEditTime: 2020-06-05 23:13:52
 */ 
#ifndef QUICK_SORT
#define QUICK_SORT
template<typename T>
int partition(T arr[],int left,int right){
    T item=arr[left];
    while(left<right){
        while(left<right&&arr[right]>=item)
            right--;
        while(left<right&&arr[left]<=item)
           left++;
        if(left<right)
        std::swap(arr[left],arr[right]);
    }
     std::swap(item,arr[left]);
    return left;
}
//三路快排
// template<typename T>
// int partition3(T arr[],int left,int right){
//     /*  
//     *arr[left+1...lt]<arr[left];
//     *arr[lt+1,i)=arr[left]
//     *arr[gt...right]>arr[left]
//     */
//    std::swap(arr[left],arr[rand()%(right-left+1)+left]);
//    T item=arr[left];
//    int lt=left;
//    int gt=right+1;
//    int i=left+1;
//    while(i<gt){
//        if(arr[i]<item){
//            std::swap(arr[++lt],arr[i++]);
//        }
//        else if(arr[i]==item)
//            i++;
//        else
//        {
//            std::swap(arr[--gt],arr[i]);
//        } 
//    }
//    std::swap(arr[left],arr[lt]);
// }
template <typename T>
void quick_sort(T arr[], int left, int right)
{
    if (left >= right)
        return;
    int mid = partition(arr, left, right);
    quick_sort(arr, left, mid - 1);
    quick_sort(arr, mid + 1, right);
}
template <typename T>
void quickSort(T arr[], int n)
{
    quick_sort(arr, 0, n - 1);
}
#endif