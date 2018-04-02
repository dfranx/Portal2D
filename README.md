# Portal2D
This project is a simple game prototype. In this game you bounce off of walls and teleport around the map.
Your goal is to get to the green platform.

## Screenshots  
![portal2d.png](http://i.imgur.com/MZFZcK8.png)

Player is a simple green circle while his path is shown with a blue lines.
We move the player with left mouse button press. White platforms are normal stationary platforms.
We win by getting on green platform.

## Getting Started
These steps will show you how to build Portal2D on your machine.

### Dependencies
This project uses SFML for rendering. To get SFML on your computer you can
visit this [link](https://www.sfml-dev.org/download.php). Portal2D uses *v2.4.2*
because at the time of making it was the newest version.

### Installing
First, you need the source code:
```
git clone https://github.com/GeneralNote/Portal2D.git Portal2D
cd Portal2D
```

Then you can build it
```
cmake .
make
```

If you get error message which says that SFML was not found on your computer
you need to specify SFML_ROOT variable in your ***cmake*** command:
```
cmake -DSFML_ROOT=path/to/your/sfml . 
```

Finally, run Portal2D:
```
./Portal2D
```

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
