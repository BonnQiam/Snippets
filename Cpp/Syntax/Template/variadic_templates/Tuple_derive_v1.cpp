#include <iostream>

using namespace std;

// 当前这个例子为递归继承
namespace light {
    // tuple can accept any number of template arguments
    template<typename...Values>
    class tuple;

    // specialization for empty tuple, as terminal condition
    template<>
    class tuple<> {
    };

    // specialization for tuple with at least one element
    template<typename Head, typename...Tail>
    class tuple<Head, Tail...> : private tuple<Tail...> {
        typedef tuple<Tail...> inherited;
    protected:
        Head m_head;
    public:
        tuple() {}

        // constructor: head is passed to m_head, tail is passed to inherited, i.e. Base class constructor
        tuple(Head h, Tail...tail) : m_head(h), inherited(tail...) {}

        // decltype()中的 m_head 必须放到前面,否则编译器找不到
        auto head() -> decltype(m_head) { return m_head; }
        // 或者 Head head()  { return m_head; }

        inherited &tail() { return *this; } // return the reference of the base class
    };
}
/**
 * string 32   8字节对齐
 * float  4
 * int    4
 * 4+4+32=40 自底向上
 */

int main() {
    using light::tuple;
    tuple<int, float, string> t(41, 6.3, "nico");
    cout << sizeof(t) << endl;
    cout << t.head() << endl;
    cout << t.tail().head() << endl;
    cout << t.tail().tail().head() << endl;

    return 0;
}
