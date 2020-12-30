
bool com(string s1,string s2)
{
    string a,b;
    a=s1+s2;
    b=s2+s1;
    return a>b;
}
 
 
 
 string largestNumber(vector<int> A) {
    vector<string> d;
    string ans="";
    for(int i=0;i<A.size();i++)
    {   
        string q=to_string(A[i]);
        d.push_back(q);
    
    }
    
    sort(d.begin(),d.end(),com);
    
    
    for(int i=0;i<d.size();i++)
    { ans+=d[i];
      ans+=" ";
      if(d[0]=="0")
       break;
    }

  return ans;
    
}