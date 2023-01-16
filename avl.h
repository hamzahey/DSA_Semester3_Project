// C++ program for AVL Tree  
#include<iostream> 
#include "node.h"
#include "bowling.h"
using namespace std; 
   
// An AVL tree node 
template <typename Z> 
class AVLNode  
{  
    public: 
    Z key;  
    AVLNode *left;  
    AVLNode *right;  
    int depth;  
};  
template <typename P> 
//get max of two nodeegers 
int max(int a, int b){
    if (a>b)
    return a;
    else
    return b;    

    
}  
   template <typename P> 
//function to get height of the tree 
int depth(AVLNode<P> *n)  
{  
    if (n == NULL)  
        return 0;  
    return n->depth;  
}  
template <typename P> 
// allocate a new node with key passed
AVLNode<P>* newNode(P key)  
{  
    AVLNode<P>* node1 = new AVLNode<P>(); 
    node1->key = key;  
    node1->left = NULL;  
    node1->right = NULL;  
    node1->depth = 1; // new node added as leaf 
    return(node1);  
}  
template <typename P> 
// right rotate the sub tree rooted with y
AVLNode<P> *rightRotate(AVLNode<P> *y)  
{  
    AVLNode<P> *x = y->left;  
    AVLNode<P> *T2 = x->right;  
   
    // Perform rotation  
    x->right = y;  
    y->left = T2;  
   
    // Update heights  
    y->depth = max(depth(y->left),  
                    depth(y->right)) + 1;  
    x->depth = max(depth(x->left),  
                    depth(x->right)) + 1;  
   
    // Return new root  
    return x;  
}  
   template <typename P> 
// left rotate the sub tree rooted with x 
AVLNode<P> *leftRotate(AVLNode<P> *x)  
{   
    AVLNode<P> *y = x->right;  
    AVLNode<P> *T2 = y->left;  
   
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
    // Update heights  
    x->depth = max(depth(x->left),  
                    depth(x->right)) + 1;  
    y->depth = max(depth(y->left),  
                    depth(y->right)) + 1;  
   
    // Return new root  
    return y;  
}  
   template <typename P> 
// Get Balance factor of node N  
int getBalance(AVLNode<P> *N)  
{  
    if (N == NULL)  
        return 0;  
    return depth(N->left) -  
           depth(N->right);  
}    
//insertion operation for node in AVL tree 
template <typename P> 
AVLNode<P>* insert(AVLNode<P>* node1,P key,string name)  {  
    //normal BST rotation
    if (node1 == NULL)  
        return(newNode(key));  
   
    if (name < node1->key.complete)  
        node1->left = insert(node1->left, key,key.complete);  
    else if (name > node1->key.complete)  
        node1->right = insert(node1->right, key,key.complete);     
    else // Equal keys not allowed  
        return node1;  
   
    //update height of ancestor node
    node1->depth = 1 + max(depth(node1->left),  depth(node1->right));  
   
    int balance = getBalance(node1);        //get balance factor
   
    // rotate if unbalanced 
   
    // Left Left Case  
    if (balance > 1 && key < node1->left->key)  
        return rightRotate(node1);  
   
    // Right Right Case  
    if (balance < -1 && key > node1->right->key)  
        return leftRotate(node1);  
  // Left Right Case  
    if (balance > 1 && key > node1->left->key)  
    {  
        node1->left = leftRotate(node1->left);  
        return rightRotate(node1);  
    }  
   
    // Right Left Case  
    if (balance < -1 && key < node1->right->key)  
    {  
        node1->right = rightRotate(node1->right);  
        return leftRotate(node1);  
    }  
    return node1;  
}  
   template <typename P> 
// find the node with minimum value 
AVLNode<P> * minValueNode(AVLNode<P>* node)  
{  
    AVLNode<P>* current = node;  
   
    // find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
   
    return current;  
}  
template <typename P> 
// delete a node from AVL tree with the given key  
AVLNode<P>* deleteNode(AVLNode<P>* root, P key)  
{  
    if (root == NULL)  
        return root;  
   
    //perform BST delete 
    if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
   
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
   
else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            AVLNode<P> *temp = root->left ?  
                         root->left :  
                         root->right;  
   
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp;   
            free(temp);  
        }  
   else
        {  
            AVLNode<P>* temp = minValueNode(root->right);  
   
            root->key = temp->key;  
   
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->key);  
        }  
    }  
   
    if (root == NULL)  
    return root;  
   
    // update depth  
    root->depth = 1 + max(depth(root->left),  
                           depth(root->right));  
   
    // get balance factor 
    int balance = getBalance(root);  
   
    //rotate the tree if unbalanced
   
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
   
    // Left Right Case  
    if (balance > 1 &&  getBalance(root->left) < 0)  {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
    // Right Right Case  
    if (balance < -1 &&  getBalance(root->right) <= 0)  
        return leftRotate(root);  
   
    // Right Left Case  
    if (balance < -1 && getBalance(root->right) > 0)   {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
    return root;  
}  
// prnodes inOrder traversal of the AVL tree
int i=2;
template <typename P> 
void inOrder(AVLNode<P> *root)  
{  
    if(root != NULL)  
    {  
        inOrder(root->left);
        cout<<i++<<endl;
        cout << root->key <<endl;  
        inOrder(root->right);  
    }  
} 