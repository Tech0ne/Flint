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
#include <fstream>

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

std::string readFile(std::string filename)
{
    std::stringstream file_buffer;
    std::ifstream newFile(filename);
    if (newFile.good()){
        file_buffer << newFile.rdbuf();
        newFile.close();
    }
    return file_buffer.str();
}

int main()
{
    try {
        Flint::Json::JsonObject json = Flint::Json::Loader::Load(readFile("file.json"));
        std::cout << json << std::endl;
    } catch (const Flint::Exceptions::Exception& e) {
        std::cerr << catch_exception(e) << std::endl;
    }
    Test obj;
    std::cout << obj << std::endl;

    throw_exception(Flint::Exceptions::NotImplementedError, "Should be caught by the handler");
}