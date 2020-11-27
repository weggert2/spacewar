#include "AssetLibrary.hpp"
#include "AssetManager.hpp"
#include "Game.hpp"
#include "GameManager.hpp"
#include "KeyManager.hpp"
#include "AssetIds.hpp"

#include "components/Player.hpp"

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
    AssetLibrary::loadAllTextures(textureManager);
    AssetLibrary::loadAllSounds(soundManager);
    AssetLibrary::loadAllText(textManager);

    /* Make the entity, event, and system managers. */
    entityx::EventManager eventManager;
    entityx::EntityManager entityManager(eventManager);
    entityx::SystemManager systemManager(entityManager, eventManager);
    GameManager gameManager(entityManager, eventManager);
    KeyManager keyManager;

    /* Make the player. */
    Player player;
    // Player player(textureManager.get(TextureId::PlayerShip));

    /* Make the game. */
    Game game(
        textureManager,
        soundManager,
        eventManager,
        entityManager,
        systemManager,
        gameManager,
        keyManager,
        player);

    /* Run the game! Hope you enjoy! */
    game.run();
}
