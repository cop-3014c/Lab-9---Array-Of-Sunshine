HEADERS       := statistics.h
IMPLEMS       := statistics.cpp
OUT           := statistics
TEST          := statistics_test.cpp
TEST_OUT      := statistics_test
DRIVER        := main.cpp

FILES         := $(DRIVER) $(IMPLEMS) $(HEADERS) $(TEST)
OUTS          := $(OUT) $(TEST_OUT)
GTEST         := googletest
FLAGS         := -Wall -Werror -Wno-unused-function

.PHONY: format build test all clean

all: format build test

format:
	@echo "\n========================\nFormatting files\n========================\n"
	@clang-format $(FILES) -i -style=google -verbose
	@echo "\n========================\nFormatting complete\n========================\n"

build: $(DRIVER) $(IMPLEMS) $(HEADERS)
	@echo "\n========================\nCompiling program\n========================\n"
	@g++ -std=c++17 $(DRIVER) $(IMPLEMS) $(FLAGS) -o $(OUT)
	@echo "========================\nCompilation complete\nRun your code with ./$(OUT)\n========================\n"

test: $(TEST) $(IMPLEMS) $(HEADERS)
	@echo "\n========================\nRunning tests\n========================\n"
	@g++ -std=c++17 $(TEST) $(IMPLEMS) $(GTEST)/libgtest.a $(GTEST)/libgtest_main.a -isystem $(GTEST)/include -pthread -Wno-unused-result -o $(TEST_OUT)
	@./$(TEST_OUT)
	@echo "\n========================\nTests complete\n========================\n"

clean:
	@rm -f $(OUTS)