
> 下面的这个模板可以判定一个类型是不是引用 / [[引用]] 类型，同样在编译期间生成常量，参考 [[is_reference.cpp]] / [[is_reference_v2.cpp]]

```cpp
template <typename T> struct is_reference      { static constexpr bool value = false; };    // #1
template <typename T> struct is_reference<T&>  { static constexpr bool value = true; };     // #2
template <typename T> struct is_reference<T&&> { static constexpr bool value = true; };     // #3

std::cout << is_reference<int>::value << std::endl;    // 0
std::cout << is_reference<int&>::value << std::endl;   // 1
std::cout << is_reference<int&&>::value << std::endl;  // 1
```

`is_reference` 包含一个主模板和两个偏特化，它接受一个类型 `T` 作为参数
- 当 `T` 传入一个右值引用类型时，编译器会选择 `#3` 这个模板特化来进行实例化；
- 当 `T` 传入一个左值引用类型时，编译器会选择 `#2` 这个模板特化来进行实例化；
- 当 `T` 不是引用类型时，`#2` 和 `#3` 都不匹配，编译器选择主模板 `#1` 来进行实例化

想要理解编译器是怎么做出这种决定的，我们假想这样一个过程（为了方便描述，我们记 `#1` 的形参为 `T1`，`#2` 的形参为 `T2`，`#3` 的形参为 `T3`）：
- 对于 `is_reference<int>` 这个实例化，编译器首先确定了模板的实参为 `int`，于是它尝试将 `int` “代入” 模板的特化中看是否匹配，并且要反向推导该特化的形参，看能否推导成功。
- 将 `int` 代入 `#2`，是匹配的，`T2&` 匹配 `int`，但反向推导 T2 失败，因为没有任何一个类型加上引用符号后能和 `int` 相等，所以编译器不选择 `#2`。
- 同理，代入 `#3`，`T3&&` 匹配 int，反向推导失败，编译器也不能选择 `#3`。于是编译器只能选择主模板 `#1`。

对于 `is_reference<int&>` 这个实例化，编译器首先确定了模板的实参为 `int&`，将 `int&` “代入” 模板的特化中并反向推导。代入 `#2`，`T2&` 匹配 `int&`，但反向推导 `T2 = int`，成功；代入 `#3`，`T3&&` 匹配 `int&`，反向推导 `T3` 失败（引用叠加规则在此处不适用）；于是选择 `#2`。