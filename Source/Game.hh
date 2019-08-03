//
// Created by Mouhammad DAHALANI on 2019-07-01.
//

#ifndef SPACE_INVADERS_GAME_HH
#define SPACE_INVADERS_GAME_HH

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <memory>
#include <vector>
#include <iostream>

#include "../Utils/StateBase.hh"
#include "../Utils/FpsCounter.hh"


class Game {
public:
    Game();

    void run();

    template<typename T>
    void initGame();

    void popState();

    void exitGame();


    const sf::RenderWindow &getWindow() const;

    void resizeWindow(unsigned width, unsigned height);

    void pushState(std::unique_ptr<StateBase> state);

    template<typename T, typename... Args>
    void pushState(Args &&... args);

    template<typename T, typename... Args>
    void changeState(Args &&... args);

private:
    sf::RenderWindow m_window;
    std::vector<std::unique_ptr<StateBase>> m_states;

    void handleEvent();

    void tryPop();

    FpsCounter counter;

    StateBase &getCurrentState();

    bool m_shouldPop = false;
    bool m_shouldExit = false;
    bool m_shouldChageState = false;
    std::unique_ptr<StateBase> m_change;
};

template<typename T> inline void Game::initGame() {
    this->pushState<T>(*this);
}

template<typename T, typename... Args>
inline void Game::pushState(Args &&... args) {
    pushState(std::make_unique<T>(std::forward<Args>(args)...));
}

template<typename T, typename... Args>
inline void Game::changeState(Args &&... args) {
    m_change = std::make_unique<T>(std::forward<Args>(args)...);
    m_shouldPop = true;
    m_shouldChageState = true;
}

#endif //SPACE_INVADERS_GAME_HH
