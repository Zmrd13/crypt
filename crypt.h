#ifndef PARENT_H
#define PARENT_H
#include <cmath>
#include <random>
#include<bits/stdc++.h>
using lli = long long int;
using namespace std;


lli powMod(lli arg, lli pow, lli mod ){
    if (pow == 0) return 1;
    lli z = powMod(arg, pow / 2, mod);
    if (pow % 2 == 0)
        return (z*z) % mod;
  else
    return (arg*z*z) % mod;
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
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (lli i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when
    // n is a prime number greater than 2
    if (n > 2)
        s.insert(n);
}
 
// Function to find smallest primitive root of n
lli findPrimitive(lli n)
{
    unordered_set<lli> s;
 
    // Check if n is prime or not
    if (check_prime(n)==false)
        return -1;
 
    // Find value of Euler Totient function of n
    // Since n is a prime number, the value of Euler
    // Totient function is n-1 as there are n-1
    // relatively prime numbers.
    lli phi = n - 1;
 
    // Find prime factors of phi and store in a set
    findPrimefactors(s, phi);
 
    // Check for every number from 2 to phi
    for (lli r=2; r <= phi; r++)
    {
        // Iterate through all prime factors of phi.
        // and check if we found a power with value 1
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
int dh(lli p, lli g, lli x, lli a, lli y, lli b , lli ka, lli kb){
if(!check_prime(p)){
    return 0;
}
g=findPrimitive(p);

   printf("The key : %lld\n", p);
   a=rand()%(p-1 + 1) + 1;
    printf("The private key a for Alice : %lld\n", a);
    x = powMod(g, a, p); 
  
  b=rand()%(p-1 + 1) + 1;
    printf("The private key b for Bob : %lld\n\n", b);
    y = powMod(g, b, p); 
    ka = powMod(y, a, p); 
    kb = powMod(x, b, p); 
     
   cout<<endl<<ka<<endl<<kb;
}
int test_res(int arg){
    return arg*(arg*-1);

}

#endif