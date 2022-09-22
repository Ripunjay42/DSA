#include <iostream>
#define MAX_VALUE 65536
using namespace std;
class N 
{ 
   public:
      int k;
      N *l, *r;
      bool leftTh, rightTh;
};
class ThreadedBinaryTree 
{
   private:
   N *root;
   public:
   ThreadedBinaryTree() 
   { 
      root= new N();
      root->r= root->l= root;
      root->leftTh = true;
      root->k = MAX_VALUE;
   }
   void insert(int el) 
   {
      N *p = root;
      for (;;) 
      {
      if (p->k< el) 
      { //move to right thread
         if (p->rightTh)
            break;
         p = p->r;
      }
      else if (p->k > el) 
      { // move to left thread
         if (p->leftTh)
            break;
         p = p->l;
      }
      else 
      {
         return;
      }
   }
   N *temp = new N();
   temp->k = el;
   temp->rightTh= temp->leftTh= true;
   if (p->k < el) 
   {
      temp->r = p->r;
      temp->l= p;
      p->r = temp;
      p->rightTh= false;
   }
   else 
   {
      temp->r = p;
      temp->l = p->l;
      p->l = temp;
      p->leftTh = false;
   }
}
void inorder() 
{ 
    //print the tree
   N *temp = root, *p;
   for (;;) 
    {
      p = temp;
      temp = temp->r;
      if (!p->rightTh) 
      {
         while (!temp->leftTh) 
         {
            temp = temp->l;
         }
      }
      if (temp == root)
         break;
         cout<<temp->k<<" ";
      }
      cout<<endl;
   }
};
int main() 
{
   ThreadedBinaryTree t;
   cout<<"Threaded Binary Tree\n";
   t.insert(56);
   t.insert(23);
   t.insert(89);
   t.insert(85);
   t.insert(20);
   t.inorder();
   cout<<"\n";
}