# print arbitrary variables with $ make print-<name>
print-%  : ; @echo $* = $($*)

UNAME_S = $(shell uname -s)

CC = clang++



INCFLAGS = -Ilibs/glm
INCFLAGS += -Ilibs/glfw/include
INCFLAGS += -Ilibs/spdlog/include

CCFLAGS  = -std=c++20 -O2 -g -Wall -Wextra -Wpedantic -Wno-c99-extensions
CCFLAGS += -Wno-unused-parameter
CCFLAGS += $(INCFLAGS)


LDFLAGS  = -lm
LDFLAGS += $(INCFLAGS)
LDFLAGs += libs/glm/build/glm/libglm.a
LDFLAGS += libs/glfw/src/libglfw3.a
LDFLAGS += libs/spdlog/libspdlog.a

# TODO: OSX specific
FRAMEWORKS	= -framework QuartzCore
FRAMEWORKS += -framework Cocoa
FRAMEWORKS += -framework Carbon
FRAMEWORKS += -framework Metal
FRAMEWORKS += -framework CoreFoundation
FRAMEWORKS += -framework IOKit


ifeq ($(UNAME_S), Darwin)
	LDFLAGS += $(FRAMEWORKS)
	# TODO: select based on ($ arch)
	BGFX_DEPS_TARGET=osx-arm64
BGFX_TARGET=osx-arm
endif

ifeq ($(UNAME_S), Linux)
	BGFX_TARGET=linux
endif

SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
BIN = bin





.PHONY: all clean

all: dirs libs build

libs:
	cd libs/glfw && bear -- cmake . && bear -- make

dirs:
	mkdir -p ./$(BIN)

# shader -> bin
run: build
	$(BIN)/game

build: $(OBJ)
	$(CC) -o $(BIN)/game $(filter %.o,$^) $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CCFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)
