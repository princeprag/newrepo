#include <bits/stdc++.h> 
using namespace std; 

bool isOperator(char c) 
{ 
	return (!isalpha(c) && !isdigit(c)); 
} 

int getPriority(char C) 
{ 
	if (C == '-' || C == '+') 
		return 1; 
	else if (C == '*' || C == '/') 
		return 2; 
	else if (C == '^') 
		return 3; 
	return 0; 
} 

string infixToPostfix(string infix) 
{ 
	infix = '(' + infix + ')'; 
	int l = infix.size(); 
	stack<char> st; 
	string output; 

	for (int i = 0; i < l; i++) 
    { 

		
		if (isalpha(infix[i]) || isdigit(infix[i])) 
			output += infix[i]; 

		else if (infix[i] == '(') 
			st.push('('); 

		else if (infix[i] == ')') { 

			while (st.top() != '(') 
            { 
				output += st.top(); 
				st.pop(); 
			} 

		
			st.pop(); 
		} 

		// Operator found 
		else
        { 
			
			if (isOperator(st.top())) 
            { 
				while (getPriority(infix[i]) <= getPriority(st.top())) 
                { 
					output += st.top(); 
					st.pop(); 
				} 

				
				
			}
            // Push current Operator on stack 
            st.push(infix[i]); 



		} 
	} 
	return output; 
} 

string infixToPrefix(string infix) 
{ 
	
	int l = infix.size(); 

	// Reverse infix 
	reverse(infix.begin(), infix.end()); 

	// Replace ( with ) and vice versa 
	for (int i = 0; i < l; i++) { 

		if (infix[i] == '(') { 
			infix[i] = ')'; 
			
		} 
		else if (infix[i] == ')') { 
			infix[i] = '('; 
			
		} 
	} 

	string prefix = infixToPostfix(infix); 

	// Reverse postfix 
	reverse(prefix.begin(), prefix.end()); 

	return prefix; 
} 

string postfix_to_infix(string s)
{
    stack<string> st;
    int sz=s.size();
    for(int i=0;i<sz;i++)
    {
       if(isOperator(s[i]))
       {
           string p1=st.top();
           st.pop();
           string p2=st.top();
           st.pop();

           string fs= "(" + p2 + s[i] + p1 +")";
           st.push(fs);

       }
       else
       {  
           string  k(1,s[i]);
           st.push(k);
       }
       

    }

    return st.top();
}

string prefix_to_infix(string s)
{
    stack<string> st;
    int sz=s.size();
    for(int i=sz-1;i>=0;i--)
    {
       if(isOperator(s[i]))
       {
           string p1=st.top();
           st.pop();
           string p2=st.top();
           st.pop();

           string fs= "(" + p1 + s[i] + p2 +")";   // NOTE CHANGE FROM THE CODE OF post_to_inf
           st.push(fs);

       }
       else
       {  
           string  k(1,s[i]);
           st.push(k);
       }
       

    }

    return st.top();
}

string postfix_to_prefix(string s)
{
    stack<string> st;
    int sz=s.size();
    for(int i=0;i<sz;i++)
    {
       if(isOperator(s[i]))
       {
           string p1=st.top();
           st.pop();
           string p2=st.top();
           st.pop();

           string fs= s[i] + p2  + p1 ;
           st.push(fs);

       }
       else
       {  
           string  k(1,s[i]);
           st.push(k);
       }
       

    }

    return st.top();
}
double opt(double n1,double n2,string s)
{
    if(s=="*") return n1*n2;
    else if(s=="/") return n1/n2;
    else if(s=="+") return n1+n2;
    else if(s=="-") return n1-n2;
    
    return 0;
}

int evaluate_postfix(string s)
{
    stack<string> st;
    for(int i=0;i<s.size();i++)
    {
        if(isOperator(s[i]))
        {
            string s1,s2;
            s1=st.top();
            st.pop();
            s2=st.top();
            st.pop();

            double p1=stoi(s1),p2=stoi(s2);
            double res=opt(p2,p1,string(1,s[i]));

            st.push(to_string(res));


        }
        else
        {
            st.push(string(1,s[i]));
        }
        
    }

    return stod(st.top());


}

string prefix_to_postfix(string s)
{
    stack<string> st;
    int sz=s.size();
    for(int i=sz-1;i>=0;i--)
    {
       if(isOperator(s[i]))
       {
           string p1=st.top();
           st.pop();
           string p2=st.top();
           st.pop();

           string fs=  p1 + p2 + s[i] ;
           st.push(fs);

       }
       else
       {  
           string  k(1,s[i]);
           st.push(k);
       }
       

    }

    return st.top();
}

// Driver code 
int main() 
{ 
   // string s;
    
	string s = "(2*3)*(3*5)+2"; 
    string pref=infixToPrefix(s);
    string post=infixToPostfix(s);
	cout <<pref<<" "<<post<<std::endl; 
    cout<<evaluate_postfix(post)<<endl;
	return 0; 
} 












////////// expression solving fully paranthesised** infix
/*
double opt(double n1,double n2,string s)
{
    if(s=="*") return n1*n2;
    else if(s=="/") return n1/n2;
    else if(s=="+") return n1+n2;
    else if(s=="-") return n1-n2;
    
    return 0;
}


int main()
{
    string s;
    getline(cin,s);
    s="("+s+")";
    int n=s.size();
   
    stack<string> st;
    bool f=true;
    for(int i=0;i<n;i++)
    {
        
        if(s[i]==' ') continue;
        else if(s[i]=='(') st.push(string(1,s[i]));
        else if(s[i]==')')
        {    
            
            if(st.size()<2) {cout<<"ERROR"<<endl;  f=false; break;}
            
            string s1=st.top(); //operand2
            st.pop();
            string s2=st.top();  //operator
            st.pop();
            
            
            if(s2=="(")
            {
                st.push(s1);
                continue;
            }
            
            
            
            string s3=st.top(); //operand1
            st.pop(); 
            if(s2=="-" && s3=="(")  // negative
            {
                s1=s2+s1;
                st.push(s1);
                continue;
                
                
            }
            
            string s4=st.top(); // closing brackets
            st.pop();
            
            
         
            if(s4=="(")
            {   
                double f1=stod(s3);
                double f2=stod(s1);
                double res=opt(f1,f2,s2);
                
                if(s2=="/" && f2==0.0) {cout<<"ERROR"<<endl;  f=false; break;}
               
                st.push(to_string(res));
                
                
            }
            else
            {
                cout<<"ERROR"<<endl; f=false; break;
            }
            
            
        }
        else st.push(string(1,s[i]));
            
        
        
    }
    
    if(f)
    cout<<stod(st.top())<<endl;
    return 0;
}

*/