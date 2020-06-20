#include<vector>
#include<iostream>
#include<queue>
template <typename Key typename Value>
class BinarySearchTree{
    private:
    struct Node{
       Key key;
       Value value;
       Node*left;
       Node*right;
       Node(Key key, Value value){
           this->key=key;
           this->value=vlaue;           
           this->left=NULL:
           this->right=NULL:
       }
       Node(Node*node){
           this->key=node->key;
           this->value=node->value;
           this->left=node->left;
           this->right=node->right;
       }
    };
    Node*root;
    int count;

    void destroy(Node* node){
        if(!node)
          return;
        destroy(node->left);
        destroy(node-right);
        delete node;
        count--;
    }

    Node*insert(Node*node,Key key,Value value){
        if(node==NULL){
            count++;
            rerurn new Node(key,value);
        }
        if(key==root->key)
             root->value=value;
        if(key<root->key)
              root->left=insert(node->left,key,value);
        if(key>root->key)
              root->right=insert(node->right,key,value);
        return node;
    }
    
    bool contain(Node*node,Key key){
        if(node==NULL){
            return false;
        }
        if(key==node->key)
            return true;
        else if(key<node->key)
              return contain(node->left,key);
        else 
              return contain(node->right,key);
    }
    
    Value*search(Node*node,Key key){
        if(node==NULL){
            return NULL;
        }
        if(node->key==key)
            return &(node->value);
        else if(node->key>key)
            return search(node->lefet,key);
        else 
            return search(node->right,key);
    }
   
    void preorder(Node*node){
        if(node==NULL){
            return ;
        }
        std::cout<<node->key<<endl;
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node*node){
        if(node==NULL){
            return;
        }
        inorder(node->left);
        std::cout<<node->key<<endl;
        inorder(node->right);
    }
    
    void postorder(Node*node){
        if(node==NULL){
            return;
        }
        postorder(node->left);
        postorder(node->right)；
        std::cout<<node->key<<endl;
    }
    
    Node*minimum(Node *node){
        if(node->left==NULL)
            return node;
        return minimum(node->left);
    }

    Node*maximum(Node*node){
        if(node->right==NULL){
            return node;
        }
        return maximum(node->right);
    }
   
    Node*removeMin(Node*node){
        if(node->left==NULL){
            Node*rightNode=node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left= removeMin(node->left);
        return node;
    }
    
    Node*removeMax(Node*node){
        if(node->right==NULL){
            Node*leftNode=node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right=removeMax(node->right);
        return node;
    }
    
    Node*remove(Node*node,Key key){
        if(node=NULL){
            return NULL;
        }
        if(node->key==key){
             if(node->left==NULL){
                 Node*nodeRight=node->right;
                 delete node;
                 count--;
                 return nodeRight;
             }
             else if(node->right==NULL){
                 Node*nodeLeft=node->left;
                 delete node;
                 count--;
                 return nodeLeft;
             }
             else{
                 Node*minRight=minimum(node->right);
                 Node*successor=new Node(minRight);
                 count++;
                 successor->right=removeMin(node->right);
                 successor->left=node->left;
                 delete node;
                 count--;
                 return successor;
             }
        }
        else if(node->key<key){
            node->right = remove(node->right, key);
            return node;
        }
        else {
             node->left=remove(node->left,key);
             return node;
        }
    }
    public:

    Value*search(Key key){
        return search(root,key);
    }
    BinarySearchTree(){
        root=NULL;
        count=0;
    }

    ~BinarySearchTree(){
        destroy(root);
    }

    bool empty(){
        return count==0;
    }

    int size(){return count;}

    void insert(Key key,Value value){
        root=insert(root, key, value);
    }

    bool contain(Key key){
        return contain(root, key);
    }

    void preorder(){
        preorder(root);
    }
    
    void inorder(){
        inorder(root);
    }

    void postorder(){
        postorder(root);
    }

    void levelOrder(){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*p=q.front();
            q.pop();
            std::cout<<p->key<<endl;
            if(p->left)
               q.push(p->left);
            else if(p->right)
                q.push(p->right);
        }
    }

    Key minimun(){
        assert(count!=0);
        Node*node=minimum(root);
        return node->key;
    }

    Key maximum(){
        assert(count!=0);
        Node*node=maximum(root);
        return node->key;
    }

    void removeMin(){
        if(root)
            root=removeMin(root);
    }

    void removeMax(){
        if(root)
           root=removeMax(root);
    }
    
    void remove(Key key){
        root=remove(root,key);
    }
};