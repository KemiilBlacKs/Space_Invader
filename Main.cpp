/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Main.cpp                                                   #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Mouhammad <dahala_m@etna-alternance.net>               #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/01/19 20:36:29 by Mouhammad                    #          bachir_c          #   */
/*  updated: 07/29/19 11:39:25 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "Source/Game.hh"
#include "Utils/StateMainMenu.hh"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace {
    void setConsolePosition() {
#ifdef _WIN32
        HWND consoleWindow = GetConsoleWindow();
    SetWindowPos(consoleWindow, 0, 0, 0, 500, 500, SWP_NOSIZE | SWP_NOZORDER);
#endif
    }

    constexpr int GAMES = 1;

    template<typename T>
    void run() {
        Game app{};
        app.initGame<T>();
        app.run();
        std::cout << '\n';
    }

    bool isValidChoice(int option) { return option > 0 && option <= GAMES + 1; }
} // namespace

int main() {
    run<SpaceInvaders::StateMainMenu>();
}
