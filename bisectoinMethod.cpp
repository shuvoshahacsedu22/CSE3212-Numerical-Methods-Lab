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

    double xl,xu,xm,presA,prevA,Etol;

    xl=0,xu=0.11,Etol=5.00;
    printf("%s%10s%10s%10s%10s%10s","It","Xl","Xu","Xm","Er","f(Xm)\n" );
    for(int i=0; i<100; i++)
    {

        xm = (xl+xu)/2.0;
        if(i==0){
        printf("%2d%10lf%10lf%10lf%10s%10lf\n",i+1,xl,xu,xm,"---",f(xm));
        }
        if(f(xl)*f(xm) < 0 )  xu=xm;
        else if(f(xm)*f(xu) < 0) xl=xm;
        else
        {

            printf("Required root is: %lf\n",xm);
            break;
        }
        presA=(xl+xu)/2.0;
        prevA=xm;
        if(Rerror(presA,prevA)<Etol)
        {
            printf("%2d%10lf%10lf%10lf%10lf%10lf\n",i+2,xl,xu,xm,Rerror(presA,prevA),f(xm));
            printf("Required root is: %lf\n",presA);
            break;
        }
        printf("%2d%10lf%10lf%10lf%10lf%10lf\n",i+2,xl,xu,xm,Rerror(presA,prevA),f(xm));

    }





    return 0;
}
