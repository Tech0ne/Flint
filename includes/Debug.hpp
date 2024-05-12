/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, May, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     Debug                                                                            *
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

#ifndef INCLUDED_DEBUG_HPP
    #define INCLUDED_DEBUG_HPP

    #include "Preprocessor.hpp"
    #include "Headers.hpp"

namespace Flint
{
    class Debug
    {
        public:
            Debug();
            Debug(std::string data);

            template <typename T>
            Debug(std::string filename, std::size_t line, T functionName);

            ~Debug() = default;
    };
}

#define Debug(data) Flint::Debug(__POSITION_INFOS__, data)

#endif
