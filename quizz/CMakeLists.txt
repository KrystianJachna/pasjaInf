cmake_minimum_required(VERSION 3.23)
project(quizz)

set(CMAKE_CXX_STANDARD 14)

add_executable(quizz main.cpp cmake-build-debug/pytanie.cpp Pytanie/pytanie.cpp Pytanie/pytanie.h pytanie.cpp pytanie.h)
