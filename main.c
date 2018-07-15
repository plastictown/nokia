#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "tests.h"

/** \brief
 *
 * \param[in] N -
 * \param[out] buf -
 *
 */
void get_primes(unsigned long N, unsigned long* buf);

int main()
{
  // we take into account punctuation marks as well as
  // all other visible printed characters
  const char* text = "That's one small step for a man, one giant leap for mankind";

  list_test(20, 5);

  tree_height_test();

  min_max_test(1u);

  word_count_test(text);

  const unsigned long num = 20;

  unsigned long buf[num];
  memset(buf, 0 , num*sizeof(unsigned long));

  get_primes( num, buf);

  for(unsigned i=0u; i<num; i++)
    printf("%u ", (unsigned)buf[i]);


  return EXIT_SUCCESS;
}

void get_primes(unsigned long N, unsigned long* buf)
{
  if(buf == NULL)
    return;
  uint32_t idx = 0u;
  double sqr = sqrt(ULONG_MAX);
  for(unsigned long x = 1; x < sqr; x++)
    for(unsigned long y = 1; y < sqr; y++)
  {
    unsigned long x2 = x * x;
    unsigned long y2 = y * y;
    unsigned long n = 4 * x2 + y2;
    unsigned prime = 0;

    if ((n % 12 == 1 || n % 12 == 5))
      prime = (prime == 0)?1:0;

    n -= x2;
    if (n % 12 == 7)
      prime = (prime == 0)?1:0;

    n -= 2 * y2;
    if (x > y && n % 12 == 11)
      prime = (prime == 0)?1:0;

    if(n%2 == 0 || n%5 ==0 || n%3 == 0 || n%7==0)
      prime = 0;

    if(prime == 1)
    {
      buf[idx++] = n;

      if(idx >= N)
        return;
    }
    // TODO
  }
}

