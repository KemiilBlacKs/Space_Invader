//
// Created by Mouhammad DAHALANI on 2019-07-16.
//

#ifndef SPACE_INVADERS_STATEBASE_HH
#define SPACE_INVADERS_STATEBASE_HH
#pragma once

#include <SFML/Graphics.hpp>

#include "../Utils/NonCopyable.hh"

class Game;

class StateBase : public NonCopyable {
public:
    StateBase(Game &game, const char *name);

    StateBase(Game &game, const char *name, unsigned resizeWindowWidth,
              unsigned resizeWindowHeight);

    virtual ~StateBase() = default;

    virtual void onOpen() {}
    virtual void handleEvent(sf::Event e) {}
    virtual void handleInput() {}
    virtual void update(sf::Time deltaTime) {}
    virtual void fixedUpdate(sf::Time deltaTime) {}
    virtual void render(sf::RenderTarget &renderer) = 0;

    const std::string &getName() { return m_name; }

protected:
    Game *m_pGame;
    std::string m_name;
};


#endif //SPACE_INVADERS_STATEBASE_HH
