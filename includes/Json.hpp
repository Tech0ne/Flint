/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, May, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     Json                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_JsonObject_HPP
    #define INCLUDED_JsonObject_HPP

    #include "Headers.hpp"
    #include "Colors.hpp"
    #include "Exceptions.hpp"
    #include "Preprocessor.hpp"

namespace Flint
{
    namespace Json
    {
        class JsonObject;

        class Loader
        {
            public:
                static std::string Escape(const std::string& str);
                static JsonObject Load(const std::string& str);

            private:
                static void remove_spaces(const std::string& str, size_t& offset);
                static JsonObject parse_next(const std::string& str, std::size_t& size);
                static JsonObject parse_bool(const std::string &str, size_t &offset);
                static JsonObject parse_number(const std::string& str, std::size_t& offset);
                static JsonObject parse_list(const std::string& str, std::size_t& offset);
                static JsonObject parse_null(const std::string &str, size_t &offset);
                static JsonObject parse_object(const std::string& str, size_t& offset);
                static JsonObject parse_string(const std::string& str, std::size_t& offset);
        };

        class Build
        {
            public:
                static JsonObject List();
                static JsonObject Object();
        };

        typedef union JsonValue {
            ~JsonValue() noexcept {};

            JsonValue(bool b):
                _bool(b)
            {}
            JsonValue(double d):
                _double(d)
            {}
            JsonValue(long l):
                _long(l)
            {}
            JsonValue(std::string s):
                _string(new std::string(s))
            {}

            JsonValue()
            {}

            bool                                _bool;
            double                              _double;
            std::vector<JsonObject>*            _list;
            long                                _long;
            nullptr_t                           _none;
            std::map<std::string, JsonObject>*  _object;
            std::string*                        _string;
        } JsonValue;

        typedef enum {
            BOOL,
            DOUBLE,
            LIST,
            LONG,
            NONE,
            OBJECT,
            STRING,
        } JsonType;

        class JsonObject
        {
            private:
                JsonValue _value;
                JsonType _type = JsonType::NONE;

                void setType(JsonType type);

            public:
                ~JsonObject();

                JsonObject();
                JsonObject(std::initializer_list<JsonObject> list);
                JsonObject(std::map<std::string, JsonObject> object);
                JsonObject(const JsonObject& other);
                JsonObject(std::nullptr_t);

                JsonObject& operator=(const JsonObject& other);

                static JsonObject Make(JsonType type);

                JsonObject& operator[](const std::string &key);
                JsonObject& operator[](long index);

                void clear();

                JsonObject& at(const std::string& key);
                const JsonObject& at(const std::string& key) const;
                JsonObject& at(long index);
                const JsonObject& at(long index) const;

                int length() const;
                int size() const;

                bool hasKey(const std::string& key) const;

                JsonType getType() const;
                std::string getTypeStr() const;

                bool isNull() const;

                std::string toString() const;
                std::string toString(bool& ok) const;

                double toDouble() const;
                double toDouble(bool& ok) const;

                long toLong() const;
                long toLong(bool& ok) const;

                bool toBool() const;
                bool toBool(bool& ok) const;

                std::string dump(int depth = 1, std::string tab = "    ", bool colorize = false) const;

                friend std::ostream& operator<<(std::ostream& os, const JsonObject& obj);

                template <typename T>
                void append(T arg)
                {
                    if (this->_type == JsonType::LIST) {
                        this->_value._list.push_back(arg);
                        return;
                    }
                    this->clear();
                    this->_type = JsonType::LIST;
                    this->_value._list.clear();
                    this->_value._list.push_back(arg);
                }

                template <typename T, typename... U>
                void append(T arg, U... args) {
                    this->append(arg);
                    this->append(args...);
                }

                template <typename T>
                typename std::enable_if<std::is_same<T, bool>::value, JsonObject&>::type operator=(T b)
                {
                    this->clear();
                    this->_type = JsonType::BOOL;
                    this->_value._bool = b;
                    return *this;
                }

                template <typename T>
                typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value, JsonObject&>::type operator=(T i)
                {
                    this->clear();
                    this->_type = JsonType::LONG;
                    this->_value._long = i;
                    return *this;
                }

                template <typename T>
                typename std::enable_if<std::is_floating_point<T>::value, JsonObject&>::type operator=(T f)
                {
                    this->clear();
                    this->_type = JsonType::DOUBLE;
                    this->_value._double = f;
                    return *this;
                }

                template <typename T>
                typename std::enable_if<std::is_convertible<T, std::string>::value, JsonObject&>::type operator=(T s)
                {
                    this->clear();
                    this->_type = JsonType::STRING;
                    this->_value._string = s;
                    return *this;
                }

                template <typename T>
                JsonObject(T b, typename std::enable_if<std::is_same<T, bool>::value>::type* = 0 ):
                    _value(b),
                    _type(JsonType::BOOL)
                {}

                template <typename T>
                JsonObject(T i, typename std::enable_if<std::is_integral<T>::value && !std::is_same<T, bool>::value>::type* = 0):
                    _value((long)i),
                    _type(JsonType::LONG)
                {}

                template <typename T>
                JsonObject(T f, typename std::enable_if<std::is_floating_point<T>::value>::type* = 0):
                    _value((double)f),
                    _type(JsonType::DOUBLE)
                {}

                template <typename T>
                JsonObject(T s, typename std::enable_if<std::is_convertible<T, std::string>::value>::type* = 0):
                    _value(std::string(s)),
                    _type(JsonType::STRING)
                {}
        };
    }
}

#endif
