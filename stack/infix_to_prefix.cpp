#include<bits/stdc++.h>
using namespace std;

int givePref(char c)
{
   if(c=='^') return 3;
   else if(c=='/' || c=='*') return 2;
   else if(c=='+' || c=='-') return 1;
   else return 0;
}

string infix_to_postfix_for_prefix(string s)
{
    stack<char> st;
    string ans="";

    for(int i=0;i<s.size();i++)
    {
        if(('A'<=s[i] && s[i]<='Z') || ('a'<=s[i] && s[i]<='z') || ('0'<=s[i] && s[i]<='9') || s[i]==' ') ans+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }

            if(!st.empty()) st.pop();
        }
        else
        {
            if(s[i]=='^')
            { 
              while(!st.empty() &&  givePref(s[i]) <= givePref(st.top()))
              {
                ans+=st.top();
                st.pop();
              }
            }
            else
            {
                while(!st.empty() &&  givePref(s[i]) < givePref(st.top()))
                {
                ans+=st.top();
                st.pop();
                }
                
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
                ans+=st.top();
                st.pop();

    }

    return ans;
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string ans="";

    for(int i=0;i<s.size();i++)
    {
        if(('A'<=s[i] && s[i]<='Z') || ('a'<=s[i] && s[i]<='z') || ('0'<=s[i] && s[i]<='9') || s[i]==' ') ans+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }

            if(!st.empty()) st.pop();
        }
        else
        {
            while(!st.empty() &&  givePref(s[i]) <= givePref(st.top()))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
                ans+=st.top();
                st.pop();

    }

    return ans;
}

string infix_to_prefix(string s)
{
    string s1="";
    for(int i=s.size()-1;i>=0;i--)
    {
           if(s[i]=='(') s1+=')';
           else if(s[i]==')') s1+='(';
           else s1+=s[i];
    }

    string s2=infix_to_postfix_for_prefix(s1);

    reverse(s2.begin(),s2.end());

    return s2;


}

string format_string(string s)
{
       string ss="";
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='+')
           {
               if(i>0 && s[i-1]!=' ') ss+=' ';
               ss+=s[i];
               if(s[i+1]!=' ') ss+=' ';
           }
           else if(s[i]=='-')
           {
               if(i>0 && s[i-1]!=' ') ss+=' ';
               ss+=s[i];
               if(s[i+1]!=' ') ss+=' ';
           }
           else if (s[i]!='+' && s[i]!='-' && s[i]!='(' && s[i]!=')') ss+=s[i];
       }

       return ss;
}




int main()
{


     string s;
     getline(cin,s);

     cout<<infix_to_prefix(s)<<endl;
     cout<<infix_to_postfix(s)<<endl;


      
}