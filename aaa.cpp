#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<int>  karatsuba(vector<int> v,vector<int> w)
{
    if(v.size()==1 || w.size()==1)
    {
          vector<int> z;
          z.push_back(v.at(0)*w.at(0));
          return z;
    };

    int size= v.size();
    vector<int> l_a,l_b,r_a,r_b,s_a,s_b;
    for(int i=0;i<size/2;i++)
    {
      l_a.push_back(v[i]);
      l_b.push_back(w[i]);
    }

    for(int i=size/2;i<size;i++)
    {
      r_a.push_back(v[i]);
      r_b.push_back(w[i]);
    }

    for(int i=0;i<size/2;i++)
    {s_a.push_back(l_a[i]+r_a[i]);
    s_b.push_back(l_b[i]+r_b[i]);}

    vector<int> x,y,z;
    x=karatsuba(l_a,l_b);
    y=karatsuba(r_a,r_b);
    z=karatsuba(s_a,s_b);


    
    ll res=x*pow(10,a_s)+y+(z-y-x)*p;

    return res;


}


int main()
{ ll a,b;
  cin>>a>>b;
  ifstream infile;
  vector<ll> v(a),w(b);
  
  infile.open("test.txt");
  if(!infile)
  {
    cout<<"Unable to open file";
    exit(1);
  }

  for(int i=0;i<a;i++)
  { infile>>v[i];

  }

    for(int i=0;i<b;i++)
  { infile>>w[i];

  }

  
  vector<ll> x= karatsuba(v,w);
  
}