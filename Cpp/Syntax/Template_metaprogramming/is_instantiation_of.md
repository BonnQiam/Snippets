这个例子展示模板模板形参（Template Template Parameters）。is_instantiation_of 接受两个参数，一个类型，一个模板，它可以判定这个类型是不是这个模板的实例类型。

```cpp
std::list<int>     li;
std::vector<int>   vi;
std::vector<float> vf;

std::cout << is_instantiation_of_v<decltype(vi), std::vector> << std::endl;  // 1
std::cout << is_instantiation_of_v<decltype(vf), std::vector> << std::endl;  // 1
std::cout << is_instantiation_of_v<decltype(li), std::vector> << std::endl;  // 0
std::cout << is_instantiation_of_v<decltype(li), std::list>   << std::endl;  // 1

// is_instantiation_of
template <typename Inst, template <typename...> typename Tmpl>
struct is_instantiation_of : false_type {};

template <template <typename...> typename Tmpl, typename... Args>
struct is_instantiation_of<Tmpl<Args...>, Tmpl> : true_type {};
```

is_instantiation_of 也有一个主模板和一个偏特化，主模板继承 false_type，它匹配当这个类型不是模板的实例时的情况；特化模板继承自 true_type，它匹配当传入的类型是对应模板的实例时的情况。这个过程也是和上面一样的，确定实参 -> 代入特化 -> 反向推导，大家可以自行尝试推演一下，我就不赘述了。