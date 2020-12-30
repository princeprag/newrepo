int binary(vector<int> &A,int B,int sI,int lI)
{
    if(lI<sI) return 0;
    int mid=(sI+lI)/2;
    
    if(mid==A.size()-1) return A.size();
    else if(mid==0) return 0;
    
    if(A[mid]==B) return mid;
    else if(A[mid]<B && B<A[mid+1]) return mid+1;
    else if(A[mid]>B)
    return binary(A,B,sI,mid-1);
    else if(A[mid+1]<B)
    return binary(A,B,mid+2,lI);
    
    
}

int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sz=A.size();
    return binary(A,B,0,sz-1);
    
}
