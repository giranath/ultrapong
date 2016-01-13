# Ultrapong
Ultrapong is a pong-like game. 

The game was made in one week of spare time in 2013. The source code has not changed
to preserve it's initial state. I only adjust some things to be able to compile the project
in today's compilers.

![alt tag](http://imgur.com/DBvkFqg.gifv)

# How to compile?
To compile _Ultrapong_, you need these tools/libraries:
- A cpp compiler
- CMake
- Mac OSX (The code should work on Windows and Linux, but not the CMakeLists.txt as they are now)
- SFML 2
- A Bash shell

## Building steps
1. Clone the repository
2. Move into the project's directory
3. Create a new directory named _build_
4. Move into the _build_ directory
5. Run this command `cmake ..`
6. Then run this command `make`
7. Move to the project's root directory
8. Run this command `sh prepare_bundle.sh`
9. The application bundle is now ready to go (It is generated into the _bin_ folder)
