#include "AssetLibrary.hpp"
#include "AssetManager.hpp"
#include "TextureId.hpp"
#include "SoundId.hpp"
#include "Game.hpp"

#include "components/Player.hpp"

#include <entityx/Event.h>
#include <entityx/Entity.h>
#include <entityx/System.h>

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

    /* Make the entity, event, and system managers. */
    entityx::EventManager eventManager;
    entityx::EntityManager entityManager(eventManager);
    entityx::SystemManager systemManager(entityManager, eventManager);

    /* Make the player. */
    // Player player(textureManager.get(TextureId::PlayerShip));
    Player player;

    /* Make the game. */
    Game game(
        textureManager,
        soundManager,
        eventManager,
        entityManager,
        systemManager,
        player);

    /* Run the game! Hope you enjoy! */
    game.run();
}
