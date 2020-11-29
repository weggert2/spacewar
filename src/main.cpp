#include "AssetIds.hpp"
#include "AssetLibrary.hpp"
#include "AssetManager.hpp"
#include "Game.hpp"
#include "GameManager.hpp"
#include "KeyManager.hpp"

#include <entityx/Event.h>
#include <entityx/Entity.h>
#include <entityx/System.h>

int main()
{
    /***********************************************************************
     * Dependency injection - make as many things up front as you can.     *
     * Main can look a bit crazy, but it's much easier to figure out where *
     * objects are coming from.                                            *
     ***********************************************************************/

    /*
     * Our game is simple enough that we can load all our assets at once.
     * For real games, these would be loaded / freed based on level, location,
     * etc.
     */
    TextureManager textureManager;
    SoundManager soundManager;
    TextManager textManager;
    FontManager fontManager;
    MusicManager musicManager;
    AssetLibrary::loadAllTextures(textureManager);
    AssetLibrary::loadAllSounds(soundManager);
    AssetLibrary::loadAllText(textManager);
    AssetLibrary::loadAllFonts(fontManager);
    AssetLibrary::loadAllMusic(musicManager);

    /* Make the entity, event, and system managers. */
    entityx::EventManager eventManager;
    entityx::EntityManager entityManager(eventManager);
    entityx::SystemManager systemManager(entityManager, eventManager);
    KeyManager keyManager;

    GameManager gameManager(
        textureManager,
        soundManager,
        textManager,
        fontManager,
        musicManager,
        entityManager,
        eventManager,
        systemManager);

    /* Make the game. */
    Game game(
        textureManager,
        soundManager,
        textManager,
        fontManager,
        eventManager,
        entityManager,
        systemManager,
        gameManager,
        keyManager);

    /* Run the game! Hope you enjoy! */
    game.run();
}
