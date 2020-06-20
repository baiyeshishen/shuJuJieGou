/*
 * @Author: your name
 * @Date: 2020-06-06 18:26:44
 * @LastEditTime: 2020-06-06 18:35:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \shu_ju_jie_gou\ListNode\listNode.h
 */ 
#ifndef LIST_NODE_H
#define LIST_NODE_H
template<typename T>
class ListNode{
    private:
    struct Node{
        T value;
        Node*next;
        Node(T value){
            this->value=value;
            next=NULL;
        }
       Node*root;
       public:
       ListNode(T arr[],int n){
           
       }
    };
};
#endif