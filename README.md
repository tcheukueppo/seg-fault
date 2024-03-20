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

Want to create a copy of the read-only memory? use `strdup` for example.

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

For `a`, `*a = 'a'` causes a segmentation fault as it tries to write into an
invalid memory location since `NULL` is basically just `0x0`.

For `b`, `*b = 'b'` writes `'b'` into an arbitrary memory location pointed
by `b` and this doesn't necessarily report a segmentation fault but leads
to undefined results or crashes.

## Freeing An Object Twice 

You may think of this mistake to be unlikely to happened more often but in
reality that isn't always the case.

```
int *a = malloc(sizeof(int));

*a = 10;

fprintf(stdout, "%p -> %d\n", a, *a);

free(a);

/* Invalid read as this mem was reclaimed! */
fprintf(stdout, "%p -> %d\n", a, *a);

/* Invalid write. */
*a = 4;

/* Segmentation fault! */
free(a);
```

A bit similar to freeing an unallocated object except that this one has
never been (re)used by the running program.

```
free(0x7fcad5b0fcc0);
```

### Why?

Well, here's obvious, freeing an already reclaimed memory should caused an
unexpected behavoir.

## Freeing A Read-Only Memory

You may have confused between read-only and heap allocated memory.

```c
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
```

### Why?

Simply because you don't have the right! This memory is managed by the
compiler not you!!
