#include "AssetLibrary.hpp"
#include "AssetManager.hpp"
#include "TextureId.hpp"
#include "SoundId.hpp"
#include "Game.hpp"

int main()
{
    TextureManager textureManager;
    SoundManager SoundManager;

    /*
     * Our game is simple enough that we can load all our assets at once.
     * For real games, these would be loaded / freed based on level, location,
     * etc.
     */
    AssetLibrary::loadAllTextures(textureManager);
    AssetLibrary::loadAllSounds(SoundManager);

    Game game(textureManager, SoundManager);
    game.run();
}
