

## Build
only tested on linux, you need to have https://github.com/raysan5/raylib installed
### option 1 temporary install
~~~ shell
git clone https://github.com/Overionised/silly-particles
cd silly-particles
gcc main.c -o silly-particles -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 
~~~

### option 2 permanent install
~~~ shell
git clone https://github.com/Overionised/silly-particles
cd silly-particles
gcc main.c -o silly-particles -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
sudo cp silly-particles /usr/bin/
~~~
## Run
### option 1 usage
~~~ shell
./silly-particles
~~~

### option 2 usage
~~~ shell
silly-particles
~~~
