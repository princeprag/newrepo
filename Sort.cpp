#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node* next;
    Node(int data)
    {
        this->val=data;
        this->next=NULL;
    }
};

void Qsort(vector<int>& vec,int sI,int lI)
{
   if(sI>=lI) return;

   int pivot=vec[lI];
   int i=sI;

   for(int k=sI;k<lI;k++)
   {
       if(vec[k]<pivot)
       {  
         
           swap(vec[k],vec[i]);
           i++;
       }
   }

   swap(vec[lI],vec[i]);

   Qsort(vec,sI,i-1);
   Qsort(vec,i+1,lI);

}

void MergeSort(vector<int>& vec,int sI,int lI)
{
    if(sI>=lI) return;
    int mid=(sI+lI)/2;
    MergeSort(vec,sI,mid);
    MergeSort(vec,mid+1,lI);

    int p1=sI,p2=mid+1,t=0;
   
    while(p1<=mid && p2<=lI)
    {
        if(vec[p1]<=vec[p2])
        {
            p1++;
        }
        else
        {
            int ix=p2;
            int val=vec[p2];

            while(ix!=p1)
            {
                vec[ix]=vec[ix-1];
                ix--;
            }

            vec[p1]=val;
            p1++;
            p2++;
            mid++;
        }
 }

    return;
}



Node* MergeSortLL(Node* nn)
{
    
    if(!(nn->next)) return nn;

    Node *fast,*slow,*prev=NULL;
    fast=slow=nn;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }

    prev->next=NULL;
    Node* rg= MergeSortLL(slow);
    Node* lf= MergeSortLL(nn);

  
   
    fast=rg,slow=lf;
    Node* root=NULL,*temp;


    while(fast && slow)
    {
        if(slow->val<=fast->val)
        {
            if(!root)
            {
                root=slow;
                temp=root;
                
            }
            else
            {
                temp->next=slow;
                temp=temp->next;
            }
            
            slow=slow->next;
            
        }
        else
        {
             if(!root)
            {
                root=fast;
                temp=root;
                
            }
            else
            {
                temp->next=fast;
                temp=temp->next;
            }
            
            fast=fast->next;


        }

    }

        if(!fast)
        {
            temp->next=slow;
        }
        else temp->next=fast;
    
        return root;
}

//creates a max heap
void maxheapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    // Initialize largest as root 
    int l = 2*i + 1; 
    // left = 2*i + 1 
    int r = 2*i + 2;

    //right = 2*i + 1 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r;  

    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        maxheapify(arr, n, largest); 
    } 

} 

void minheapify(int arr[], int n, int i) 
{ 
    int smallest = i; 
    // Initialize largest as root 
    int l = 2*i + 1; 
    // left = 2*i + 1 
    int r = 2*i + 2;

    //right = 2*i + 1 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r;  

    if (smallest != i) 
    { 
        swap(arr[i], arr[smallest]); 
        minheapify(arr, n, smallest); 
    } 

} 

void heapSort(int arr[], int n) 
{ 
    
    for (int i = n/2 - 1; i >= 0; i--) 
        minheapify(arr, n, i); 
                  //maxheapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
       
        swap(arr[0], arr[i]); 
        minheapify(arr, i, 0); 

        // maxheapify(arr, i, 0); 
    } 

}




int main()
{
  
   int n,a;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   heapSort(arr,n);
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";

  



}


////////////// Binary Min Heap /////////////
// A C++ program to demonstrate common Binary Heap Operations 
#include<iostream> 
#include<climits> 
using namespace std; 

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 

// A class for Min Heap 
class MinHeap 
{ 
	int *harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap 
public: 
	// Constructor 
	MinHeap(int capacity); 

	// to heapify a subtree with the root at given index 
	void MinHeapify(int ); 

	int parent(int i) { return (i-1)/2; } 

	// to get index of left child of node at index i 
	int left(int i) { return (2*i + 1); } 

	// to get index of right child of node at index i 
	int right(int i) { return (2*i + 2); } 

	// to extract the root which is the minimum element 
	int extractMin(); 

	// Decreases key value of key at index i to new_val 
	void decreaseKey(int i, int new_val); 

	// Returns the minimum key (key at root) from min heap 
	int getMin() { return harr[0]; } 

	// Deletes a key stored at index i 
	void deleteKey(int i); 

	// Inserts a new key 'k' 
	void insertKey(int k); 
}; 

// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new int[cap]; 
} 

// Inserts a new key 'k' 
void MinHeap::insertKey(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	// First insert the new key at the end 
	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	swap(&harr[i], &harr[parent(i)]); 
	i = parent(i); 
	} 
} 

// Decreases value of key at index 'i' to new_val. It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, int new_val) 
{ 
	harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	swap(&harr[i], &harr[parent(i)]); 
	i = parent(i); 
	} 
} 

// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 


// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int i) 
{ 
	decreaseKey(i, INT_MIN); 
	extractMin(); 
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] < harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] < harr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
        //recursively restoring heap property
		MinHeapify(smallest); 
	} 
} 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	MinHeap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin(); 
	return 0; 
} 
