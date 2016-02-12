c4: connect4_driver.c connect4_engine.c
	clang -o connect4 connect4_driver.c connect4_engine.c -g -Wall
tests: CuTest.c c4_engine_test.c connect4_engine.c
	clang -o c4_engine_test CuTest.c c4_engine_test.c connect4_engine.c -g -Wall
