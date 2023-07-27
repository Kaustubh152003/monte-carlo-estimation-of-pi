#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int get_rand_for_range(int a,int b)
{
    if(a>b)
    b=a;
    int x = rand();
    x=x%(b-a+1);
    x=x+a;
    return x;
}
void initialize_random()
{
    srand(time(0));
}
void get_random_cords_for_square(int xlim,int ylim,int* x,int* y)
{
    *x=get_rand_for_range(0,xlim);
    *y=get_rand_for_range(0,ylim);
}
int check_if_inside(double x,double y,int r)
{
    if(sqrt(x*x+y*y)<=r)
    return 1;
    else
    return 0;
}
double get_pi(int xlim,int n)
{
    int j=0;
    double hits=0;
    while(j<n)
    {
        int x,y;
        get_random_cords_for_square(xlim,xlim,&x,&y);
        hits=hits+check_if_inside(x,y,xlim);
        j++;
    }
    double total=n;
    double p=hits/total;
    double pi=4*p;
    return pi;
}
int main() 
{
    initialize_random();
    printf("%lf ",get_pi(100000,10000000));

    return 0;
}
