#元数据

# Metafunction

> `is_reference` / [[is_reference]] 的返回值名为 “value”，`remove_reference` / [[remove_reference]] 的返回值名为 “type”，为了形式化上的一致性，Metafunction Convention 规定，*所有的 Metafunction 都以 “type” 作为唯一的返回值，对于原本已 “value” 指代的那些常量，使用一个类模板将它们封装起来，Metafunction 返回这个类模板的相应实例*。

我们举例说明：

```cpp
// non-type metadata (or numerical metadata)
template <bool b>
struct bool_ { static constexpr bool value = b; };

// metafunction
template <typename T> struct is_reference      { using type = bool_<false>; };
template <typename T> struct is_reference<T&>  { using type = bool_<true>; };
template <typename T> struct is_reference<T&&> { using type = bool_<true>; };
```

我们定义了一个名为 `bool_` 的类模板，以封装 `bool` 类型的常量，`is_reference` 的返回值就变成了 `bool_` 和 `bool`。在调用 `is_reference` 时，也是使用 “`type`” 这个名字，如果想访问结果中的布尔值，使用 `is_reference<T>::type::value` 即可。

> 注意，Metafunction Convention 的这种规定，并不是 C++ 语言上的要求，而是编程指导上的要求，目的是规范元编程的代码，使其更具可读性和兼容性。标准库、boost / [[boost]]、github 上热门的 TMP 库都遵循了这一约定，你也应该遵守。

> 另外，我们在定义类模板时，使用 `struct` 关键字，而不使用 `class` 关键字，这样就可以省略继承时的 `public` 关键字，以及类模板定义内部的 `public` 关键字了 —— [[C++ 模板元编程（TMP）#3 use public inheritance]]

^4c1777
