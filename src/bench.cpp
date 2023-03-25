#include <iostream>
#include <benchmark/benchmark.h>

#include "figures.cpp"

using namespace std;

static void BM_Cout(benchmark::State& state) {
    std::cout.setstate(std::ios::failbit) ;

    for (const auto& s : state)
    {
        int perimeter = 2 * 3.14 * 5;
        std::cout << perimeter;
    }

    std::cout.clear() ;
}

static void BM_Figure(benchmark::State& state) {
    std::cout.setstate(std::ios::failbit) ;

    for (const auto& s : state)
    {
        figure test(circle);
        test.setR(5);
        cout << test.perimeter();
    }

    std::cout.clear() ;
}

static void BM_FigureInheritance(benchmark::State& state) {
    std::cout.setstate(std::ios::failbit) ;

    for (const auto& s : state)
    {
        Circle test(5);
        cout << test.perimeter();
    }

    std::cout.clear() ;
}

static void BM_FigureOverloaded(benchmark::State& state) {
    std::cout.setstate(std::ios::failbit) ;

    for (const auto& s : state)
    {
        circleStruct c;
        c.m_r=5;

        figureOverloadedConstructors test(c);
        cout << test.perimeter();
    }

    std::cout.clear() ;
}

BENCHMARK(BM_Cout);
BENCHMARK(BM_Figure);
BENCHMARK(BM_FigureInheritance);
BENCHMARK(BM_FigureOverloaded);

BENCHMARK_MAIN();

