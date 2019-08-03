/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  FpsCounter.cpp                                             #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/17/19 10:14:48 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/17/19 11:06:34 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "FpsCounter.hh"

#include "ResourceHolder.hh"

#include <iostream>

FpsCounter::FpsCounter() {
    m_text.move(0, 0);
    m_text.setOutlineColor(sf::Color::Black);
    m_text.setFillColor({255, 255, 255});
    m_text.setOutlineThickness(2);
    m_text.setFont(ResourceHolder::get().fonts.get("Roboto-Regular"));
    m_text.setCharacterSize(15);
}

// Mise à jour des FPS
void FpsCounter::update() {
    m_frameCount++;

    if (m_delayTimer.getElapsedTime().asSeconds() > 0.2) {
        m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
        m_frameCount = 0;
        m_delayTimer.restart();
    }
}

// Imprime les FPS sur l'écran
void FpsCounter::draw(sf::RenderTarget &renderer) {
    m_text.setString("FPS " + std::to_string((int) m_fps));
    renderer.draw(m_text);
}