LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX := g++

all: dortal

%.o: %.cpp
	$(CXX) -c $< -o $@ -std=c++11

%.o: %.h
	$(CXX) -c $< -o $@ -std=c++11

dortal: main.o Level.o LevelBuilder.o LevelObstacle.o LevelRenderer.o Player.o Ray.o
	@echo "** Building the game"
	$(CXX) -o dortal.bin main.o Level.o LevelBuilder.o LevelRenderer.o Player.o Ray.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f dortal.bin *.o

install:
	@echo '** Installing...'
	cp dortal /usr/bin/

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/dortal

