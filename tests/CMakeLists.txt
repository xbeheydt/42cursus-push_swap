# CMakeList.txt : Sub-level CMake tests project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(
	HEADER_FILE_TESTS
	".tests.h"
) 
set(
	SOURCE_FILE_TESTS
	".tests.c"
	".test_main.c"
	".test_stack_handling.c"
	".test_stack_operations.c"
	".test_operations_frontend.c"
	".test_argparser.c"
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


# Create tests executable
add_executable(
	${PROJECT_NAME}-tests
	${HEADER_FILE_TESTS}
	${SOURCE_FILE_TESTS}
	${SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME}-tests libft)
target_include_directories(
	${PROJECT_NAME}-tests
	PRIVATE
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/tests"
	"${PORJECT_SOURCE_DIR}/libft/include"
)

# IDE tree view
source_group(
	"Header_Files"
	FILES ${HEADER_FILE_TESTS}
)

source_group(
	"Source_Files"
	FILES ${SOURCE_FILE_TESTS}
)

# tests section
#enable_testing()
add_test(test_stack_rotate ${PROJECT_NAME}-tests -t test_stack_rotate)
set_tests_properties(test_stack_rotate PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stack_rotate PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stack_rev_rotate ${PROJECT_NAME}-tests -t test_stack_rev_rotate)
set_tests_properties(test_stack_rev_rotate PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stack_rev_rotate PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stack_push ${PROJECT_NAME}-tests -t test_stack_push)
set_tests_properties(test_stack_push PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stack_push PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stack_swap ${PROJECT_NAME}-tests -t test_stack_swap)
set_tests_properties(test_stack_swap PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stack_swap PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stack_issorted ${PROJECT_NAME}-tests -t test_stack_issorted)
set_tests_properties(test_stack_issorted PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stack_issorted PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stacknew ${PROJECT_NAME}-tests -t test_stacknew)
set_tests_properties(test_stacknew PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stacknew PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stackadd_back ${PROJECT_NAME}-tests -t test_stackadd_back)
set_tests_properties(test_stackadd_back PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stackadd_back PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stackadd_front ${PROJECT_NAME}-tests -t test_stackadd_front)
set_tests_properties(test_stackadd_front PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stackadd_front PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_stackclear ${PROJECT_NAME}-tests -t test_stackclear)
set_tests_properties(test_stackclear PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_stackclear PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_argparser ${PROJECT_NAME}-tests -t test_argparser)
set_tests_properties(test_argparser PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_argparser PROPERTIES PASS_REGULAR_EXPRESSION "KO")

add_test(test_push ${PROJECT_NAME}-tests -t test_push)
set_tests_properties(test_push PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_push PROPERTIES PASS_REGULAR_EXPRESSION "KO")
