#include<bits/stdc++.h>
using namespace std;
int main()
{
    float dsp,acs,dc,mcr,crl,dsa,cn,itc,cc;
    cout<<"Consu Chem "; cin>>cc; 
    cout<< "Data Structures "; cin>>dsa; 
    cout<< "Advance  Control "; cin>>acs; 
    cout<< "Compu Networks "; cin>>cn;

    cout<< "ITC "; cin>>itc; 
    cout<< "Digital  "; cin>>dc; 
    cout<< "Micro Lab "; cin>>mcr; 
    cout<< "DSP labs "; cin>>dsp;
    cout<< "Control lab "; cin>>crl;



    float ans;
    ans=((cc+dsa+acs+cn+itc+dc)*6+(mcr+dsp+crl)*3)/45;

    cout<<ans<<endl;
}

/*
Consu Chem 9
Data Structures 8
Advance  Control 8
Compu Networks 9
ITC 9
Digital  9
Micro Lab 9
DSP labs 10
Control lab 9

Result- 8.8
*/