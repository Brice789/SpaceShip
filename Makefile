#############
# Main target
TARGET=efreiroids
.DEFAULT_GOAL := $(TARGET)
# For use with bmake
.MAIN := $(TARGET)

#########################################
# Variables to control Makefile operation
CC = g++
CFLAGS = -Wall -g -std=c++11
SDL_FLAGS = `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`
MAIN = main.cpp
ALL_OBJECTS = framework.o 
# spaceship.o asteroid.o missile.o flying_object.o model.o view.o controller.o

########
# Builds 
$(TARGET): $(MAIN) $(ALL_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(MAIN) $(ALL_OBJECTS)

# asteroid.o: asteroid.hpp asteroid.cpp
# 	$(CC) $(CFLAGS) -c asteroid.cpp

# missile.o: missile.hpp missile.cpp
# 	$(CC) $(CFLAGS) -c missile.cpp

# spaceship.o: spaceship.hpp spaceship.cpp
# 	$(CC) $(CFLAGS) -c spaceship.cpp

# flying_object.o: flying_object.hpp flying_object.cpp
# 	$(CC) $(CFLAGS) -c flying_object.cpp

framework.o: framework.hpp framework.cpp
	$(CC) $(CFLAGS) $(SDL_FLAGS) -c framework.cpp

# model.o: model.hpp model.cpp
# 	$(CC) $(CFLAGS) -c model.cpp

# view.o: view.hpp view.cpp
# 	$(CC) $(CFLAGS) -c view.cpp

# controller.o: controller.hpp controller.cpp view.hpp model.hpp
# 	$(CC) $(CFLAGS) -c controller.cpp

clean :
	rm -f $(ALL_OBJECTS) $(TARGET)
