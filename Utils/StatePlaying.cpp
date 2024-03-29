/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  StatePlaying.cpp                                           #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/19/19 10:53:32 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 08/02/19 20:56:57 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include <iostream>
#include "StatePlaying.hh"
#include "StateHighscores.hh"
#include "ResourceHolder.hh"
#include "../Source/Game.hh"
#include "../GUI/Button.hh"

namespace SpaceInvaders {
    StatePlaying::StatePlaying(Game &game)
            : StateBase(game, "Jouer au jeu"),
              m_gameOverMenu(game.getWindow(), Display::HEIGHT / 3),
              m_scoreDisplay(Display::WIDTH / 8, "Score"),
              m_highestScoreDisplay(Display::WIDTH / 2, "Meilleur score ")            {

        auto mmButton = std::make_unique<gui::Button>();
        mmButton->setText("Menu principal");
        mmButton->setFunction([&]() { m_pGame->popState(); });

        auto submitBtn = std::make_unique<gui::Button>();
        submitBtn->setText("Enregistrer un score");
        submitBtn->setFunction(
                [&]() { m_pGame->changeState<StateHighscores>(*m_pGame, m_score); });

        auto exitButton = std::make_unique<gui::Button>();
        exitButton->setText("Quitter le jeu");
        exitButton->setFunction([&]() { m_pGame->exitGame(); });

        m_gameOverMenu.setTitle("Perdu", game.getWindow());
        m_gameOverMenu.addWidget(std::move(mmButton));
        m_gameOverMenu.addWidget(std::move(submitBtn));
        m_gameOverMenu.addWidget(std::move(exitButton));

        m_highestScoreDisplay.update(StateHighscores::getHighestScore());
    }

    void StatePlaying::handleEvent(sf::Event e) {
        if (m_isGameover) {
            m_gameOverMenu.handleEvent(e, m_pGame->getWindow());
        }
    }

    void StatePlaying::handleInput() { m_world.input(); }

    void StatePlaying::update(sf::Time deltaTime) {
        if (!m_isGameover) {
            m_score += m_world.update(deltaTime.asSeconds());
            m_scoreDisplay.update(m_score);

            if (m_score > m_highestScoreDisplay.getCurrentScoreDisplayed()) {
                m_highestScoreDisplay.update(m_score);
            }
        }

        m_isGameover = m_world.isGameOver();
    }

    void StatePlaying::render(sf::RenderTarget &renderer) {
        m_world.draw(renderer);

        m_lifeDisplay.draw(renderer, m_world.getPlayer().getLives());
        m_scoreDisplay.draw(renderer);
        m_highestScoreDisplay.draw(renderer);

        if (m_isGameover) {
            m_gameOverMenu.render(renderer);
        }
    }

/////////////////////////////////////////////////
//     Fonctions d'affichage des membres      ///
    StatePlaying::LifeDisplay::LifeDisplay() {
        m_lifeStamp.setSize({Player::WIDTH / 2, Player::WIDTH / 2});
        m_lifeStamp.setTexture(&ResourceHolder::get().textures.get("si/player"));
        //m_lifeStamp.setTextureRect({0, 0, 11, 8}); // Pas besoin vu que plus de sprite pour le player
        m_label.setPosition(Display::WIDTH - (Player::WIDTH * 5), 10);
        m_label.setString("Vies");
        m_label.setOutlineThickness(0);
    }

    void StatePlaying::LifeDisplay::draw(sf::RenderTarget &window, int lives) {
        float xOrigin =
                m_label.getPosition().x + m_label.getGlobalBounds().width + 10;
        float yOrigin =
                m_label.getPosition().y + m_label.getGlobalBounds().height / 2;

        window.draw(m_label);
        for (int i = 0; i < lives; i++) {
            m_lifeStamp.setPosition(xOrigin + i * Player::WIDTH / 2 + i * 10,
                                    yOrigin);
            window.draw(m_lifeStamp);
        }
    }

    StatePlaying::ScoreDisplay::ScoreDisplay(float x, const std::string &text)
            : m_text(text), m_centerPosition(x) {
        updateDisplay();
        m_label.setOutlineThickness(0);
    }

    void StatePlaying::ScoreDisplay::update(int newScore) {
        m_currentScore = newScore;
        updateDisplay();
    }

    void StatePlaying::ScoreDisplay::draw(sf::RenderTarget &target) {
        target.draw(m_label);
    }

    int StatePlaying::ScoreDisplay::getCurrentScoreDisplayed() const {
        return m_currentScore;
    }

    void StatePlaying::ScoreDisplay::updateDisplay() {
        m_label.setString(m_text + "   " + std::to_string(m_currentScore));
        m_label.setPosition(m_centerPosition - m_label.getGlobalBounds().width / 2,
                            15);
    }
}