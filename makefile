CXX = g++
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g#

OBJS = inputValidation.o Menu.o Item.o List.o groceryListMain.o

SRCS = inputValidation.cpp Menu.cpp Item.cpp List.cpp groceryListMain.cpp

HEADERS = inputValidation.h Menu.h Item.h List.h

groceryList: ${OBJS} ${HEADERS}
		${CXX} ${OBJS} -o groceryList

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o groceryList	
