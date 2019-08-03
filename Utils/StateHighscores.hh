//
// Created by Mouhammad DAHALANI on 2019-07-18.
//

#ifndef SPACE_INVADERS_STATEHIGHSCORES_HH
#define SPACE_INVADERS_STATEHIGHSCORES_HH

#pragma once

#include "StateBase.hh"
#include "../GUI/StackMenu.hh"
#include "../GUI/Widget.hh"
#include "../Source/StarsBackground.hh"

namespace SpaceInvaders {
    class StateHighscores : public StateBase {
        using Entry = std::pair<std::string, int>;

        struct EntryBox {
        public:
            EntryBox(int position, const std::string &name, int score);

            void draw(sf::RenderTarget &renderer);

        private:
            sf::RectangleShape m_background;
            gui::Widget::Text m_nameText;
            gui::Widget::Text m_scoreText;
        };

        enum class State {
            Submitting, Viewing
        };

    public:
        StateHighscores(Game &game, int score);

        StateHighscores(Game &game);

        void handleEvent(sf::Event e) override;

        void handleInput() override {};

        void update(sf::Time deltaTime) override;

        void render(sf::RenderTarget &renderer) override;

        static int getHighestScore();

    private:
        void initViewMenu();

        void initSubmitMenu();

        void switchToViewMenu();

        void createHighscoreView();

        void loadScores();

        void writeScores();

        void sortScores();

        void submitScore();

        gui::StackMenu m_submitScoreMenu;
        gui::StackMenu m_highscoreMenu;
        gui::StackMenu *m_pActiveMenu;

        std::vector<Entry> m_scores;
        std::vector<EntryBox> m_entryBoxes;

        StarsBackground m_background;

        State m_state;

        std::string m_submitString;
        int m_scoreToSubmit = 0;

        sf::RectangleShape m_banner;
    };
}

#endif //SPACE_INVADERS_STATEHIGHSCORES_HH
