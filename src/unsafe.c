#include <stddef.h>

int
main()
{
   char *a = NULL, *b;

   /* Segmentation fault! */
   *a = 'a';

   /* Depends, but never rely on this! */
   *b = 'b';

   /* Good. */
   b = "b";
   a = "a";

   return 0;
}
