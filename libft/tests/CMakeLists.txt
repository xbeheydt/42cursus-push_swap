# CMakeList.txt : Sub-level CMake tests project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(
	HEADER_FILE_TESTS
	"${PROJECT_SOURCE_DIR}/tests/.tests.h"
) 
set(
	SOURCE_FILE_TESTS
	"${PROJECT_SOURCE_DIR}/tests/.tests.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_main.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_atoi.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_bzero.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_calloc.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isalnum.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isalpha.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isascii.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isdigit.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_islower.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isprint.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isspace.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_isupper.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_itoa.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstadd_back.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstadd_front.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstclear.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstdelone.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstiter.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstlast.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstmap.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstnew.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstsize.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstpop_front.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_lstpop_back.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_memchr.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_memcmp.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_memcpy.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_memmove.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_memset.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_putchar_fd.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_putendl_fd.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_puthnbr_fd.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_putnbr.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_putstr_fd.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_putunbr_fd.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_split.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strchr.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strdup.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_striteri.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strjoin.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strlcat.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strlcpy.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strlen.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strmapi.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strncmp.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strnstr.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strrchr.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_strtrim.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_substr.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_tolower.c"
	"${PROJECT_SOURCE_DIR}/tests/.test_ft_toupper.c"
	"${PROJECT_SOURCE_DIR}/tests/get_next_line/.test_gnl_get_buffer.c"
	"${PROJECT_SOURCE_DIR}/tests/get_next_line/.test_gnl_clear_buffer.c"
	"${PROJECT_SOURCE_DIR}/tests/get_next_line/.test_gnl_get_line.c"
	"${PROJECT_SOURCE_DIR}/tests/get_next_line/.test_gnlt_line_realloc.c"
	"${PROJECT_SOURCE_DIR}/tests/get_next_line/.test_gnl_get_next_line.c"
	"${PROJECT_SOURCE_DIR}/tests/ft_printf/.test_ft_printf.c"
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
	"${PROJECT_SOURCE_DIR}/tests"
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/src/ft_printf"
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
add_test(test_libft_all ${PROJECT_NAME}-tests )
set_tests_properties(test_libft_all PROPERTIES WILL_FAIL TRUE)
set_tests_properties(test_libft_all PROPERTIES PASS_REGULAR_EXPRESSION "KO")
