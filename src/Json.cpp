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

#include "Json.hpp"

namespace Flint::Json
{
    std::string Loader::Escape(const std::string& str)
    {
        std::string output;
        for(unsigned i = 0; i < str.length(); ++i) {
            switch(str[i]) {
                case '\"':
                    output += "\\\"";
                    break;
                case '\\':
                    output += "\\\\";
                    break;
                case '\b':
                    output += "\\b";
                    break;
                case '\f':
                    output += "\\f";
                    break;
                case '\n':
                    output += "\\n";
                    break;
                case '\r':
                    output += "\\r";
                    break;
                case '\t':
                    output += "\\t";
                    break;
                default:
                    output += str[i];
                    break;
            }
        }
        return output;
    }

    JsonObject Loader::Load(const std::string& str)
    {
        size_t offset = 0;
        return parse_next(str, offset);
    }

    void Loader::remove_spaces(const std::string& str, size_t& offset)
    {
        while(isspace(str[offset])) offset++;
    }

    JsonObject Loader::parse_next(const std::string& str, std::size_t& offset)
    {
        char value;
        remove_spaces(str, offset);
        value = str[offset];
        switch (value) {
            case '[':
                return parse_list(str, offset);

            case '{':
                return parse_object(str, offset);

            case '\"':
                return parse_string(str, offset);

            case 't':
            case 'f':
                return parse_bool(str, offset);

            case 'n':
                return parse_null(str, offset);

            default:
                if ((value <= '9' && value >= '0') ||
                    value == '-')
                    return parse_number(str, offset);
        }
        throw_exception(Flint::Exceptions::JsonParsingError, std::string("Parsing: Unkown starting character '") + value + "'");
    }

    JsonObject Loader::parse_bool(const std::string &str, size_t &offset)
    {
        JsonObject Bool;
        if (str.substr(offset, 4) == "true")
            Bool = true;
        else if (str.substr(offset, 5) == "false")
            Bool = false;
        else {
            throw_exception(Flint::Exceptions::JsonParsingError, std::string("Bool: Expected 'true' or 'false', found '") + str.substr(offset, 5) + "'");
        }
        offset += (Bool.toBool() ? 4 : 5);
        return Bool;
    }

    JsonObject Loader::parse_number(const std::string& str, std::size_t& offset)
    {
        JsonObject Number;
        std::string val, exp_str;
        char c;
        bool isDouble = false;
        long exp = 0;
        for (;;) {
            c = str[offset++];
            if ((c == '-') ||
                (c >= '0' && c <= '9') )
                val += c;
            else if (c == '.') {
                val += c;
                isDouble = true;
            }
            else
                break;
        }
        if (c == 'E' || c == 'e') {
            c = str[offset++];
            if (c == '-') {
                offset++;
                exp_str += '-';
            }
            for (;;) {
                c = str[ offset++ ];
                if (c >= '0' && c <= '9')
                    exp_str += c;
                else if (!isspace(c) &&
                        c != ',' &&
                        c != ']' &&
                        c != '}') {
                    throw_exception(Flint::Exceptions::JsonParsingError, std::string("Number: Expected a number for exponent, found '") + c + "'");
                }
                else
                    break;
            }
            exp = std::stol(exp_str);
        }
        else if (!isspace(c) &&
                c != ',' &&
                c != ']' &&
                c != '}') {
            throw_exception(Flint::Exceptions::JsonParsingError, std::string("Number: Unexpected characted '") + c + "'");
        }
        offset--;

        if (isDouble)
            Number = std::stod(val) * std::pow(10, exp);
        else {
            if (!exp_str.empty())
                Number = std::stol(val) * std::pow(10, exp);
            else
                Number = std::stol(val);
        }
        return Number;
    }

    JsonObject Loader::parse_list(const std::string& str, std::size_t& offset)
    {
        JsonObject List = JsonObject::Make(JsonType::LIST);

        unsigned index = 0;

        offset++;
        remove_spaces(str, offset);
        if (str[offset] == ']') {
            offset++;
            return List;
        }

        for (;;) {
            List[index++] = parse_next(str, offset);
            remove_spaces(str, offset);

            if (str[offset] == ',') {
                offset++; continue;
            }
            else if (str[offset] == ']') {
                offset++; break;
            }
            else {
                throw_exception(Flint::Exceptions::JsonParsingError, std::string("List: Excpected ',' or ']', found '") + str[offset] + "'");
            }
        }

        return List;
    }

