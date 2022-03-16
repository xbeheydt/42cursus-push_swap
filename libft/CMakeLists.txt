# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(NAME libft)

project (
	"42cursus-${NAME}"
	VERSION 0.1.0
)
enable_testing()

add_subdirectory(tests)

set(
	HEADER_FILES
	"${PROJECT_SOURCE_DIR}/include/libft.h"
	"${PROJECT_SOURCE_DIR}/include/get_next_line.h"
	"${PROJECT_SOURCE_DIR}/include/ft_printf.h"
) 
set(
	SOURCE_FILES
	"${PROJECT_SOURCE_DIR}/src/ft_atoi.c"
	"${PROJECT_SOURCE_DIR}/src/ft_bzero.c"
	"${PROJECT_SOURCE_DIR}/src/ft_calloc.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isalnum.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isalpha.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isascii.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isdigit.c"
	"${PROJECT_SOURCE_DIR}/src/ft_islower.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isprint.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isspace.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isupper.c"
	"${PROJECT_SOURCE_DIR}/src/ft_itoa.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstadd_back.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstadd_front.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstclear.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstdelone.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstiter.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstlast.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstmap.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstnew.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstsize.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstpop_front.c"
	"${PROJECT_SOURCE_DIR}/src/ft_lstpop_back.c"
	"${PROJECT_SOURCE_DIR}/src/ft_memchr.c"
	"${PROJECT_SOURCE_DIR}/src/ft_memcmp.c"
	"${PROJECT_SOURCE_DIR}/src/ft_memcpy.c"
	"${PROJECT_SOURCE_DIR}/src/ft_memmove.c"
	"${PROJECT_SOURCE_DIR}/src/ft_memset.c"
	"${PROJECT_SOURCE_DIR}/src/ft_putchar_fd.c"
	"${PROJECT_SOURCE_DIR}/src/ft_putendl_fd.c"
	"${PROJECT_SOURCE_DIR}/src/ft_putnbr_fd.c"
	"${PROJECT_SOURCE_DIR}/src/ft_putstr_fd.c"
	"${PROJECT_SOURCE_DIR}/src/ft_split.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strchr.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strdup.c"
	"${PROJECT_SOURCE_DIR}/src/ft_striteri.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strjoin.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strlcat.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strlcpy.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strlen.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strmapi.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strncmp.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strnstr.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strrchr.c"
	"${PROJECT_SOURCE_DIR}/src/ft_strtrim.c"
	"${PROJECT_SOURCE_DIR}/src/ft_substr.c"
	"${PROJECT_SOURCE_DIR}/src/ft_tolower.c"
	"${PROJECT_SOURCE_DIR}/src/ft_toupper.c"
	"${PROJECT_SOURCE_DIR}/src/ft_isspace.c"
	"${PROJECT_SOURCE_DIR}/src/ft_putunbr_fd.c"
	"${PROJECT_SOURCE_DIR}/src/ft_puthnbr.c"
	"${PROJECT_SOURCE_DIR}/src/get_next_line/get_next_line.c"
	"${PROJECT_SOURCE_DIR}/src/get_next_line/get_next_line_utils.c"
	"${PROJECT_SOURCE_DIR}/src/ft_printf/core.c"
	"${PROJECT_SOURCE_DIR}/src/ft_printf/hexadecimal.c"
	"${PROJECT_SOURCE_DIR}/src/ft_printf/integer.c"
	"${PROJECT_SOURCE_DIR}/src/ft_printf/parser.c"
	"${PROJECT_SOURCE_DIR}/src/ft_printf/string.c"
	"${PROJECT_SOURCE_DIR}/src/ft_printf/utils.c"
)

# Create static lib target
add_library(libft STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(
	libft
	PUBLIC
	"${PROJECT_SOURCE_DIR}/include"
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