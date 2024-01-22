#include<iostream>

using namespace std;

int sum(int a,int b){
   return a+b;
}

int sum(float a, float b){
   return a+b;
}

int main(){
   cout << sum(1.3, 2.7);
   return 0;
}