    JsonObject Loader::parse_null(const std::string &str, size_t &offset)
    {
        JsonObject Null;
        if (str.substr(offset, 4) != "null") {
            throw_exception(Flint::Exceptions::JsonParsingError, std::string("None: Expected 'null', found '") + str.substr(offset, 4) + "'");
        }
        offset += 4;
        return Null;
    }

    JsonObject Loader::parse_object(const std::string& str, size_t& offset)
    {
        JsonObject Object = JsonObject::Make(JsonType::OBJECT);

        JsonObject Key;
        JsonObject Value;

        offset++;
        remove_spaces(str, offset);
        if (str[offset] == '}') {
            offset++;
            return Object;
        }

        for (;;) {
            Key = parse_next(str, offset);
            remove_spaces(str, offset);
            if (str[offset] != ':')
                throw_exception(Flint::Exceptions::JsonParsingError, std::string("Object: Expected ':', found '") + str[offset] + "'");
            offset++;
            remove_spaces(str, offset);

            Value = parse_next(str, offset);

            Object[Key.toString()] = Value;

            remove_spaces(str, offset);
            if (str[offset] == ',') {
                offset++; continue;
            }
            else if (str[offset] == '}') {
                offset++; break;
            }
            else {
                throw_exception(Flint::Exceptions::JsonParsingError, std::string("Object: Expected ',' or '}', found '") + str[offset] + "'");
            }
        }

        return Object;
    }

    JsonObject Loader::parse_string(const  std::string& str, std::size_t& offset)
    {
        JsonObject String;
        std::string val;
        for (char c = str[++offset]; c != '\"'; c = str[++offset]) {
            if (c == '\\') {
                switch(str[ ++offset ]) {
                    case '\"':
                        val += '\"'; break;
                    case '\\':
                        val += '\\'; break;
                    case '/':
                        val += '/' ; break;
                    case 'b':
                        val += '\b'; break;
                    case 'f':
                        val += '\f'; break;
                    case 'n':
                        val += '\n'; break;
                    case 'r':
                        val += '\r'; break;
                    case 't':
                        val += '\t'; break;
                    case 'u':
                    {
                        val += "\\u" ;
                        for(unsigned i = 1; i <= 4; i++) {
                            c = str[offset + i];
                            if ((c >= '0' && c <= '9') ||
                                (c >= 'a' && c <= 'f') ||
                                (c >= 'A' && c <= 'F'))
                                val += c;
                            else {
                                throw_exception(Flint::Exceptions::JsonParsingError, std::string("String: Expected hex characted in unicode escape, found '") + c + "'");
                            }
                        }
                        offset += 4;
                    }
                        break;

                    default:
                        val += '\\';
                        break;
                }
            }
            else
                val += c;
        }
        offset++;
        String = val;
        return String;
    }

    JsonObject Build::List()
    {
        return JsonObject::Make(JsonType::LIST);
    }

    JsonObject Build::Object()
    {
        return JsonObject::Make(JsonType::OBJECT);
    }

    JsonObject::~JsonObject()
    {
        this->clear();
    }

    JsonObject::JsonObject()
    {}

    JsonObject::JsonObject(std::initializer_list<JsonObject> list)
    {
        this->_type = JsonType::LIST;
        for( auto i = list.begin(), e = list.end(); i != e; ++i, ++i )
            operator[](i->ToString()) = *std::next(i);
        // this->_value._list = std::vector<JsonObject>(list);
    }

    JsonObject::JsonObject(std::map<std::string, JsonObject> object)
    {
        this->_type = JsonType::OBJECT;
        this->_value._object = object;
    }

    JsonObject::JsonObject(const JsonObject& other):
        _type(other._type)
    {
        switch (this->_type) {
            case JsonType::BOOL:
                this->_value._bool = other._value._bool;
                break;

            case JsonType::DOUBLE:
                this->_value._double = other._value._double;
                break;

            case JsonType::LIST:
                this->_value._list = other._value._list;
                break;

            case JsonType::LONG:
                this->_value._long = other._value._long;
                break;

            case JsonType::NONE:
                this->_value._none = other._value._none;
                break;

            case JsonType::OBJECT:
                this->_value._object = std::map<std::string, JsonObject>(other._value._object);
                break;

            case JsonType::STRING:
                this->_value._string = other._value._string;
                break;

            default:
                break;
        }
    }

