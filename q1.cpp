#include <iostream>
#include <string.h>
using namespace std;

struct person
{
    char nams[50];
    char DOBs[10];
    float income;
};

int main()
{
    struct person ob1;
    cin>>ob1.nams;
    cin>>ob1.DOBs;
    cin>>ob1.income;
    
    float year_t = 2020;
    float month_t = 05;
    float date_t = 23;

    float year_b = (ob1.DOBs[6]-48)*1000 + (ob1.DOBs[7]-48)*100 + (ob1.DOBs[8]-48)*10 + (ob1.DOBs[9]-48);
    float month_b = (ob1.DOBs[0]-48)*10 + (ob1.DOBs[1]-48);
    float date_b = (ob1.DOBs[3]-48)*10 + (ob1.DOBs[4]-48);
    
    float age = year_t - year_b + (1/12)*(month_t-month_b) + (1/365)*(date_t - date_b);
    if(age>40)
    cout<<ob1.income;
    return 0;
}
