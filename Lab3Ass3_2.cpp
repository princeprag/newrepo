#include <bits/stdc++.h> 
using namespace std; 

class DNode { 
public: 
	int data; 
	DNode* next;
    DNode* prev; 
    DNode(int v)
    {
        this->data=v;
        this->next=NULL;
        this->prev=NULL;
    }
}; 

int giveLength(DNode* head)
{
    int l=0;
    DNode* temp=head;
    while(temp)
    {
        temp=temp->next;
        l++;
    }

    return l;
}

DNode* insertNode(DNode* node,DNode* head, int pos=-1)
{

     
      DNode *temp;
      if(pos==-1)
      {
           temp=head;
           while(temp!=NULL && temp->next!=NULL)
           {
               temp=temp->next;
           }

           if(temp==NULL) return  node;

           temp->next=node;
           node->prev=temp;
           return head;
      }
      else 
      {
          if(pos>giveLength(head))
          {
              return insertNode(node,head);
          }
          else
          {
              temp=head;
              pos--;
              while(pos--)
              {
                
                  temp=temp->next;
              }

              if(temp==head)
              {
                  node->next=temp;
                  temp->prev=node;
                  return node;
              }
              else
              {
                  node->next=temp->next;
                  temp->next->prev=node;
                  node->prev=temp;
                  temp->next=node;
                  return head;
              }


          }
      }
}


DNode* deleteNode(DNode* node,DNode* head)
{
     if(node==NULL || head==NULL) return head;
     DNode* temp=head;

     if(head==node)
     {
         head=head->next;
         head->prev=NULL;
         delete node;
         return head;
     }

     else
     {
         
     
     while(temp && temp->next!=node)
     {
         temp=temp->next;
     }

   
     if(temp==NULL) return head;

     temp->next=node->next;
     node->next->prev=temp;
     delete node;

     }

     return head;
}


int searchNode(int key,DNode* head)
{
     DNode* temp=head;
     while(temp)
     {
         if(temp->data==key) return 1;
         temp=temp->next;
     }

     return 0;
}

void printList(DNode* head)
{
     DNode* temp=head;
     while(temp)
     {
         cout<<temp->data;
         temp=temp->next;

         if(temp)
         {
             cout<<" ---><--- ";
         }
         else cout<<endl;
     }


}


int main() 
{ 
	DNode* n1 = NULL; 
	DNode* n2 = NULL; 
	DNode* n3 = NULL;
    DNode* n4 = NULL; 
	DNode* n5 = NULL; 
	DNode* n6 = NULL; 

	
	n1 = new DNode(1); 
	n2 = new DNode(2); 
	n3 = new DNode(3); 
    n4 = new DNode(4); 
	n5 = new DNode(5); 
	n6 = new DNode(6); 
     
   
    DNode *head=insertNode(n1,NULL);
    head=insertNode(n2,head);
    head=insertNode(n3,head);
    head=insertNode(n4,head,1);
    head=insertNode(n5,head,10);
    head=insertNode(n6,head);


    printList(head);
    head=deleteNode(n2,head);
    printList(head);
    head=deleteNode(n4,head);
    printList(head);

    cout<<searchNode(5,head)<<endl;
    cout<<searchNode(10,head)<<endl;



	


	return 0; 
} 


