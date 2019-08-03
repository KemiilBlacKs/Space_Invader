//
// Created by Mouhammad DAHALANI on 2019-07-18.
//

#ifndef SPACE_INVADERS_STATEMAINMENU_HH
#define SPACE_INVADERS_STATEMAINMENU_HH
#pragma once

#include "StateBase.hh"
#include "Random.hh"
#include "../Source/StarsBackground.hh"
#include "../GUI/StackMenu.hh"

namespace SpaceInvaders {
    class StateMainMenu : public StateBase {
    public:
        StateMainMenu(Game &game);

        void handleEvent(sf::Event e) override;

        void handleInput() override {};

        void update(sf::Time deltaTime) override;

        void render(sf::RenderTarget &renderer) override;

    private:
        gui::StackMenu m_mainMenu;
        sf::RectangleShape m_banner;
        sf::Music m_music_game;

        StarsBackground m_background;
    };
}
#endif //SPACE_INVADERS_STATEMAINMENU_HH
