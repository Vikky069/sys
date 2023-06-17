#include<iostream>
using namespace std;

#define square(a) a*a
#define equation a+b-c

int main(){
    int a,b,c;
    float num;
    cout<<"Enter number to find the square\n";
    scanf("%f",&num);
    float d = square(num);
    cout<<"Square is "<<d;

    cout<<"\nEnter a,b,c\n";
    scanf("%d%d%d",&a,&b,&c);
    cout<< "result of equation is "<<equation;
    return 0;
}
