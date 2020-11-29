Welcome to SpaceWar! This is a variant of the classic [1962 computer game](https://en.wikipedia.org/wiki/Spacewar!). It is my attempt to learn how to use an entity-component system. I made heavy use of the book [SFML Game Development](https://github.com/SFML/SFML-Game-Development-Book) and [Triangulum](https://github.com/TransNeptunianStudios/Triangulum) to guide me in the right direction.

Assets (textures, music, sound effects) are credited in the "Credits" menu.

Setup Instructions
```
git submodule init
git submodule update
```

Build Instructions
```
mkdir -p build
mkdir -p install
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install
cmake --build . --config Release
```

Run from within the install directory so that the binary can find the assets.

The C++ standard is C++17, although it can probably work with lower. Compilation has been tested on Ubuntu 20.04 with GCC 9.3.0, And Windows 10 with Visual Studio 2019. I'm sure you can get away with older versions though.
