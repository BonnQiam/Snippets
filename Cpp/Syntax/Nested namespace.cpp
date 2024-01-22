#include <stdlib.h>

#include <iostream>

namespace detail // 定义一个namespace
{
const int i=99;
}

namespace ant // namespace 嵌套
{
    namespace blas
    {
        const int i=0;
    }//end blas

    const int i=3;

    namespace detail
    {
    const int i=33;
    void test()
    {
        std::cout<<"i:"<<i<<std::endl;  // 33
        std::cout<<"::detail::i"<<::detail::i<<std::endl; // 99
        std::cout<<"detail::i"<<detail::i<<std::endl; // 33
        std::cout<<"::ant::blas::i:"<<::ant::blas::i<<std::endl;// 0 ::ant 表根命名空间
        std::cout<<"ant::blas::i"<<::ant::blas::i<<std::endl;   // 0
        std::cout<<"blas::i"<<blas::i<<std::endl;   // 0 平级
        //std::cout<<"::blas::i"<<::blas::i<<std::endl;   // error
        std::cout<<"ant::i"<<ant::i<<std::endl;// 3
    }
    }// end detail

}//end namespace ant

using namespace std;
int main()
{
    ant::detail::test(); // 引用test（） 需要：： 限定符
    return 0;
}