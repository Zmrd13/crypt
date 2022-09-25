#include <iostream>
#include "crypt.h"

using namespace  std;
int main() {
    srand(time(NULL));
    lli pid=rand() % ((int)pow(10,11)-(int)pow(10,9)) + (int)pow(10,9);;
    cout<<pid;
    while(check_prime(pid)==0){
        pid=rand() % ((int)pow(10,11)-(int)pow(10,9 )) +(int)pow(10,9) ;;
         //cout<<"enter";
    }
  //  cout<<"enter1";

dh(pid);
    return 0;
}
