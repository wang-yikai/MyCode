#include <stdio.h>
#include <stdlib.h>

void main() {
  int *p;
  p = malloc( 5 * sizeof(int) ); //same as calloc( 5, sizeof(int) )

  p[0] = 2;
  printf( "p[0]: %d\n", 0[p] );

  int *q;
  q = (int*)malloc( 20 * sizeof(float) );

  q[0] = 5;
  printf( "q[0]: %d\n", 0[q] );

  free(q);
  printf( "After free(), q[0]: %d\n", 0[q] );

  struct{ int a; char c1; char c2; } b;
  printf( "sizeof(b): %lu\n", sizeof(b) );

  struct foo { int i; char c3; };
  struct foo *s = (struct foo *)malloc(sizeof(struct foo));
  (*s).i = 764;
  printf( "s->i: %d\n", s->i );
}
