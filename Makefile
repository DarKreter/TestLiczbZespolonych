
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test_arytm_zesp
	${TRGDIR}/test_arytm_zesp  latwy

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/Zespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o\
					 ${OBJ}/Statystyka.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/Zespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o

${OBJ}:
	mkdir ${OBJ}

main: src/main.cpp inc/Zespolona.hpp inc/BazaTestu.hpp
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

Zespolona: src/Zespolona.cpp inc/Zespolona.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Zespolona.o src/Zespolona.cpp

BazaTestu: src/BazaTestu.cpp inc/BazaTestu.hpp inc/WyrazenieZesp.hpp\
                       inc/Zespolona.hpp
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

WyrazenieZesp: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hpp\
                       inc/Zespolona.hpp
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o src/WyrazenieZesp.cpp

Statystyka: src/Statystyka.cpp inc/Statystyka.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Statystyka.o src/Statystyka.cpp



clear:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
