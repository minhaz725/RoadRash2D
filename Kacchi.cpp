#include <bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--){
    int pB=5 , pM=10 , pO= 1 , pG=1 , pP=3 ;
    int nB=0,nM=0,nO=0,nG=0,nP=0;
    int B=0,M=0,O=0,G=0,P=0;  //cost per kg
    long long int p=0;
    int s=0,n=0,c=0; //n->number of sold pot c->cost

    //input//
    cin>>B>>M>>O>>G>>P;
    cin>>nB>>nM>>nO>>nG>>nP;



    cin>>p>>s;
    bool stock=true; //flag to check stock
    while(1)
    {
        if(nB==nM && nM==nO && nO==nG && nG==nP) {stock=false ;break;}

        int cB=0,cM=0,cO=0,cG=0,cP=0;

        if(nB==0) {cB=pB*B;}
        else if(nB-pB>=0) {nB=nB-pB;cB=0;}
        else if(nB-pB<0) {cB=(pB-nB)*B;nB=0;}

        if(nM==0) {cM=pM*M;}
        else if(nM-pM>=0) {nM=nM-pM;cM=0;}
        else if(nM-pM<0) {cM=(pM-nM)*M;nM=0;}

        if(nO==0) {cO=pO*O;}
        else if(nO-pO>=0) {nO=nO-pO;cO=0;}
        else if(nO-pO<0) {cO=(pO-nO)*O;nO=0;}

        if(nG==0) {cG=pG*G;}
        else if(nG-pG>=0) {nG=nG-pG;cG=0;}
        else if(nG-pG<0) {cG=(pG-nG)*G;nG=0;}

        if(nP==0) {cP=pP*P;}
        else if(nP-pP>=0) {nP=nP-pP;cP=0;}
        else if(nP-pP<0) {cP=(pP-nP)*P;nP=0;}


        c =c+ cB+cM+cO+cG+cP;

        if (c>p) break;
        else n++;

    }
    if(stock==false)
    {

        int perpot=pB*B+pM*M+pO*O+pG*G+pP*P;

        int money= ((p-c)/perpot)*s + n*s;

        cout<<money<<"\n";
    }
    else cout<<n*s<<"\n";
}
    return 0;
}
