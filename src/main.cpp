#include "AssetLibrary.hpp"
#include "AssetManager.hpp"
#include "TextureId.hpp"
#include "SoundId.hpp"
#include "Game.hpp"

int main()
{
    /* Dependency injection - make as many things up front as you can. */
    TextureManager textureManager;
    SoundManager soundManager;

    /*
     * Our game is simple enough that we can load all our assets at once.
     * For real games, these would be loaded / freed based on level, location,
     * etc.
     */
    AssetLibrary::loadAllTextures(textureManager);
    AssetLibrary::loadAllSounds(soundManager);

    Game game(textureManager, soundManager);
    game.run();
}
