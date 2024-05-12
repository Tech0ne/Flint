/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Apr, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     Exceptions                                                                       *
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

#ifndef INCLUDED_EXCEPTIONS_HPP
    #define INCLUDED_EXCEPTIONS_HPP

    #include "Headers.hpp"
    #include "CxxABI.hpp"
    #include "Colors.hpp"
    #include "Inspection.hpp"
    #include "Preprocessor.hpp"

namespace Flint::Exceptions
{
    class Exception: public std::exception
    {
        protected:
            std::string _what;
            std::pair<std::pair<std::string, std::size_t>, std::string> _infos;
        public:
            Exception(std::string what = "An exception occured !",
                      std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""});

            std::pair<std::pair<std::string, std::size_t>, std::string> getInfos() const;
            std::string getClassNameFromStackTrace(const std::vector<std::pair<std::string, std::size_t>>& stackTrace) const;
            std::string show(std::pair<std::pair<std::string, std::size_t>, std::string> infos) const;
            const char* what() const noexcept override;
            friend std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj);
    };

    class InvalidJsonTypeError: public Flint::Exceptions::Exception
    {
        public:
            InvalidJsonTypeError(std::string what = "Invalid Json type.",
                                 std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class InvalidIndexError: public Flint::Exceptions::Exception
    {
        public:
            InvalidIndexError(std::string what = "Index is not valid.",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class JsonParsingError: public Flint::Exceptions::Exception
    {
        public:
            JsonParsingError(std::string what = "Error while parsing Json string.",
                             std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class NotImplementedError: public Flint::Exceptions::Exception
    {
        public:
            NotImplementedError(std::string what = "Asked action haven't been implemented yet.",
                                std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };
}

#endif
