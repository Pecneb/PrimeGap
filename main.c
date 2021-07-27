#include <stdlib.h>
#include <stdio.h>

/* 
g is the gap size we want to find.
m is the start number, n is the end number.
The function returns the firs prime pair that has the g sized gap between them.
We only looking for two primes after each other for example: 2-3, 3-5, 5-7...etc.
If the function not finding primes between m and n, it returns {0, 0}.
*/
long long* gap(int g, long long m, long long n) {
  // allocate memory for the two returning primes
  long long *ret = malloc(2*sizeof(long long));
  ret[0] = 0;
  ret[1] = 0;
  long long a = 0;
  // This is the part when we use Sieve of Eratostheles
  // enumerating all the primes until n
  int *primes = malloc(n*sizeof(int));
  primes[0] = 0;
  primes[1] = 0;
  for(int i=2; i<n; i++) primes[i] = 1;
  for(int i=2; i*i<n; i++) {
    if(primes[i] == 1) {
      for(int j=i*i; j<n; j+=i) {
        primes[j] = 0;
      }
    }
  }
  // Finding the first gap that equals g.
  for(long long i = m; i<n; i++) {
    if(primes[i] == 1) {
      printf("%lld, ", i);
      if(a!=0) {
        if(i-a == g) {
          ret[0] = a;
          ret[1] = i;
          return ret;
        }
        a=i;
      } else a=i;
    }
  }
  printf("\n");
  return ret;
}

int main() {
  //add your test code here! 
  return 0;
}
