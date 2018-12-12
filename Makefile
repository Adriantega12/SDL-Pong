#OBJS specifies which files to compile as part of the project 
OBJS = main.cpp game_loop.cpp game_state_play.cpp game_state_menu.cpp sdl_graphics.cpp sdl_input.cpp graphics_component.cpp physics_component.cpp player.cpp enemy.cpp paddle.cpp ball.cpp gs_play_display.cpp


#CC specifies which compiler we're using 
CC = g++ -std=c++11

#COMPILER_FLAGS specifies the additional compilation options we're using # -w suppresses all warnings 
COMPILER_FLAGS = -w 

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lSDL2 -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = pong 

#This is the target that compiles our executable 
all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
