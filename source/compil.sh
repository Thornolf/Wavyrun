g++ core/*.cpp main.cpp -I/usr/local/SFML/include -o ../release/Wavyrun -L/usr/local/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++11

# Don't forget to : export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/SFML/lib