    JsonObject& JsonObject::operator=(const JsonObject& other)
    {
        this->clear();
        this->_type = other._type;
        switch (this->_type) {
            case JsonType::BOOL:
                this->_value._bool = other._value._bool;
                break;

            case JsonType::DOUBLE:
                this->_value._double = other._value._double;
                break;

            case JsonType::LIST:
                this->_value._list = other._value._list;
                break;

            case JsonType::LONG:
                this->_value._long = other._value._long;
                break;

            case JsonType::NONE:
                this->_value._none = other._value._none;
                break;

            case JsonType::OBJECT:
                this->_value._object = other._value._object;
                break;

            case JsonType::STRING:
                this->_value._string = other._value._string;
                break;

            default:
                break;
        }
        return *this;
    }

    JsonObject::JsonObject(std::nullptr_t):
        _value(),
        _type(JsonType::NONE)
    {}

    JsonObject JsonObject::Make(JsonType type)
    {
        switch (type) {
            case JsonType::BOOL:
                return JsonObject(false);

            case JsonType::DOUBLE:
                return JsonObject(0.0);

            case JsonType::LIST:
                return JsonObject({});

            case JsonType::LONG:
                return JsonObject(0);

            case JsonType::NONE:
                return JsonObject();

            case JsonType::OBJECT:
                return JsonObject(std::map<std::string, JsonObject>({}));

            case JsonType::STRING:
                return JsonObject("");

            default:
                return JsonObject();
        }
    }

