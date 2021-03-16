
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test_arytm_zesp
	#${TRGDIR}/test_arytm_zesp  latwy

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/Zespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/Zespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Zespolona.hpp inc/BazaTestu.hpp
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Zespolona.o: src/Zespolona.cpp inc/Zespolona.hpp
	g++ -c ${FLAGS} -o ${OBJ}/Zespolona.o src/Zespolona.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hpp inc/WyrazenieZesp.hpp\
                       inc/Zespolona.hpp
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hpp\
                       inc/Zespolona.hpp
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o src/WyrazenieZesp.cpp




clear:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
