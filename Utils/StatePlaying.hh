//
// Created by Mouhammad DAHALANI on 2019-07-19.
//

#ifndef SPACE_INVADERS_STATEPLAYING_HH
#define SPACE_INVADERS_STATEPLAYING_HH
#pragma once

#include "StateBase.hh"
#include "StateMainMenu.hh"
#include "../GUI/StackMenu.hh"
#include "../Source/World.hh"

namespace SpaceInvaders {
/*
    L'état principal ; où tout le gameplay se passe
*/
    class StatePlaying : public StateBase {
    public:
        StatePlaying(Game &game);

        void handleEvent(sf::Event e) override;

        void handleInput() override;

        void update(sf::Time deltaTime) override;

        void render(sf::RenderTarget &renderer) override;

    private:
        World m_world;

        int m_score = 0;
        bool m_isGameover;
        sf::Clock m_gameOverClock;
        gui::StackMenu m_gameOverMenu;

        // Affiche le nombre de vies qu'il reste au joueur
        class LifeDisplay {
        public:
            LifeDisplay();

            void draw(sf::RenderTarget &window, int lives);

        private:
            gui::Widget::Text m_label;
            sf::RectangleShape m_lifeStamp;
        } m_lifeDisplay;

        // Affiche le score actuel du joueur
        class ScoreDisplay {
        public:
            ScoreDisplay(float centreX, const std::string &text);

            void update(int newScore);

            void draw(sf::RenderTarget &target);

            int getCurrentScoreDisplayed() const;

        private:
            void updateDisplay();

            gui::Widget::Text m_label;
            std::string m_text;
            int m_currentScore;
            float m_centerPosition;
        } m_scoreDisplay, m_highestScoreDisplay;
    };
}
#endif //SPACE_INVADERS_STATEPLAYING_HH
