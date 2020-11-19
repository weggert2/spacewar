#include "AssetManager.hpp"
#include "Game.hpp"

int main()
{
    AssetManager assetManager;

    /* We have very few textures, so we can afford to load them
     * all at once. For a larger game, we would load them based
     * on what level, area (i.e. game state) you're in. */
    AssetLibrary::loadAllAssets(assetManager);

    Game game(assetManager);
    game.run();
}
