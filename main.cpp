#include <iostream>
#include "crypt.h"
using namespace  std;
int main() {
    srand(time(0));
    lli pid=rand() % (10000000000-2) + 2;;
    cout<<pid;
    while(check_prime(pid)!=1){
        pid=rand() % (10000000000-2) + 2;;
         cout<<"enter";
    }
dh(pid,0,0,2,0,6,0,0);
    return 0;
}
