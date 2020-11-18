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

Run from within the install directory.
