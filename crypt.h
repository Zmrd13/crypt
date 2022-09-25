#ifndef PARENT_H
#define PARENT_H
#include <cmath>
#include <bitset>
#include <random>
#include<bits/stdc++.h>
using lli = long long int;
using namespace std;


lli powMod(lli arg, lli pow, lli mod ){
    arg%=mod;

    if (pow == 0) return 1;
    lli z = powMod(arg  %mod, (pow / 2)  %mod, mod);
    z%=mod;
    if (pow % 2 == 0)
        return (z  %mod*z  %mod) % mod;
  else
    return (arg  %mod*z  %mod*z  %mod) % mod;
}
int gcdmodif(lli &a, lli &b, lli &x){
    x = std::min(a,b);
    while (x > 0) {

        if (a % x == 0 && b % x == 0) {
            break;
        }
        x--;
    }
    a/=x;
    b/=x;
    return x; 
}


int discreteLogarithm(int a, int b, int m) {
    int perf=0;
    int n = (int) sqrt (m) + 1;
 
    unordered_map<int, int> value;

    for (int i = n; i >= 1; --i)
        value[ powMod (a, i * n, m) ] = i;
 perf++;
    for (int j = 0; j < n; ++j)
    {
     

        int cur = (powMod (a, j, m) * b) % m;
perf++;

        if (value[cur])
        {
            
            int ans = value[cur] * n - j;

            if (ans < m){
             cout<<endl<<"perf="<<perf<<endl;
                return ans;
                    }        }
    }
    cout<<endl<<"/perf="<<perf<<endl;
    return -1;
}
bool check_prime(lli n) {
  bool is_prime = true;

 
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (lli i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}
void findPrimefactors(unordered_set<lli> &s, lli n)
{

    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }

    for (lli i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
 

    if (n > 2)
        s.insert(n);
}

lli findPrimitive(lli n)
{
    unordered_set<lli> s;

    if (!check_prime(n))
        return -1;
 

    lli phi = n - 1;
 
    // Find prime factors of phi and store in a set
    findPrimefactors(s, phi);

    for (lli r=2; r <= phi; r++)
    {

        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
 
            if (powMod(r, phi/(*it), n) == 1)
            {
                flag = true;
                break;
            }
         }
 
         if (flag == false)
           return r;
    }

    return -1;
}
int dh(lli p){
    lli g,x,a, y,  b , ka,  kb;
if(!check_prime(p)){
    return 0;
}
g=findPrimitive(p);
g%p;

   printf("The key : %lld\n", p);
   a=rand()%(p-1 + 1) + 1;
    a=3;
   a%=p;
    printf("The private key a for Alice : %lld\n", a);
    x = powMod(g%p, a%p, p);

  
  b=rand()%(p-1 + 1) + 1;
  b=32;
  b%=p;
    printf("The private key b for Bob : %lld\n\n", b);
    y = powMod(g%p, b%p, p)%p ;
    ka = powMod(y%p, a%p, p)%p;
    kb = powMod(x%p, b%p, p)%p;
    std::bitset<16> kab(ka);
    std::bitset<16> kbb(kb);
   cout<<endl<<ka<<endl<<kb<<endl;
   cout<<kbb<<endl<<kab;
   cout<<"\nDIFF="<<kab.to_ullong() -kbb.to_ullong();
}
int test_res(int arg){
    return arg*(arg*-1);

}

#endif