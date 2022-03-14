# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (
	"42cursus-libft"
	VERSION 0.1.0
)

set(
	HEADER_FILES
	"include/libft.h"
	"include/get_next_line.h"
	"include/ft_printf.h"
) 
set(
	SOURCE_FILES
	"src/ft_atoi.c"
	"src/ft_bzero.c"
	"src/ft_calloc.c"
	"src/ft_isalnum.c"
	"src/ft_isalpha.c"
	"src/ft_isascii.c"
	"src/ft_isdigit.c"
	"src/ft_islower.c"
	"src/ft_isprint.c"
	"src/ft_isspace.c"
	"src/ft_isupper.c"
	"src/ft_itoa.c"
	"src/ft_lstadd_back.c"
	"src/ft_lstadd_front.c"
	"src/ft_lstclear.c"
	"src/ft_lstdelone.c"
	"src/ft_lstiter.c"
	"src/ft_lstlast.c"
	"src/ft_lstmap.c"
	"src/ft_lstnew.c"
	"src/ft_lstsize.c"
	"src/ft_lstpop_back.c"
	"src/ft_lstpop_front.c"
	"src/ft_memchr.c"
	"src/ft_memcmp.c"
	"src/ft_memcpy.c"
	"src/ft_memmove.c"
	"src/ft_memset.c"
	"src/ft_putchar_fd.c"
	"src/ft_putendl_fd.c"
	"src/ft_putnbr_fd.c"
	"src/ft_putstr_fd.c"
	"src/ft_split.c"
	"src/ft_strchr.c"
	"src/ft_strdup.c"
	"src/ft_striteri.c"
	"src/ft_strjoin.c"
	"src/ft_strlcat.c"
	"src/ft_strlcpy.c"
	"src/ft_strlen.c"
	"src/ft_strmapi.c"
	"src/ft_strncmp.c"
	"src/ft_strnstr.c"
	"src/ft_strrchr.c"
	"src/ft_strtrim.c"
	"src/ft_substr.c"
	"src/ft_tolower.c"
	"src/ft_toupper.c"
	"src/ft_isspace.c"
	"src/ft_putunbr_fd.c"
	"src/ft_puthnbr.c"
	"src/get_next_line/get_next_line.c"
	"src/get_next_line/get_next_line_utils.c"
	"src/ft_printf/core.c"
	"src/ft_printf/hexadecimal.c"
	"src/ft_printf/integer.c"
	"src/ft_printf/parser.c"
	"src/ft_printf/string.c"
	"src/ft_printf/utils.c"
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
if($ENV{BUFFER_SIZE})
	message("BUFFER_SIZE defined")
	add_compile_definitions(BUFFER_SIZE=$ENV{BUFFER_SIZE})
endif()

# Create static lib target
add_library(libft STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(
	libft
	PUBLIC
	"include"
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