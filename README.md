# Segmentation fault

These are a collection of mistakes C programmers do that may caused an
unexpected behavoir and introduce bugs. Regularly skim through this
document to improve your C coding skills.

## Read-only Memory

See `src/`

```c
char *a = "Niger!"

/* Segmentation fault! */
a[4] = '?'
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

## Freeing Unallocated Memory


### Why?




