CXX	= g++
CFLAGS	= -c -g -std=c++11 -Wall
LDFLAGS	=

SOURCES	= main.cpp
SOURCES += unittest.cpp
SOURCES += genetic_settings.cpp
SOURCES += testindividual.cpp

SOURCES += individual/individual.cpp

SOURCES += dna/linear_binary_dna.cpp

SOURCES += parents_selection/panmixia.cpp
SOURCES += parents_selection/inbreeding_fenotype.cpp
SOURCES += parents_selection/inbreeding_genotype.cpp

SOURCES += new_generation_selection/elite.cpp
SOURCES += new_generation_selection/truncation.cpp

SOURCES += recombination/discrete.cpp

SOURCES += mutation/binary_dna_mutation.cpp

SOURCES += test_calculator.cpp

OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(SOURCES)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
