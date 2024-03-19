# Segmentation fault

This is a collection of mistakes C programmers do that may caused an
unexpected behavoir and/or introduce bugs in code. Regularly skim
through this document if you are trying to learn C.

## Read-only Memory

See `src/`

```c
char *a = "Niger!";

/* Segmentation fault! */
a[4] = '?';
```

### Why?

The string literal `"Niger!"` isn't stack allocated, it's some read-only
memory that may lead to undefined behavoirs if we attempt to write to it.

See!

```c
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
```

Want to create a copy of it? use `strdup` for example.

## Using Unsafe Memory

```c
char *a = NULL, *b;

/* Segmentation fault! */
*a = 'a';

/* Depends, but never rely on this! */
*b = 'b';

/* Good. */
b = "b";
a = "a";
```

### Why?

## Freeing twice or Unallocated object.

```
int *a = malloc(sizeof(int));

*a = 10;

fprintf(stdout, "%p -> %d\n", a, *a);

free(a);

/* Can now be used by an external program! */
fprintf(stdout, "%p -> %d\n", a, *a);

/* Segmentation fault! */
free(a);
```

```
free(0x7fcad5b0fcc0);
```




