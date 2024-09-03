abmmake: src/*
	g++ -std=c++17 -Ofast -I headers -o serial.out src/* -L/Users/nehayelshetty/Desktop/lib64 -lmysqlcppconn
abmdebug:
	g++ -std=c++17 -g -I headers -o serial.out src/*

