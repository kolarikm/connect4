connect4make: connect4_driver.c connect4_engine.c
	clang -o connect4 connect4_driver.c connect4_engine.c -g -Wall
