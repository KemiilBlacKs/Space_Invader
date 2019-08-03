//
// Created by Mouhammad DAHALANI on 2019-07-22.
//

#ifndef SPACE_INVADERS_ANIMATION_HH
#define SPACE_INVADERS_ANIMATION_HH
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    struct Frame {
        Frame(const sf::IntRect &bnds, sf::Time dly)
                : bounds(bnds), delay(dly) {}

        sf::IntRect bounds; // La zone dans une texture du cadre
        sf::Time delay;     // Temporisation jusqu'à l'image suivante
    };

    Animation(unsigned frameWidth, unsigned frameHeight);

    void addFrame(unsigned index, sf::Time delay);

    const sf::IntRect &getFrame();

private:
    sf::Clock m_timer; // Minuterie pour faire avancer l'animation

    std::vector<Frame> m_frames; // Liste des cadres d'animation

    unsigned m_framePointer = 0; // L'index de la trame active courante
    const unsigned FRAME_WIDTH;
    const unsigned FRAME_HEIGHT;
};

#endif //SPACE_INVADERS_ANIMATION_HH
