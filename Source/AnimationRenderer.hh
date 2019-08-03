//
// Created by Mouhammad DAHALANI on 2019-07-19.
//

#ifndef SPACE_INVADERS_ANIMATIONRENDERER_HH
#define SPACE_INVADERS_ANIMATIONRENDERER_HH
#pragma once

#include <SFML/Graphics.hpp>

namespace SpaceInvaders {
/*
    Classe utilitaire pour la restitution d'un grand nombre de droits qui se partagent
    la même animation
*/
    class AnimationRenderer {
    public:
        AnimationRenderer(int frameWidth, int frameHeight, float entityWidth,
                          float entityHeight, const sf::Texture &spriteSheet);

        // Changements à l'image suivante
        void nextFrame();

        // Rendu d'une seule entité, en utilisant le cadre d'animation courant
        void renderEntity(sf::RenderTarget &renderer, int type,
                          const sf::Vector2f &position);

    private:
        sf::RectangleShape m_entity;
        int m_currentFrame;
        const int m_frameWidth;
        const int m_frameHeight;
    };
}

#endif //SPACE_INVADERS_ANIMATIONRENDERER_HH
