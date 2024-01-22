#include<iostream>
using namespace std;
template <typename T>
void swap(T &a,T &b);

int main(){
    int a=5,b=3;
    swap(a,b);
    cout<<a<<b<<endl;
    return 0;

}
template<typename T>
void swap(T &a,T &b){
    T temp;
    temp=a;
    a=b;
    b=temp;
}
