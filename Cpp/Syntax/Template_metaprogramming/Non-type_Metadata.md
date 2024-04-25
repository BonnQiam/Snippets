#Snippet 

# Non-type_Metadata

在真实世界的场景中，一个典型的 Non-type Metadata / [[Non-type_Metadata]] 是这样定义的：

```cpp
template <typename T, T v>
struct integral_constant {
  static constexpr T value = v;
  using value_type = T;
  using type = integral_constant;   // using injected-class-name
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};
```

这是我们在 TMP 中最常用的一个 Non-type Metadata，它除了像 `bool_`（参考 [[Metafunction]]） 那样定义了一个 `value` 外，还定义了：
*  `value_type` 指代数据的类型
*   `type` 指代自身，即 `integral_constant`，这个成员使得 `integral_constant` 变成了一个返回自己的 Metafunction / [[Metafunction]]
*   `operator value_type ()` 是到 `value_type` 的隐式类型转换，返回 `value` 的值
*   `value_type operator ()` 是函数调用运算符重载，返回 `value` 的值

## alias

这些成员，特别是 `type`，都会使 TMP 变得更方便，后面会看到例子。通常我们在使用时还会定义一些 `alias`：

```cpp
// alias
template <bool B> using bool_constant = integral_constant<bool, B>;
using true_type  = bool_constant<true>;
using false_type = bool_constant<false>;
```

有了这些定义，`is_reference` / [[is_reference_v2.cpp]] 的定义就变成了：

```cpp
template <typename T> struct is_reference      { using type = false_type; };
template <typename T> struct is_reference<T&>  { using type = true_type; };
template <typename T> struct is_reference<T&&> { using type = true_type; };
```

对它的调用就变成了：

```cpp
std::cout << is_reference<int>::type::value;  // 0
std::cout << is_reference<int>::type();       // 0, implicit cast: false_type --> bool
std::cout << is_reference<int>::type()();     // 0
```