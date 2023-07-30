#include <iostream>
#include <stdlib.h>
#define PI 3.142857
#include <math.h>
using namespace std;

double error_percentage(double og,double x)
{
    double diff=abs(og-x);
    diff=diff*100;
    diff=diff/og;
    return diff;
}
int per_test(double og,double x,double err_per)
{
    double ep=error_percentage(og,x);
    printf("error_percentage: %lf\n",ep);
    if(ep<err_per)
    {
        printf("TEST PASSED.\nERROR PERCENTAGE IS LESS THAN %lf percent\n",err_per);
        return 1;
    }
    else
    {
        printf("TEST FAILED.\nERROR PERCENTAGE IS MORE THAN %lf percent\n",err_per);
        return 0;
    }
}
int diff_test(double og,double x,double allowed_diff)
{
    double diff=abs(og-x);
    printf("difference: %lf\n",diff);
    if(diff<=allowed_diff)
    {
        printf("TEST PASSED.\nDIFFERENCE IS LESS THAN %lf \n",allowed_diff);
        return 1;
    }
    else
    {
        printf("TEST FAILED.\nDIFFERENCE IS MORE THAN %lf \n",allowed_diff);
        return 0;
    }
}
char* get_data_from_file(char* filename)
{
    char* str=(char*)malloc(1000*sizeof(char));
    int j=0;
    FILE * fptr;
    fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        printf("ERROR: FILE CANT BE READ\n");
        return NULL;
    }
    else
    {
        fscanf(fptr,"%s",str);
        return str;
    }
}
double string_to_float(char* str)
{
    int j=0;
    double x=0;
    while(str[j]!='\0' && str[j]!='.')
    {
        x=x*10+str[j]-'0';
        j++;
    }
    j++;
    int k=1;
    while(str[j]!='\0')
    {
        double a=(str[j]-'0')/pow(10,k);
        x=x+a;
        k++;
        j++;
    }
    return x;
}
int main()
{
    double og,x,err_per,allowed_diff;
    og=PI;
    err_per=0.3;
    allowed_diff=0.01;
    char filename[]="answer.txt";
    char* content=get_data_from_file(filename);
    printf("content of the file: %s\n",content);
    x=string_to_float(content);
    printf("pi value from the file: %lf\n",x);
    per_test(og,x,err_per);
    diff_test(og,x,allowed_diff);
    
}
