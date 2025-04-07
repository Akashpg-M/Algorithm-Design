// n1 = a*10^n + b
// n2 = c*10^n + d
// ab * (10^ (2 * n/2)) + (ad+bc)*10^(n/2) + bd

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int karatsuba(int n1, int n2);

int main(){
  int a, b;
  cout<<"Enter first Number : ";
  cin>>a;
  cout<<"\nEnter Second Number : ";
  cin>>b;

  int res = karatsuba(a, b);
  cout<<"\nResult: "<<res;
}


int karatsuba(int n1, int n2){
  if(n1 < 10 && n2 < 10) return n1*n2;

  int h = max(floor(log10(n1))+1, floor(log10(n2))+1)/2;

  int power = pow(10, h);
  int a = n1/power;
  int b = n1%power;
  int c = n2/power;
  int d = n2%power;

  int ac = karatsuba(a, c);
  int bd = karatsuba(b, d);
  int ad_plus_bc = karatsuba(a+b, c+d) - ac - bd;

  int res = ac * pow(10, 2*h) + ad_plus_bc * pow(10, h) + bd;

  return res;

}