    JsonObject& JsonObject::operator[](const std::string &key)
    {
        if (this->_type != JsonType::OBJECT)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "operator[] with std::string key require JsonType::OBJECT, but got JsonType::" + this->getTypeStr());
        return this->_value._object.operator[](key);
    }

    JsonObject& JsonObject::operator[](long index)
    {
        if (this->_type != JsonType::LIST)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "operator[] with long key require JsonType::LISt, but got JsonType::" + this->getTypeStr());

        while (index < 0)
            index += (long)this->_value._list.size();
        if (index >= (long)this->_value._list.size())
            this->_value._list.resize(index + 1);
        return this->_value._list.operator[](index);
    }

    void JsonObject::clear()
    {
        this->_type = JsonType::NONE;
    }

    JsonObject& JsonObject::at(const std::string& key)
    {
        return this->operator[](key);
    }

    const JsonObject& JsonObject::at(const std::string& key) const
    {
        return this->_value._object.at(key);
    }

    JsonObject& JsonObject::at(long index)
    {
        return operator[](index);
    }

    const JsonObject& JsonObject::at(long index) const
    {
        return this->_value._list.at(index);
    }

    int JsonObject::length() const
    {
        if (this->_type != JsonType::LIST)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "length() method require JsonType::LIST, but got JsonType::" + this->getTypeStr());
        return this->_value._list.size();
    }

    bool JsonObject::hasKey(const std::string& key) const
    {
        if (this->_type != JsonType::OBJECT)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "hasKey() method require JsonType::OBJECT, but got JsonType::" + this->getTypeStr());
        return this->_value._object.find(key) != this->_value._object.end();
    }

    int JsonObject::size() const
    {
        if (this->_type != JsonType::OBJECT &&
            this->_type != JsonType::LIST)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "size() method require JsonType::OBJECT or JsonType::LIST, but got JsonType::" + this->getTypeStr());
        if (this->_type == JsonType::OBJECT)
            return this->_value._object.size();
        return this->_value._list.size();
    }

    JsonType JsonObject::getType() const
    {
        return this->_type;
    }

    std::string JsonObject::getTypeStr() const
    {
        switch (this->_type) {
            case JsonType::BOOL:
                return "BOOL";
            case JsonType::DOUBLE:
                return "DOUBLE";
            case JsonType::LIST:
                return "LIST";
            case JsonType::LONG:
                return "LONG";
            case JsonType::NONE:
                return "NONE";
            case JsonType::OBJECT:
                return "OBJECT";
            case JsonType::STRING:
                return "STRING";
            default:
                break;
        }
        return "[UNDEFINED]";
    }

    bool JsonObject::isNull() const
    {
        return this->_type == JsonType::NONE;
    }

    std::string JsonObject::toString() const
    {
        if (this->_type != JsonType::STRING)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "toString() method require JsonType::STRING, but got JsonType::" + this->getTypeStr());
        bool b;
        return this->toString(b);
    }

    std::string JsonObject::toString(bool& ok) const
    {
        ok = (this->_type == JsonType::STRING);
        if (ok)
            return Loader::Escape(this->_value._string);
        return "";
    }

    double JsonObject::toDouble() const
    {
        if (this->_type != JsonType::DOUBLE)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "toDouble() method require JsonType::DOUBLE, but got JsonType::" + this->getTypeStr());
        bool b;
        return this->toDouble(b);
    }

    double JsonObject::toDouble(bool& ok) const
    {
        ok = (this->_type == JsonType::DOUBLE);
        if (ok)
            return this->_value._double;
        return 0.0;
    }

    long JsonObject::toLong() const
    {
        if (this->_type != JsonType::LONG)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "toLong() method require JsonType::LONG, but got JsonType::" + this->getTypeStr());
        bool b;
        return this->toLong(b);
    }

    long JsonObject::toLong(bool& ok) const
    {
        ok = (this->_type == JsonType::LONG);
        if (ok)
            return this->_value._long;
        return 0;
    }

    bool JsonObject::toBool() const
    {
        if (this->_type != JsonType::BOOL)
            throw_exception(Flint::Exceptions::InvalidJsonTypeError, "toBool() method require JsonType::BOOl, but got JsonType::" + this->getTypeStr());
        bool b;
        return this->toBool(b);
    }

    bool JsonObject::toBool(bool& ok) const
    {
        ok = (this->_type == JsonType::BOOL);
        if (ok)
            return this->_value._bool;
        return false;
    }

    std::string JsonObject::dump(int depth, std::string tab, bool colorize) const
    {
        std::string pad = "";
        for(int i = 0; i < depth; i++, pad += tab);

        switch(this->_type) {
            case JsonType::NONE:
                return (colorize ? Flint::Colors::F_BLUE : "") +
                        "null" +
                    (colorize ? Flint::Colors::RESET : "");

            case JsonType::OBJECT:
            {
                std::string s = (colorize ? Flint::Colors::F_YELLOW : "") +
                                "{\n" +
                                (colorize ? Flint::Colors::RESET : "");
                bool skip = true;
                for (auto& p : this->_value._object) {
                    if (!skip)
                        s += (colorize ? Flint::Colors::F_CYAN : "") +
                            ",\n" +
                            (colorize ? Flint::Colors::RESET : "");
                    s += (pad +
                        (colorize ? Flint::Colors::F_CYAN : "") +
                        "\"" +
                        (colorize ? Flint::Colors::GREEN : "") +
                        p.first +
                        (colorize ? Flint::Colors::CYAN : "") +
                        "\": " +
                        (colorize ? Flint::Colors::RESET : "") +
                        p.second.dump(depth + 1, tab, colorize));
                    skip = false;
                }
                s += ("\n" +
                    pad.erase(0, tab.size()) +
                    (colorize ? Flint::Colors::F_YELLOW : "") +
                    "}" +
                    (colorize ? Flint::Colors::RESET : ""));
                return s;
            }

            case JsonType::LIST:
            {
                std::string s = (colorize ? Flint::Colors::F_PURPLE : "") +
                                "[" +
                                (colorize ? Flint::Colors::RESET : "");
                bool skip = true;
                for (auto& p : this->_value._list) {
                    if (!skip)
                        s += (colorize ? Flint::Colors::F_CYAN : "") +
                            ", " +
                            (colorize ? Flint::Colors::RESET : "");
                    s += p.dump(depth + 1, tab, colorize);
                    skip = false;
                }
                s += (colorize ? Flint::Colors::F_PURPLE : "") +
                    "]" +
                    (colorize ? Flint::Colors::RESET : "");
                return s;
            }

            case JsonType::STRING:
                return (colorize ? Flint::Colors::F_CYAN : "") +
                        "\"" +
                    (colorize ? Flint::Colors::RESET : "") +
                        Loader::Escape(this->_value._string) +
                    (colorize ? Flint::Colors::F_CYAN : "") +
                        "\"" +
                    (colorize ? Flint::Colors::RESET : "");

            case JsonType::DOUBLE:
                return (colorize ? Flint::Colors::F_BLUE : "") +
                        std::to_string(this->_value._double) +
                    (colorize ? Flint::Colors::RESET : "");

            case JsonType::LONG:
                return (colorize ? Flint::Colors::F_BLUE : "") +
                        std::to_string(this->_value._long) +
                    (colorize ? Flint::Colors::RESET : "");

            case JsonType::BOOL:
                return (colorize ? Flint::Colors::F_BLUE : "") +
                        (this->_value._bool ? "true" : "false") +
                    (colorize ? Flint::Colors::RESET : "");

            default:
                return "";
        }
        return "";
    }

    std::ostream& operator<<(std::ostream &os, const JsonObject &json)
    {
        os << json.dump(1, "    ", true);
        return os;
    }
}