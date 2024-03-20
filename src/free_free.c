#include <stdlib.h>
#include <stdio.h>

int
main()
{
   int *a = malloc(sizeof(int));

   *a = 10;
   fprintf(stdout, "%p -> %d\n", a, *a);

   free(a);

   /* Invalid read as this mem was reclaimed! */
   fprintf(stdout, "%p -> %d\n", a, *a);

   /* Invalid write */
   *a = 4;

   /* Segmentation fault! */
   free(a);

   return 0;
}
