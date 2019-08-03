//
// Created by Mouhammad DAHALANI on 2019-07-18.
//

#ifndef SPACE_INVADERS_STARSBACKGROUND_HH
#define SPACE_INVADERS_STARSBACKGROUND_HH

#pragma once

#include <SFML/Graphics.hpp>
#include "../Utils/Random.hh"

namespace SpaceInvaders {

    class StarsBackground {
    public:
        StarsBackground();

        void update(float dt);

        void draw(sf::RenderTarget &renderer);

    private:
        void giveStarRandomStartLocation(sf::Vertex &v);

        std::vector<sf::Vertex> m_stars;

        Random<> m_rng;
    };
}
#endif //SPACE_INVADERS_STARSBACKGROUND_HH
