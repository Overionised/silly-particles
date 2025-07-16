# Silly-particles

## Build Instructions

### Linux

~~~
git clone https://github.com/Overionised/silly-particles
cd silly-particles/build
./premake5-compat gmake # you can also run  ./premake5 gmake   on newer systems
cd ..
make
cd bin
~~~
executable should be in bin, or in the debug folder

### macOS
~~~
git clone https://github.com/Overionised/silly-particles                  
cd silly-particles/build                                                                    
./premake5.osx gmake          
cd ..   
make
cd bin
~~~ 
executable should be in bin, or in the debug folder

### windows
~~~
git clone https://github.com/Overionised/silly-particles
Double click the build-MinGW-W64.bat file
cd silly-particles/
make
~~~
executable should be in bin, or in the debug folder

## Credits

This project is based on:

- [raylib-quickstart](https://github.com/raylib-extras/raylib-quickstart) by Jeffery Myers (© 2020–2025)
- [raylib](https://github.com/raysan5/raylib) by raysan5

Modifications were made to source layout and build configuration.
