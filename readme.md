
# Template Library
## Shared ptr
    A shared ptr is a pointeur that is aware of all other shared pointers
    that point to the exact same memory space. It is automatically destroyed
    and can be transfered between functions.

    **Example**:
    ```c
    void func(int *p2)
    {
	// 'p2' is another shared_ptr
	int a = *p2;

	// ... some code ...

	// 'p2' is automatically destroyed before return
	return;
    }

    int main(void)
    {
	// Pointer declaration, MB_INT is a type's describing structure
	SMART int *p = shared_ptr(MB_INT);

	// Making another shared_ptr from the first one
	// A shared ptr **ALWAYS** has to be copied this way,
	// otherwise its internal reference counter is not increased
	func(spcopy(p));

	// 'p' is automatically destroyed here
	return (0);
    }
    ```

# Inspiration (copyright)
    Snaipe's work on unique and shared pointer realisation in C
