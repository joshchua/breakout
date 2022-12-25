CXX = g++
STD = -std=c++20
SDL = -lSDL2

breakout:
	$(CXX) $(STD) $(SDL) src/Exception.cc src/Color.cc src/Renderer.cc src/Vector2D.cc src/Ball.cc src/Scene.cc src/Game.cc src/main.cc
run:
	./a.out
clean:
	rm ./a.out
