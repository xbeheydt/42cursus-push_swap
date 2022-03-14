# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (
	"42cursus-push_swap"
	VERSION 0.1.0
)

add_subdirectory(libft)

set(
	HEADER_FILES
	"include/push_swap.h"
) 
set(
	SOURCE_FILES
	"src/push_swap.c"
	"src/argparser.c"
	"src/stack.c"
	"src/stack_operations.c"
	"src/push.c"
	"src/swap.c"
	"src/rotate.c"
	"src/rev_rotate.c"
)
set(
	HEADER_FILE_TESTS
	"tests/.tests.h"
) 
set(
	SOURCE_FILE_TESTS
	"tests/.tests.c"
	"tests/.test_main.c"
	"tests/.test_stack_handling.c"
	"tests/.test_stack_operations.c"
	"tests/.test_operations_frontend.c"
	"tests/.test_argparser.c"
)

if($ENV{INTERNAL})
	message("INTERNAL defined")
	add_compile_definitions(INTERNAL=1)
endif()
if($ENV{MANDATORY})
	message("MANDATORY defined")
	add_compile_definitions(MANDATORY)
endif()
if($ENV{BONUS})
	message("BONUS defined")
	add_compile_definitions(BONUS=$ENV{BONUS})
endif()

# Create static lib target
add_library(libpush_swap STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(libpush_swap PRIVATE libft)
target_include_directories(
	libpush_swap
	PUBLIC
	"include"
)

# Create push_swap executable target
add_executable(push_swap ${HEADER_FILE_TESTS} ${SOURCE_FILES} "src/push_swap.c")
target_link_libraries(push_swap PRIVATE libft)
target_include_directories(
	push_swap
	PRIVATE
	"include"
	"libft/include"
	"tests"
)

# Create tests executable target
add_executable(tests ${HEADER_FILE_TESTS} ${SOURCE_FILE_TESTS})
target_link_libraries(tests PRIVATE libft libpush_swap)
target_include_directories(
	tests
	PRIVATE
	"include"
	"libft/include"
	"tests"
)

# IDE tree view
source_group(
	"Header_Files"
	FILES ${HEADER_FILES} ${HEADER_FILE_TESTS}
)

source_group(
	"Source_Files"
	FILES ${SOURCE_FILES} ${SOURCE_FILE_TESTS}
)
