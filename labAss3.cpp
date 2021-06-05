#include <bits/stdc++.h> 
using namespace std; 

class Node { 
public: 
	int data; 
	Node* next; 
    Node(int v)
    {
        this->data=v;
        this->next=NULL;
    }
}; 

int giveLength(Node* head)
{
    int l=0;
    Node* temp=head;
    while(temp)
    {
        temp=temp->next;
        l++;
    }

    return l;
}

Node* insertNode(Node* node,Node* head, int pos=-1)
{

     
      Node *temp,*prev;
      if(pos==-1)
      {
           temp=head;
           while(temp!=NULL && temp->next!=NULL)
           {
               temp=temp->next;
           }

           if(temp==NULL) return  node;

           temp->next=node;
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
                  return node;
              }
              else
              {
                  node->next=temp->next;
                  temp->next=node;
                  return head;
              }


          }
      }
}


Node* deleteNode(Node* node,Node* head)
{
     if(node==NULL || head==NULL) return head;
     Node* temp=head;

     if(head==node)
     {
         head=head->next;
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
     delete node;

     }

     return head;
}


int searchNode(int key,Node* head)
{
     Node* temp=head;
     while(temp)
     {
         if(temp->data==key) return 1;
         temp=temp->next;
     }

     return 0;
}

void printList(Node* head)
{
     Node* temp=head;
     while(temp)
     {
         cout<<temp->data;
         temp=temp->next;

         if(temp)
         {
             cout<<" ---> ";
         }
         else cout<<endl;
     }


}


int main() 
{ 
	Node* n1 = NULL; 
	Node* n2 = NULL; 
	Node* n3 = NULL;
    Node* n4 = NULL; 
	Node* n5 = NULL; 
	Node* n6 = NULL; 

	
	n1 = new Node(1); 
	n2 = new Node(2); 
	n3 = new Node(3); 
    n4 = new Node(4); 
	n5 = new Node(5); 
	n6 = new Node(6); 
     
   
    Node *head=insertNode(n1,NULL);
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


