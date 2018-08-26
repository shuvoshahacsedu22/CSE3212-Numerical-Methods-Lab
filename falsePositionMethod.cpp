#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
#define REP(i,n)  for(int i=0;i<n;i++)
#define pb push_back

double f(double x)
{
    return x*x*x-0.165*x*x+3.993*pow(10,-4);
}
double Rerror(double presA,double prevA)
{

    return fabs( ((presA-prevA)*100)/presA );

}

int main()
{

    double xl,xu,xr,presA,prevA,Etol;

    xl=0,xu=0.11,Etol=5.00;
    printf("%s%10s%10s%10s%10s%10s","It","Xl","Xu","Xr","Er","f(Xr)\n" );
    for(int i=0; i<100; i++)
    {

        xr = ( (xu*f(xl)-xl*f(xu)) /(f(xl)-f(xu)) );

        if(i==0){
        printf("%2d%10lf%10lf%10lf%10s%10lf\n",i+1,xl,xu,xr,"---",f(xr));
        }
        if(f(xl)*f(xr) < 0 )  xu=xr;
        else if(f(xr)*f(xu) < 0) xl=xr;
        else
        {

            printf("Required root is: %lf\n",xr);
            break;
        }
        presA=( (xu*f(xl)-xl*f(xu)) /(f(xl)-f(xu)) );
        prevA=xr;
        if(Rerror(presA,prevA)<Etol)
        {
            printf("%2d%10lf%10lf%10lf%10lf%10lf\n",i+2,xl,xu,xr,Rerror(presA,prevA),f(xr));
            printf("Required root is: %lf\n",presA);
            break;
        }
        printf("%2d%10lf%10lf%10lf%10lf%10lf\n",i+2,xl,xu,xr,Rerror(presA,prevA),f(xr));

    }





    return 0;
}
