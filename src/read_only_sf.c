int
main()
{
   char *a = "Niger!";

   /* Segmentation fault! */
   a[4] = '?';

   return 0;
}
