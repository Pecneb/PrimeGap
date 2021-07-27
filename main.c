#include <stdlib.h>
#include <stdio.h>

long long* gap(int g, long long m, long long n) {
  long long *ret = malloc(2*sizeof(long long));
  ret[0] = 0;
  ret[1] = 0;
  long long a = 0;
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
