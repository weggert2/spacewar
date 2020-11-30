/**
 * @file
 *
 * $Id: AssetLibrary.hpp $
 * @author Bill Eggert
 */

#include "AssetManager.hpp"

namespace AssetLibrary
{
    /* Load assets into their various managers. */
    bool loadAllTextures(TextureManager &textureManager);
    bool loadAllSounds(SoundManager &soundManager);
    bool loadAllText(TextManager &textManager);
    bool loadAllFonts(FontManager &fontManager);
    bool loadAllMusic(MusicManager &musicManager);
}; /* end namespace AssetLibrary. */
