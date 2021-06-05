#include<bits/stdc++.h>
using namespace std;
int main()
{

   float emb,dsp,poc,iot,hss,emt;

   emb=7;
   poc=dsp=10;
   hss=9;
   iot=9;
   emt=8;

  
   

   float spi;

  
   float kk=emb*7+poc*8+hss*6+iot*6+emt*6+dsp*6;
   spi=kk/39;

   cout<<"The SPI is "<<spi<<endl;

   
   float pcpi=8.37;
   // cout<<"Enter The previous cpi:";
   // cin>>pcpi;

   

   cout<<"Your current CPI is"<<(pcpi*167  + kk)/206<<endl;

   float nc=pcpi*167+kk;

   for(float p=6;p<=9.5;p=p+0.1)
   {
      float ncc=(p*45+nc)/251;

      cout<<p<<" "<<ncc<<endl;
   }
   
   
    
}