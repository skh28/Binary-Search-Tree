//Scott Ha
#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
    
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
       
        bool isEmpty() const { return root==NULL; }
	    void Add(int);
		void inorder(tree_node*);
        void print_inorder();
		void postorder(tree_node*);
		void print_postorder();
};

//Compare element with root and insert left or insert right side of tree
void BinarySearchTree::Add(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    
    if(isEmpty()) root = t;
    else
    {
        tree_node* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
    }
}

//Orders the Nodes in Ascending order
void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_inorder()
{
  inorder(root);
}

//Orders the Nodes in Descending order
void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
        if(p->left) postorder(p->left);
    }
    else return;
}

//Post order print
void BinarySearchTree::print_postorder()
{
  postorder(root);
}

int main()
{
    BinarySearchTree b;
    int ch,tmp,tmp1;
    while(1)
    {
		// Menu for User selection
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. In-Order Traversal "<<endl;
	   cout<<" 3. Post-Order Traversal "<<endl;
       cout<<" 4. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    cin>>tmp;
                    b.Add(tmp);
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    b.print_inorder();
                    break;
		   case 3 : cout<<endl;
					cout<<" Post-Order Traversal "<<endl;
					b.print_postorder();
					break;
           case 4 : 
                    return 0;
                    
       }
    }
}