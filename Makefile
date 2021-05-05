CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = subject.o pc.o basic.o decorator.o human.o dwarf.o elves.o orc.o potion.o enemy.o vampire.o phoenix.o dragon.o merchant.o werewolf.o goblin.o troll.o map.o display.o cell.o main.o saitama.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k+

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencie
