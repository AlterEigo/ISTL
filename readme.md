
# Template Library
## Shared ptr
    A shared ptr is a pointeur that is aware of all other shared pointers
that point to the exact same memory space. It is automatically destroyed
and can be transfered between functions.

**Example**: Smart pointer creation
```c
void func(int *p2)
{
    int a = *p2;

    // ... some code ...

    // 'p2' has no need to be destroyed, since it has been passed
    // as usual pointer
    return;
}

int main(void)
{
    // Pointer declaration, MB_INT is a type's describing structure
    SMART int *p = snew(MB_INT);

    func(p);

    // 'p' is automatically destroyed here
    return (0);
}
```

**Example**: Shared and weak pointers
```c
int *func(void)
{
    SMART int *sp = shared_ptr(MB_INT);

    return (spcopy(sp));
}

int main(void)
{
    SMART int *sp = func();
    SMART wptr_t wp = make_weak(sp);

    // ... code ...

    SMART int *sp2 = wptr_lock(wp);

    if (sp2 != NULL)
	// Memory was not freed

    // ... code ...

    // Automatic free of 'sp', 'wp', 'sp2'
}
```

# Inspiration (copyright)
    Snaipe's work on unique and shared pointer realisation in C
