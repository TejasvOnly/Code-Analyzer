#include<stdio.h>
#include<stdlib.h>
#include<chrono>
#include<fstream>
#include<iostream>
#define INITIALIZER(f) \
        static void f(void); \
        struct f##_t_ { f##_t_(void) { f(); } }; static f##_t_ f##_; \
        static void f(void)

std::chrono::time_point<std::chrono::system_clock> start, end;

std::ifstream in("in.txt"); 
auto cinbuf = std::cin.rdbuf(in.rdbuf());


std::ofstream out("out.txt");
auto coutbuf = std::cout.rdbuf(out.rdbuf());

static void finalize(void) {
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	printf("\n%f",elapsed_seconds.count());
}

INITIALIZER(initialize) {
	start = std::chrono::system_clock::now();
	atexit(finalize);
}