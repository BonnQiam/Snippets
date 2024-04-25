假如说我们想判定两个类型是否相等，并以此来写一些逻辑，应该怎么做呢？在 Python 中，我们用 isinstance / [[isinstance]]  就可以了，但在 C++ 中，由于缺乏自省机制，所以普通的代码是不可能实现下面这种效果的：

```cpp
int i = 0;
std::cout << is_same_v<decltype(i), int>   << std::endl;    // 1
std::cout << is_same_v<decltype(i), float> << std::endl;    // 0

if (is_same_v<decltype(i), int>) {
    // ...
} else {
    // ...
}
```

这里你可能会想到 RTTI / [[RTTI 机制]]（Run-Time Type Information）的机制，但 RTTI 不同编译器的实现可能有差别，它的本意是为了实现 C++ 内部的一些语言机制，主要是动态多态（Dynamic Polymorphism），因此依赖 RTTI 的代码可能不具备可移植性。但是通过 TMP，我们可以实现一个 Metafunction 来达到判定类型的效果，原理非常简单（使用 [[C++ 模板元编程（TMP）#3 use public inheritance]]）：

```cpp
template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};
```

`is_same` 是一个类模板，它有两个模板形参，`T` 和 `U`，它的主模板继承了 `false_type` （参考 [[Non-type_Metadata#alias]] ），另外有一个特化继承了 `true_type` （参考 [[Non-type_Metadata#alias]]），这个特化模板匹配 `T` 和 `U` 相同的情况。这个过程和我们之前描述的一样，当 `T` 和 `U` 相同时，编译器将 `T` 和 `U` 代入模板特化的实参列表里，然后尝试推导特化模板的形参，因为两个参数相同，所以推导得出一致的结果，匹配特化成功，`is_same<T, U>::value == true`。当 `T` 和 `U` 不同时，推导失败，fallback 到匹配主模板，这时 `is_same<T, U>::value == false`。