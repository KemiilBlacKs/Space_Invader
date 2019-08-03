//
// Created by Mouhammad DAHALANI on 2019-07-17.
//

#ifndef SPACE_INVADERS_FPSCOUNTER_HH
#define SPACE_INVADERS_FPSCOUNTER_HH
#pragma once

#include <SFML/Graphics.hpp>

class FpsCounter {
public:
    FpsCounter();

    void update();

    void draw(sf::RenderTarget &renderer);

private:
    sf::Text m_text;
    sf::Font m_font;

    sf::Clock m_delayTimer;
    sf::Clock m_fpsTimer;

    float m_fps = 0;

    int m_frameCount = 0;
};


#endif //SPACE_INVADERS_FPSCOUNTER_HH
