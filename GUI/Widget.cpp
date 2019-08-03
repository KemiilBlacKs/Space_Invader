/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Widget.cpp                                                 #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/18/19 15:39:13 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/18/19 15:40:03 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "Widget.hh"

namespace gui {

// Text
    Widget::Text::Text() {
        setCharacterSize(25);
        setOutlineColor(sf::Color::Black);
        setFillColor(sf::Color::White);
        setFont(ResourceHolder::get().fonts.get("Roboto-Regular"));
    }

    bool Widget::Rectangle::isRolledOn(const sf::RenderWindow &window) const {
        auto pos = sf::Mouse::getPosition(window);
        return getGlobalBounds().contains((float)pos.x, (float)pos.y);
    }

    bool Widget::Rectangle::isClicked(sf::Event e, const sf::RenderWindow &window) {
        if (isRolledOn(window)) {
            if (e.type == sf::Event::MouseButtonPressed) {
                return e.mouseButton.button == sf::Mouse::Left;
            }
        }
        return false;
    }

}