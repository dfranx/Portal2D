# Portal2D
Portal2D is a simple game prototype. The main mechanic of the game is to bounce off of the obstacles.
Your goal is to get to the green platform.
Various things could be added to this game in future. For example: moving platforms, spikes, more complex shapes, etc...
The graphics is simple and it is just a placeholder. Also, quad tree could be implemented so that the line-line collision
isnt checked with every single obstacle.

![portal2d.png](http://i.imgur.com/MZFZcK8.png)

## Building
This project uses [SFML](https://www.sfml-dev.org) *v2.5*.

### Installing
First, you need the source code:
```
git clone https://github.com/GeneralNote/Portal2D.git Portal2D
cd Portal2D
```

To build it on **Linux** run these commands:
```
cmake .
make
./Portal2D
```

To build it on **Windows** open the *.vcxproj* file. After that link SFML and build the project.

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
