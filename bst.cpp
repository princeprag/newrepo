#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *left,*right;
    int val;
    Node(int value)
    {
        this->left=this->right=NULL;
        this->val=value;

    }


};

Node* insert(int value,Node *root)
{
    if(root==NULL)
    {
        Node* nd=new Node(value);
        return nd;
    }

    if(value < root->val)
    {
        Node* temp=insert(value,root->left);
        root->left=temp;
    }
    
    else
    {
        Node* temp=insert(value,root->right);
        root->right=temp;
    }

    return root;
    


}

Node* mmm= new Node(-1); 

void levelorder(Node* root)
{
       if(root==NULL) return;

       queue<Node*> qq;
       qq.push(root);
       qq.push(NULL);

       while(!qq.empty())
       {
           Node* fr=qq.front();
           qq.pop();

           if(fr==mmm)
           {
               cout<<-1<<" ";
               continue;
           }

           if(fr==NULL)
           {
               if(!qq.empty())
               {
                 cout<<endl;
                 qq.push(NULL);
               }

               continue;
           }

           cout<<fr->val<<" ";
           if(fr->left) qq.push(fr->left);
           else qq.push(mmm);
           if(fr->right) qq.push(fr->right);
           else qq.push(mmm);


       }

}

int main()
{
    int n,k;
    cin>>n;

    Node* root=NULL;
    


    for(int i=0;i<n;i++)
    { 
    cin>>k;
    
    root=insert(k,root);
    }

    

    levelorder(root);


   return 0;

}

