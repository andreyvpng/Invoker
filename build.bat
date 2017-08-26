g++.exe -c Source\main.cpp -I <sfml-install-path>\include
g++ main.o -o Invoker -L <sfml-install-path>\lib -lsfml-graphics -lsfml-window -lsfml-system
DEL main.o