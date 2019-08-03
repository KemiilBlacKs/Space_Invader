/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  StarsBackground.cpp                                        #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/18/19 15:59:56 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/29/19 11:39:26 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "StarsBackground.hh"
#include "../Utils/DisplayInfo.hh"

namespace SpaceInvaders {
    StarsBackground::StarsBackground() {
        for (int i = 0; i < 500; i++) {
            sf::Vertex star;
            giveStarRandomStartLocation(star);
            star.position.y -= Display::HEIGHT;
            m_stars.push_back(star);
        }
    }

    void StarsBackground::update(float dt) {
        for (auto &star : m_stars) {
            star.position.y -= 250 * dt;
            if (star.position.y <= 0) {
                giveStarRandomStartLocation(star);
            }
        }
    }

    void StarsBackground::draw(sf::RenderTarget &renderer) {
        renderer.draw(m_stars.data(), m_stars.size(), sf::Points);
    }

    void StarsBackground::giveStarRandomStartLocation(sf::Vertex &star) {
        star.position = {m_rng.getFloatInRange(0, (float) Display::WIDTH),
                         m_rng.getFloatInRange((float) Display::HEIGHT,
                                               (float) Display::HEIGHT * 2.0f)};
    }
}