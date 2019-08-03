/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  StateBase.cpp                                              #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/16/19 11:25:33 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 07/16/19 16:58:43 by Dahalani Mouhamad            #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/

#include "StateBase.hh"

#include "../Source/Game.hh"

StateBase::StateBase(Game &game, const char *name)
        : m_pGame(&game), m_name(name) {}

StateBase::StateBase(Game &game, const char *name, unsigned resizeWindowWidth,
                     unsigned resizeWindowHeight)
        : m_pGame(&game), m_name(name) {
    m_pGame->resizeWindow(resizeWindowWidth, resizeWindowHeight);
}