#include <bits/stdc++.h> 
using namespace std; 


template <class T>  class Node { 
public: 
	T data; 
	Node<T>* next;
    Node<T>* prev; 
    Node(T v)
    {
        this->data=v;
        this->next=NULL;
        this->prev=NULL;
    }
}; 

template <class T>  int giveLength(Node<T>* head)
{
    int l=0;
    Node<T>* temp=head;
    while(temp)
    {
        temp=temp->next;
        l++;
    }

    return l;
}

template <class T>  Node<T>* insertNode(Node<T>* node,Node<T>* head, int pos=-1)
{

      Node<T>* temp;
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


template <class T>  Node<T>* deleteNode(Node<T>* node,Node<T>* head)
{
     if(node==NULL || head==NULL) return head;
     Node<T>* temp=head;

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


template <class T>  int searchNode(T key,Node<T>* head)
{
     Node<T>* temp=head;
     while(temp)
     {
         if(temp->data==key) return 1;
         temp=temp->next;
     }

     return 0;
}

template <class T>  void printList(Node<T>* head)
{
     Node<T>* temp=head;
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

/*
    Node<int>* nl = NULL;  
	Node<int>* n1 = NULL; 
	Node<int>* n2 = NULL; 
	Node<int>* n3 = NULL;
    Node<int>* n4 = NULL; 
	Node<int>* n5 = NULL; 
	Node<int>* n6 = NULL; 


	
	n1 = new Node<int>(1); 
	n2 = new Node<int>(2); 
	n3 = new Node<int>(3); 
    n4 = new Node<int>(4); 
	n5 = new Node<int>(5); 
	n6 = new Node<int>(6); 
     
   
    Node<int>* head=insertNode(n1,nl);
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
*/

    Node<char>* nl = NULL;  
	Node<char>* n1 = NULL; 
	Node<char>* n2 = NULL; 
	Node<char>* n3 = NULL;
    Node<char>* n4 = NULL; 
	Node<char>* n5 = NULL; 
	Node<char>* n6 = NULL; 

    n1 = new Node<char>('A'); 
	n2 = new Node<char>('E'); 
	n3 = new Node<char>('I'); 
    n4 = new Node<char>('O'); 
	n5 = new Node<char>('U'); 
	n6 = new Node<char>('X'); 
     
   
    Node<char>* head=insertNode(n1,nl);
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

    cout<<searchNode('A',head)<<endl;
    cout<<searchNode('E',head)<<endl;



	


	return 0; 
} 


