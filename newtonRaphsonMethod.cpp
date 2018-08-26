#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
#define REP(i,n)  for(int i=0;i<n;i++)
#define pb push_back

double f(double x)
{
    //return x*x*x-0.165*x*x+3.993*pow(10,-4);
     // return (x-1)*(x-1)*(x-1)+0.512;
     return x*x*x - 0.03*x*x + 2.4*pow(10,-6);
}
double fx(double x){

    //return 3*x*x-2.0*0.165*x;
    //return 3*(x-1)*(x-1);
    return 3*x*x - 0.06*x;

}
double Rerror(double presA,double prevA)
{

    return fabs( ( (presA-prevA)/presA )*100.0);

}

int main()
{
    int itr;
    double x0,x1,presAprx,prevAprx,tolerance;
    cout<<"Enter the initial guess, tolerance and iteration number"<<endl;
    cin>>x0>>tolerance>>itr;

    printf("%2s%10s%10s%10s","It","X","Er","f(X)\n" );
    printf("%2s%10.5lf%10s%10s","0",x0,"----","----\n" );
    for(int i=0; i<itr; i++)
    {

        x1 = x0-f(x0)/fx(x0);

        if(f(x1)==0)
        {
            printf("%2d %10.5lf %10.5lf %10.5lf\n",i+1,x1,Rerror(x1,x0),f(x1));
            printf("Required root is: %10.5lf\n",x1);
            break;
        }
        presAprx=x1;
        prevAprx=x0;
        if(Rerror(presAprx,prevAprx)<tolerance)
        {
            printf("%2d %10.5lf %10.5lf %10.5lf\n",i+1,x1,Rerror(presAprx,prevAprx),f(x1));
            printf("Required root is: %10.5lf\n",presAprx);
            break;
        }
        printf("%2d %10.5lf %10.5lf %10.5lf\n",i+1,x1,Rerror(presAprx,prevAprx),f(x1));
        x0=x1;
    }

    return 0;
}
