# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft - Makefile                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:30:27 by xbeheydt          #+#    #+#              #
#    Updated: 2022/03/09 11:25:24 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re tests ctest

BUILD_DIR		?= $(PWD)/build
OBJ_DIR			?= ${BUILD_DIR}/obj/libft
INCLUDE_DIR		?= ${BUILD_DIR}/include
LIB_DIR			?= ${BUILD_DIR}/lib
EXE_DIR			?= ${BUILD_DIR}/bin
SRC_DIR			= $(CURDIR)/src
HEADER_DIR		= $(CURDIR)/include
TEST_DIR		= $(CURDIR)/tests

NAME			= ${LIB_DIR}/libft.a

HEADERS			= libft/include/libft.h \
				  libft/include/get_next_line.h \
				  libft/include/ft_printf.h
INCLUDES		= $(addprefix ${INCLUDE_DIR}/, $(addsuffix .h, $(notdir $(basename ${HEADERS}))))
SRCS			= $(wildcard ${SRC_DIR}/ft_*.c ${SRC_DIR}/ft_printf/*.c ${SRC_DIR}/get_next_line/*.c)
OBJS 			= $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))

SRCS_TEST		= $(wildcard ${TEST_DIR}/.*.c ${TEST_DIR}/*/.*.c)

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
ifdef DEBUG
CFLAGS			+= -g3
endif
IFLAGS			= -I${HEADER_DIR}
IFLAGSTEST		= ${IFLAGS} -Isrc/ft_printf -Isrc/get_next_line -I${TEST_DIR}

VPATH			= $(sort $(dir $(SRCS)))

NORM			= norminette
RM				= rm -rf
MKDIR			= mkdir -p
CP				= cp

all: $(NAME) $(INCLUDES)

$(NAME): ${INCLUDES} ${OBJS}
	$(MKDIR) ${LIB_DIR}
	ar rcs $@ ${OBJS}
	ranlib $@

$(OBJ_DIR)/%.o: %.c
	$(MKDIR) ${OBJ_DIR}
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

$(INCLUDE_DIR)/%: ${HEADER_DIR}/%
	$(MKDIR) ${INCLUDE_DIR}
	$(CP) $< $@

norm:
	@$(NORM) ${HEADER_DIR} ${SRC_DIR}

clean:
	${RM} ${OBJS}

fclean: clean
	$(RM) ${NAME}
	$(RM) $(INCLUDES)
	$(RM) ${EXE_DIR}/tests

del-build:
	$(RM) ${BUILD_DIR}

re: fclean all

ARGS	?=
tests: $(NAME)
	@$(MKDIR) ${EXE_DIR}
	@$(CC) -w ${IFLAGSTEST} -L${LIB_DIR} -o ${EXE_DIR}/tests ${SRCS_TEST} -lft
	@echo "Libft test"
	@${EXE_DIR}/tests ${ARGS}

ctest:
	@$(MKDIR) build; cd build; cmake ..; make 42cursus-libft-tests; ctest $(ARGS)