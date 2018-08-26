#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
#define REP(i,n)  for(int i=0;i<n;i++)
#define pb push_back

double f(double x)
{
    //return x*x*x-0.165*x*x+3.993*pow(10,-4);
      return (x-1)*(x-1)*(x-1)+0.512;
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
    double x0,x1,x2,presAprx,prevAprx,tolerance;
    cout<<"Enter the initial two guesses, tolerance and iteration number"<<endl;
    cin>>x0>>x1>>tolerance>>itr;

    printf("%2s%10s%10s%10s%10s%10s","It","Xi-1","Xi","Xi+1","Er","  f(Xi+1)\n" );

    for(int i=0; i<itr; i++)
    {
         x2 = x1 - ( f(x1)*(x1-x0) ) / ( f(x1)-f(x0) );

        if(f(x2)==0)
        {
            printf("%2d %10.5lf %10.5lf %10.5lf %10.5lf %10.5lf\n",i+1,x0,x1,x2,Rerror(x2,x1),f(x2));
            printf("Required root is: %10.5lf\n",x2);
            break;
        }
        presAprx=x2;
        prevAprx=x1;
        if(Rerror(presAprx,prevAprx)<tolerance)
        {
            printf("%2d %10.5lf %10.5lf %10.5lf %10.5lf %10.5lf\n",i+1,x0,x1,x2,Rerror(x2,x1),f(x2));
            printf("Required root is: %10.5lf\n",x2);
            break;
        }
        printf("%2d %10.5lf %10.5lf %10.5lf %10.5lf %10.5lf\n",i+1,x0,x1,x2,Rerror(x2,x1),f(x2));
        x0=x1;
        x1=x2;
    }

    return 0;
}
