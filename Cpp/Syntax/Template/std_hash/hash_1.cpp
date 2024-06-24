#include <iostream>
#include <string>
#include <unordered_set>

struct Name {
    std::string first_name;
    std::string last_name;
};

bool operator==(const Name& lhs, const Name& rhs) {
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

namespace std
{
    template<> struct hash<Name>
    {
        typedef Name        argument_type;
        typedef std::size_t result_type;

        result_type operator()(argument_type const& s) const
        {
            result_type const h1 ( std::hash<std::string>{}(s.first_name) );
            result_type const h2 ( std::hash<std::string>{}(s.last_name) );
            return h1 ^ (h2 << 1);
        }
    };
}

int main() {
    std::cout << "Test int hash" << std::endl;

    std::unordered_set<int> int_set;
    int_set.insert(1);
    int_set.insert(2);
    int_set.insert(3);
    int_set.insert(1);
    for (const auto& i : int_set) {
        //std::cout << i << std::endl;
        std::cout << std::hash<int>{}(i) << std::endl;
    }

    std::cout << "Test Name (self defined) hash" << std::endl;

    std::unordered_set<Name> names;
    names.insert(Name{"John", "Doe"});
    names.insert(Name{"Mary", "Sue"});
    names.insert(Name{"John", "Doe"});
    for (const auto& name : names) {
        //std::cout << name.first_name << " " << name.last_name << std::endl;
        std::cout << std::hash<Name>{}(name) << std::endl;
    }

    return 0;
}