#include<iostream>
using namespace std;
#define BINARY_SEARCH_TREE
class BSTNode 
{
    public:
        BSTNode() 
        {
            left = right = 0;
        }
        BSTNode(int e, BSTNode *l = 0, BSTNode *r = 0) 
        {
            info = e; left = l; right = r;
        }
        int info;
        BSTNode *left, *right;
};
class BST 
{
    BSTNode *root;
    public:
        BST() 
        {
            root = 0;
        }
        ~BST() 
        {
            clear();
        }      
        void clear() 
        {
            clear(root); 
            root = 0;
        }
        void clear(BSTNode *root)
        {
                if(root!=0)
                {
                    clear(root->left);
                    clear(root->right);
                    delete(root);
                }
        }
        bool isEmpty() const 
        {
            return root == 0;
        }
        void insert(int el) 
        {
            BSTNode *p = root, *prev = 0;
            while (p != 0) 
            { 
                prev = p;
                if (el < p->info)
                    p = p->left;
                else p = p->right;
            }
            if (root == 0) // tree is empty;
                root = new BSTNode(el);
            else if (el < prev->info)
                prev->left = new BSTNode(el);
            else prev->right = new BSTNode(el);
        }
        void insert_rec(int el)
        {
            BSTNode *p=root;
            if(p==NULL)
            {
                BSTNode *n=new BSTNode(el);
                n->info=el;
                p=n;
            }
            else
            {
                if(el<p->info)
                {
                    insert(el);
                    p=p->left;
                }
                else
                {
                    insert(el);
                    p=p->right;
                }
            }
            return;
        }
        void delete_merge(BSTNode *node)
        {
            BSTNode *tmp = node;
            if (node != 0) 
            {
                if (!node->right) 
                    node = node->left; 
                else if (node->left == 0) 
                    node = node->right; 
                else 
                { 
                    tmp = node->left; 
                    while (tmp->right != 0)
                        tmp = tmp->right;
                        tmp->right = node->right; 
                        tmp = node; 
                        node = node->left; 
                }
                delete tmp;
            }
        }
        void DeleteByMerging(int el) 
        {
            BSTNode *node = root, *prev = 0;
            while (node != 0) 
            {
            if (node->info == el)
                break;
            prev = node;
            if (el < node->info)
                node = node->left;
            else node = node->right;
            }
            if (node != 0 && node->info == el)
                if (node == root)
                    delete_merge(root);
                else if (prev->left == node)
                    delete_merge(prev->left);
                else delete_merge(prev->right);
            else if (root != 0)
                cout << "element" << el << "is not in the tree\n";
            else cout << "the tree is empty\n";
        }
        void preorder() 
        {
            preorder(root); 
        }
        void preorder(BSTNode *p) 
        {
            if (p != 0) 
            {
                visit(p);
                preorder(p->left);
                preorder(p->right);
            }
        }
        void inorder() 
        {
            inorder(root);
        }
        void inorder(BSTNode *p) 
        {
            if (p != 0) 
            {
                inorder(p->left);
                visit(p);
                inorder(p->right);
            }
        }
        void postorder() 
        {
            postorder(root);
        }
        void postorder(BSTNode* p) 
        {
            if (p != 0) 
            {
                postorder(p->left);
                postorder(p->right);
                visit(p);
            }
        }
        int search(int el)
        {
            return search(root,el);
        }
        int search(BSTNode* p, int el) 
        {
            while (p != 0)
                if (el == p->info)
                    return p->info;
                else if (el < p->info)
                    p = p->left;
                else p = p->right;
            return 0;
        }
        virtual void visit(BSTNode* p) 
        {
            cout << p->info << ' ';
        }
        int printGivenLevel(int level)
        {
            return printGivenLevel(root,level);
        }
        int printGivenLevel(BSTNode *root,int level)
        {
            if (root == NULL)
                return 0 ;
            if (level == 1)
                cout<< root->info<< "    ";
            else if (level > 1)
            {
                printGivenLevel(root->left, level-1);
                printGivenLevel(root->right, level-1);
            }
            return 0;
        }
        int countleafNode()
        {
            return countleafNode(root);
        }
        int countleafNode(BSTNode *root)
        {
            if (root == NULL )
                return 0;
            if((root->left == NULL &&   root->right == NULL))
                return 1;
            else
                return ( countleafNode(root->left) +  countleafNode(root->right));
        }
        int countNonleafNode()
        { 
            return countNonleafNode(root);
        }
        int countNonleafNode(BSTNode *root)
        {
            if (root==NULL || (root->left == NULL &&  root->right == NULL))
                return 0;
            else
                return (1 + countNonleafNode(root->left) +  countNonleafNode(root->right));
        }
        int maxDepth()
        {
            return maxDepth(root);
        }
        int maxDepth(BSTNode* root)
        {
            if (root == NULL)
                return 0;
            else
            {
                /* compute the depth of each subtree */
                int lDepth = maxDepth(root->left);
                int rDepth = maxDepth(root->right);
                /* use the larger one */
                if (lDepth > rDepth)
                    return(lDepth + 1);
                else return(rDepth + 1);
            }
        }
        void mirrorImage()
        {
            mirrorImage(root);
        }
        void mirrorImage(BSTNode *root)
        {
            if (root == NULL)
                return;
            else
            {

                mirrorImage(root->left);
                mirrorImage(root->right);
                swap(root->left,root->right);
            }
        }
        int is_equal(BST x)
        {
            return is_equal(root,x.root);
        }
        int is_equal(BSTNode *r1, BSTNode *r2)
        {
         if(r1==0 && r2==0) return 1;
         if(r1->info==r2->info && is_equal(r1->left,r2->left)&&is_equal(r1->right,r2->right))
            return 1;
         else
            return 0;
        }

};
int main()
{
    BST r;
    r.insert(5);
    r.insert(3);
    r.insert(7);
    r.insert(1);
    r.insert_rec(4);
    //r.DeleteByMerging(4);
    r.search(4)? cout<<"\nelement found" : cout<<"\nelement not found";
    cout<<"\nrec_preorder:";
    r.preorder();
    cout<<"\nrec_inorder:";
    r.inorder();
    cout<<"\nrec_postorder";
    r.postorder();
    cout<<"\nlevel by level order traversal ="<<r.printGivenLevel(2);
    cout<<"\nNo. of leaf nodes="<<r.countleafNode();
    cout<<"\nNo. of non leaf nodes="<<r.countNonleafNode();
    cout<<"\nHeight="<<r.maxDepth()<<endl;
    r.mirrorImage();
    cout<<"After mirror image call:";
    r.inorder();
    BST r1;
    r1.insert(7);
    r1.insert(8);
    r1.insert(6);
    r1.insert(3);
    r1.insert(9);
    cout<<endl;
    if(r.is_equal(r1))
        cout<<" equal";
    else cout<<"Not equal";

    
}