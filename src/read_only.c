#include <stdio.h>

char *
addr()
{
   char *k = "Niger!";
   return k;
}

int
main()
{
   char *a = "Niger!";

   /* Stack allocated! String literal is on the stack. */
   char k[] = "Niger!"; 

   /* Output: Same! */
   addr() == a && fprintf(stdout, "Same!\n");

   /* Ouput: Diff! */
   addr() != k && fprintf(stdout, "Diff!\n");

   return 0;
}
