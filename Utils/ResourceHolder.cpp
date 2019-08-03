/* **********************************************************************************************/
/*                                                                                              */
/*                                                             ##############################   */
/*  ResourceHolder.cpp                                         #                            #   */
/*                                                             #   SPACE INVADERS CUSTOM    #   */
/*  By: Dahalani Mouhamad <dahala_m@etna-alternance.net>       #          fourra_b          #   */
/*                                                             #          dahala_m          #   */
/*  created: 07/17/19 10:34:49 by Dahalani Mouhamad            #          bachir_c          #   */
/*  updated: 08/02/19 16:41:02 by Dahalani Mouhammad           #                            #   */
/*                                                             ##############################   */
/*                                                                                              */
/* **********************************************************²***********************************/
#include "ResourceHolder.hh"

ResourceHolder &ResourceHolder::get() {
    static ResourceHolder holder;
    return holder;
}

ResourceHolder::ResourceHolder()
        : fonts("Fonts", "ttf"), textures("Textures", "png"),
          soundBuffers("Sfx", "ogg") {}