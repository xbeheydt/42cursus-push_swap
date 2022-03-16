# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (
	"42cursus-push_swap"
	VERSION 0.1.0
)
enable_testing()

add_subdirectory(libft)
add_subdirectory(tests)

set(
	HEADER_FILES
	"${PROJECT_SOURCE_DIR}/include/push_swap.h"
) 
set(
	SOURCE_FILES
	"${PROJECT_SOURCE_DIR}/src/push_swap.c"
	"${PROJECT_SOURCE_DIR}/src/stack.c"
	"${PROJECT_SOURCE_DIR}/src/stack2.c"
	"${PROJECT_SOURCE_DIR}/src/stack3.c"
	"${PROJECT_SOURCE_DIR}/src/argparser.c"
	"${PROJECT_SOURCE_DIR}/src/push.c"
	"${PROJECT_SOURCE_DIR}/src/swap.c"
	"${PROJECT_SOURCE_DIR}/src/rotate.c"
	"${PROJECT_SOURCE_DIR}/src/rev_rotate.c"
	#"${PROJECT_SOURCE_DIR}/src/sort_engine.c"
)

# Create static lib target
add_library(libpush_swap STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(libpush_swap PRIVATE libft)
target_include_directories(
	libpush_swap
	PUBLIC
	"${PROJECT_SOURCE_DIR}/include"
)

# Create push_swap executable target
add_executable(push_swap ${HEADER_FILE_TESTS} ${SOURCE_FILES} "${PROJECT_SOURCE_DIR}/src/push_swap.c")
target_link_libraries(push_swap PRIVATE libft)
target_include_directories(
	push_swap
	PRIVATE
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/libft/include"
	"${PROJECT_SOURCE_DIR}/tests"
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
