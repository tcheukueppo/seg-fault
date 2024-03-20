#include <stdlib.h>
#include <stdio.h>

int
main()
{
   char *c = "Burkina";
   char **a = malloc(sizeof(char *));

   if (!a) 
      return 1;

   *a = c;

   fprintf(stdout, "%s\n", *a);

   /* Segmentation fault! */
   free(*a);

   free(a);

   return 0;
}
