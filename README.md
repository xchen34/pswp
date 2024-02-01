* 在 C 语言中，使用指针参数而不是直接使用值（如 long long 类型）的主要原因是为了能够在函数内部修改变量的值，并且这些修改在函数返回后依然有效。这种做法通常称为“传递引用”或“传递地址”，虽然 C 语言本身不直接支持引用类型，但通过指针可以实现类似的效果。 对于您的 atoi2 函数： bool atoi2(const char *s, long long *nb) 这里的 long long *nb 是一个指向 long long 类型的指针，这意味着函数可以修改 nb 指向的内存中存储的值。这种方法的几个关键点包括： 修改外部变量: 通过传递 long long 类型变量的地址（即指针），函数可以修改调用方提供的变量。这对于返回多个值或在函数内部修改状态非常有用。 避免复制大对象: 对于较大的数据类型（如结构体或大数组），通过指针传递可以避免复制整个对象，从而提高效率。尽管 long long 不是非常大的类型，但这种做法在处理大型数据结构时尤其有用。 返回多个结果: 在 C 中，函数只能有一个返回值。如果您想要函数返回多个结果，可以通过指针参数来实现。在 atoi2 的情况下，您可以返回一个布尔值来表示转换是否成功，同时通过指针参数返回转换得到的数字。 可选输出: 有时，函数可能有一个可选的输出参数。通过传递指针，调用者可以选择是否接收这个额外的输出。 例如，如果您只使用 long long 而不是指针，那么函数将无法修改调用方传递的变量，因为函数将获得该值的副本，而不是实际变量的引用。通过使用指针，您允许函数直接修改原始变量。

* 在 C 语言中，是否需要使用 free 来释放内存取决于内存是如何分配的。当您使用 malloc, calloc, 或 realloc 等函数动态分配内存时，您需要使用 free 来释放这块内存。然而，对于非动态分配的内存（例如，自动（局部）变量或通过参数传递的地址），则不应使用 free。

* valgrind --leak-check=full --show-leak-kinds=all ./push_swap "54545454545456456454564"

* another tester: https://github.com/SimonCROS/push_swap_tester  

* ARG=$(seq 1 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
