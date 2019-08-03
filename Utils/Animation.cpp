/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  Animation.cpp                                              #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/22/19 10:22:35 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/22/19 10:26:25 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/
#include "Animation.hh"

Animation::Animation(unsigned frameWidth, unsigned frameHeight)
        : FRAME_WIDTH(frameWidth), FRAME_HEIGHT(frameHeight) {}

// Ajout d'un cadre...
void Animation::addFrame(unsigned index, sf::Time delay) {
    sf::IntRect bounds;
    bounds.top = 0;
    bounds.height = FRAME_HEIGHT;
    bounds.width = FRAME_WIDTH;
    bounds.left = index * FRAME_WIDTH;

    m_frames.emplace_back(bounds, delay);
}

// Renvoie le cadre actuel/actif de l'animation
const sf::IntRect &Animation::getFrame() {
    if (m_timer.getElapsedTime() >= m_frames[m_framePointer].delay) {
        m_timer.restart();
        m_framePointer++;
        if (m_framePointer == m_frames.size())
            m_framePointer = 0;
    }

    return m_frames[m_framePointer].bounds;
}
