
> 除了判定一个引用类型外，我们还可以移除一个类型的引用 / [[引用]] —— 参考 [[remove_reference.cpp]] / [[remove_reference_v2.cpp]]

```cpp
template <typename T> struct remove_reference      { using type = T; };     // #1
template <typename T> struct remove_reference<T&>  { using type = T; };     // #2
template <typename T> struct remove_reference<T&&> { using type = T; };     // #3

// case 1:
int&& i = 0;
remove_reference<decltype(i)>::type j = i;    // equivalent to: int j = i;

// case 2:
template <typename T>
void foo(typename remove_reference<T>::type a_copy) { a_copy += 1; }

foo<int>(i);    // passed by value
foo<int&&>(i);  // passed by value
```

> 与 [[is_reference]] 同样的一个主模板和两个偏特化，同样的匹配规则。

- 例如，对于 `remove_reference<int&&>`，会匹配 `#3`，`#3` 中的 `T` 被推导为 `int`，于是 `remove_reference<int&&>::type` 就是 `int`。这里你可能会有疑问，移除引用的语义是什么？一个变量被移除了引用之后是变成了一份拷贝了吗？—— *这里我们再次强调，TMP 工作在编译期，在编译期没有变量，只有常量和类型，这里的移除引用就是把一个引用类型变成对应的非引用类型* ^d627ba
- 另一个问题是，“case 2” 中为什么 `remove_reference` 的前面要加一个 “`typename`” 关键字？这是因为 `remove_reference<T>::type` 是一个[待决名（Dependent Name）](https://link.zhihu.com/?target=https%3A//en.cppreference.com/w/cpp/language/dependent_name)，编译器在语法分析的时候还不知道这个名字到底代表什么。对于普通的名字，编译器直接通过名字查找就能知道这个名字的词性。但对于待决名，因为它是什么取决于模板的实参 `T`，所以直到编译器在语义分析阶段对模板进行了实例化之后，它才能对 “type” 进行名字查找，知道它到底是什么东西，所以名字查找是分[两个阶段](https://link.zhihu.com/?target=https%3A//en.cppreference.com/w/cpp/language/two-phase_lookup)的，待决名直到第二个阶段才能被查找。但是在语法分析阶段，编译器就需要判定这个语句是否合法，所以需要我们显式地告诉编译器 “`type`” 是什么。在 `remove_reference<T>::type` 这个语法中，`type` 有三种可能，一是静态成员变量或函数，二是一个类型，三是一个成员模板。编译器要求对于类型要用 `typename` 关键字修饰，对于模板要用 `template` 关键字修饰，以便其完成语法分析的工作。