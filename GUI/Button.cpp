/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Button.cpp                                                 #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/19/19 10:38:45 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/19/19 10:40:10 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include <iostream>
#include "Button.hh"

namespace gui {
    Button::Button(ButtonSize size) {
        m_button.setOutlineThickness(1);
        m_button.setOutlineColor(sf::Color::Green);
        m_button.setFillColor(sf::Color::Black);
        switch (size) {
            case ButtonSize::Wide:
                m_button.setSize({256, 64});
                break;

            case ButtonSize::Small:
                m_button.setSize({128, 64});
                break;
        }
    }

    void Button::setFunction(std::function<void(void)> function) {
        m_function = function;
    }

    void Button::setText(const std::string &str) {
        m_text.setString(str);
        updateText();
    }

    void Button::setTexture(const sf::Texture &tex) { m_button.setTexture(&tex); }

    void Button::handleEvent(sf::Event e, const sf::RenderWindow &window) {
        auto pos = sf::Mouse::getPosition(window);

        switch (e.type) {
            case sf::Event::MouseButtonPressed:
                switch (e.mouseButton.button) {
                    case sf::Mouse::Left:
                        if (m_button.getGlobalBounds().contains((float) pos.x,
                                                                (float) pos.y)) {
                            m_function();
                        }

                    default:
                        break;
                }

            default:
                break;
        }
    }

    void Button::render(sf::RenderTarget &renderer) {
        renderer.draw(m_button);
        renderer.draw(m_text);
    }

    void Button::setPosition(const sf::Vector2f &pos) {
        m_position = pos;

        m_button.setPosition(m_position);
        m_text.setPosition(m_position);

        updateText();
    }

    void Button::updateText() {
        m_text.setOrigin(m_text.getGlobalBounds().width / 2,
                         m_text.getGlobalBounds().height / 2);

        m_text.move(m_button.getGlobalBounds().width / 2.0f,
                    m_button.getGlobalBounds().height / 2.5f);
    }

    sf::Vector2f Button::getSize() const { return m_button.getSize(); }

}