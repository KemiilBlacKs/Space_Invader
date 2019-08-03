//
// Created by Mouhammad DAHALANI on 2019-07-18.
//

#ifndef SPACE_INVADERS_STACKMENU_HH
#define SPACE_INVADERS_STACKMENU_HH
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../Utils/NonCopyable.hh"
#include "Widget.hh"

namespace gui {
/**
 * @brief Class pour menu vertical
 * Un menu de pile est un menu où ses widgets apparaissent dans une pile verticale.
 */
    class StackMenu : public NonCopyable {
    public:
        StackMenu(const sf::RenderWindow &window, float baseY);

        StackMenu(const sf::Vector2f &position);

        StackMenu(StackMenu &&other);

        StackMenu &operator=(StackMenu &&other);

        ~StackMenu() = default;

        void addWidget(std::unique_ptr<Widget> w);

        /*
        template<typename T, typename... Args>
        void addWidget(Args&&... args) {
            auto w = std::make_unique<T>(std::forward<Args>(args)...);
            initWidget(*w);
            m_widgets.push_back(std::move(w));
        }*/

        void setTitle(const std::string &title, const sf::RenderTarget &target);

        void handleEvent(sf::Event e, const sf::RenderWindow &window);

        void render(sf::RenderTarget &renderer);

    private:
        void initWidget(Widget &w);

        std::vector<std::unique_ptr<Widget>> m_widgets;
        sf::RectangleShape m_background;

        sf::Vector2f m_basePosition;
        sf::Vector2f m_baseSize;

        Widget::Text m_titleText;
    };

}
#endif //SPACE_INVADERS_STACKMENU_HH
