#include <iostream>
#include "mVector.h"
#include <vector>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    double A[3]={1.1,1.2,1.3};
    mVector B(3,A);
    B.ShowVector();
    mVector C(B);
    double resize[5]={1, 2, 3,4.3,5};
    B.resizedata(resize,5);
    B.pushdata(1);
    B.ShowVector();
    double resize1[6]={4,3,2,1,0,9.9};
    mVector D(6,resize1);
    mVector E(6);
    E=B;
    cout<<"The equal Vector "<<endl;
    E.ShowVector();
    E=(B+D);
    cout<<"The added vector"<<endl;
    E.ShowVector();
    E+=0.0001;
    E.ShowVector();
    cout<<"Using index notation "<<E(50)<<endl;
    bool b=(E==B);
    cout<<"value of b"<<b<<endl;
    E=B;
    b=(E==B);
    cout<<"value of b"<<b<<endl;
    return 0;
}
