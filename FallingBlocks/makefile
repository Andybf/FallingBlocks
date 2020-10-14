#
#  makefile
#  MicroRender
#
#  Created by Anderson Bucchianico on 13/10/20.
#  Copyright © 2020 Anderson Bucchianico. All rights reserved.
#

# Variables
compiler       = g++
operation      = -o
specification  = -std=c++11
executableName = FallingBlocks
files          = main.cpp Game/Game.cpp Game/Player.cpp Game/Target.cpp \
					MicroRender/Window.cpp MicroRender/Engine.cpp \
					MicroRender/Entity.cpp MicroRender/Writter.cpp

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) # Apple macOS

frameworks     = -L/System/Library/Frameworks -framework GLUT -framework OpenGL

All:
	$(compiler) $(specification) $(operation) $(executableName) $(files) $(frameworks)
	# Prepare the directory scheme for macOS
	rm -rf $(executableName).app
	mkdir MacOS
	mv $(executableName) MacOS
	mkdir Contents
	mv MacOS Contents
	mkdir $(executableName).app
	mv Contents $(executableName).app
	chmod 777 $(executableName).app/*
	
else

frameworks = -lGL -lGLU -lglut

All:
	$(compiler) $(specification) $(operation) $(executableName) $(files) $(frameworks)
	
endif
