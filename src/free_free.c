#include <stdlib.h>
#include <stdio.h>

int
main()
{
   int *a = malloc(sizeof(int));

   *a = 10;
   fprintf(stdout, "%p -> %d\n", a, *a);

   free(a);

   fprintf(stdout, "%p -> %d\n", a, *a);

   /* Segmentation fault! */
   free(a);

   return 0;
}
