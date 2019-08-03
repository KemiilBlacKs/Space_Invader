/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  StateMainMenu.cpp                                          #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/18/19 15:14:23 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 08/02/19 20:56:48 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "StateMainMenu.hh"
#include "StateHighscores.hh"
#include "StatePlaying.hh"
#include "../Source/Game.hh"
#include "../GUI/Button.hh"

namespace SpaceInvaders {
    StateMainMenu::StateMainMenu(Game &game)
            : StateBase(game, "Menu Principal", Display::WIDTH, Display::HEIGHT),
              m_mainMenu(game.getWindow(), Display::HEIGHT / 2 - 100) {
        m_banner.setSize({(float) Display::WIDTH, 200});
        m_banner.setTexture(&ResourceHolder::get().textures.get("si/logo"));

        m_music_game.openFromFile("../Ressources/Sfx/si/main-music.ogg");
        m_music_game.play();
        m_music_game.setLoop(true);

        auto playBtn = gui::makeButton();
        playBtn->setText("Jouer au jeu");
        playBtn->setFunction([&]() { m_pGame->pushState<StatePlaying>(*m_pGame); m_music_game.pause(); });

        auto highscoresBtn = gui::makeButton();
        highscoresBtn->setText("Meilleurs Scores");
        highscoresBtn->setFunction(
                [&]() { m_pGame->pushState<StateHighscores>(*m_pGame); });

        auto exitBtn = gui::makeButton();
        exitBtn->setText("Quitter le jeu");
        exitBtn->setFunction([&]() { m_pGame->popState(); });

        m_mainMenu.addWidget(std::move(playBtn));
        m_mainMenu.addWidget(std::move(highscoresBtn));
        m_mainMenu.addWidget(std::move(exitBtn));
        m_mainMenu.setTitle("Choisir une action", game.getWindow());
    }

    void StateMainMenu::handleEvent(sf::Event e) {
        m_mainMenu.handleEvent(e, m_pGame->getWindow());
    }

    void StateMainMenu::update(sf::Time deltaTime) {
        m_background.update(deltaTime.asSeconds());
    }

    void StateMainMenu::render(sf::RenderTarget &renderer) {
        m_background.draw(renderer);
        m_mainMenu.render(renderer);
        renderer.draw(m_banner);
    }
}