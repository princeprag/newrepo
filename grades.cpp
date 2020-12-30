#include<bits/stdc++.h>
using namespace std;
int main()
{

   float emb,dsp,poc,iot,hss,emt;

   emb=7;
   poc=dsp=10;
   hss=9;
   iot=8;
   emt=7;

   emb=6;
   poc=dsp=4;
   hss=4;
   iot=6;
   emt=7;

   

   float spi;

   // for(float dd=7;dd<=10;dd++)
   // { 
   // cout<<dd<<" :";

   for(dsp=0; dsp<=10;dsp++)
   {

   cout<<"DSP grades:"<<dsp<<endl;
   float kk=emb*7+poc*8+hss*6+iot*6+emt*6+dsp*6;
   spi=kk/39;

   cout<<"The SPI is "<<spi<<endl;

   
   float pcpi=6.33;
   // cout<<"Enter The previous cpi:";
   // cin>>pcpi;

   

   cout<<"Your current CPI is"<<(pcpi*167  + kk)/206<<endl;
   }
   
    
}