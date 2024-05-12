/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, May, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     main                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Flint.hpp"

class SubClass: public Flint::Inspection<SubClass>
{
    private:
        double j = 5.6;
        std::size_t big_nbr = ((std::size_t)-1);

    public:
        SubClass() {}

        std::string str() const
        {
            return make_str(display_attr(j) << ", " << display_attr(big_nbr));
        }
};

class Test: public Flint::Inspection<Test>
{
    private:
        int n = 12;
        std::string s = "Hello world";
        SubClass obj;

    public:
        Test() {}

        std::string str() const
        {
            return make_str(display_attr(n) << ", " << display_attr(s) << ", " << display_attr(obj));
        }
};

int main()
{
    Test obj;
    std::cout << obj << std::endl;
}