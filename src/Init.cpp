/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, May, 2024                                                     *
 * Title           - Flint                                                              *
 * Description     -                                                                    *
 *     Init                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Init.hpp"

void unhandeled_exception()
{
    try {
        std::rethrow_exception(std::current_exception());
    } catch (const std::exception& e) {
        const Flint::Exceptions::Exception* exception = dynamic_cast<const Flint::Exceptions::Exception*>(&e);
        if (exception != nullptr) {
            std::cerr << Flint::Colors::RED << "/!\\ Uncaught Flint exception /!\\" << std::endl << std::endl << exception << std::endl;
        } else {
            std::cerr << Flint::Colors::RED << "/!\\ Uncaught exception /!\\" << std::endl << std::endl << e.what() << std::endl;
        }
    }
}

void Flint::Init()
{

}