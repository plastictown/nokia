#include <stdlib.h>

#include "tests.h"

// Achtung! Memory allocation errors are not checked!!!
int main()
{
  // we take into account punctuation marks as well as
  // all other visible printed characters
  const char* text = "That's one small step for a man, one giant leap for mankind";

  // removes every fifth item
  list_test( 20, 5 );

  // the tree is created inside the function
  tree_height_test();

  // prints the minimum and maximum values
  min_max_test( 1u );

  // calculates the number of words of different lengths
  word_count_test( text );

  // computes and outputs the first N prime numbers
  primes_test( 10ul );

  return EXIT_SUCCESS;
}



