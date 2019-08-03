/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  AnimationRenderer.cpp                                      #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/19/19 11:47:12 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/19/19 11:50:07 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "AnimationRenderer.hh"

namespace SpaceInvaders {
    AnimationRenderer::AnimationRenderer(int frameWidth, int frameHeight,
                                         float entityWidth, float entityHeight,
                                         const sf::Texture &spriteSheet)
            : m_frameWidth(frameWidth), m_frameHeight(frameHeight) {
        m_entity.setSize({entityWidth, entityHeight});
        m_entity.setTexture(&spriteSheet);
    }

    void AnimationRenderer::nextFrame() { m_currentFrame++; }

    void AnimationRenderer::renderEntity(sf::RenderTarget &renderer, int type,
                                         const sf::Vector2f &position) {
        // Calculer les coordonnées de texture
        int texLeft = (m_currentFrame % 2) * m_frameWidth;
        int texTop = (type * m_frameHeight);

        // Repositionnement et dessin du sprite
        m_entity.setPosition(position);
        m_entity.setTextureRect({texLeft, texTop, m_frameWidth, m_frameHeight});
        renderer.draw(m_entity);
    }
}