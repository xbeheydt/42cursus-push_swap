# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap - Makefile                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 15:30:27 by xbeheydt          #+#    #+#              #
#    Updated: 2022/03/09 11:25:24 by xbeheydt         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re tests del-build

BUILD_DIR		?= $(PWD)/build
OBJ_DIR			?= ${BUILD_DIR}/obj
INCLUDE_DIR		?= ${BUILD_DIR}/include
LIB_DIR			?= ${BUILD_DIR}/lib
EXE_DIR			?= ${BUILD_DIR}/bin
SRC_DIR			= $(CURDIR)/src
HEADER_DIR		= $(CURDIR)/include
TEST_DIR		= $(CURDIR)/tests

NAME			= ${EXE_DIR}/push_swap
LIBFT			= ${LIB_DIR}/libft.a

HEADERS			= include/push_swap.h
INCLUDES		= $(addprefix ${INCLUDE_DIR}/, $(addsuffix .h, $(notdir $(basename ${HEADERS}))))
SRCS			= src/argparser.c \
				  src/push.c \
				  src/rev_rotate.c \
				  src/rotate.c \
				  src/stack.c \
				  src/stack_operations.c \
				  src/swap.c
SRCS_EXE		= ${SRCS} src/push_swap.c
OBJS 			= $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS_EXE)))))

SRCS_TEST		= $(wildcard ${TEST_DIR}/.*.c ${TEST_DIR}/*/.*.c)

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
ifdef DEBUG
	CFLAGS			+= -g3
endif
IFLAGS			= -I${INCLUDE_DIR}
IFLAGSTEST		= ${IFLAGS} -I${TEST_DIR}

VPATH			= $(sort $(dir $(SRCS)))

NORM			= norminette
RM				= rm -rf
MKDIR			= mkdir -p
CP				= cp

all: $(NAME)

$(NAME): ${LIBFT} ${INCLUDES} ${OBJS}
	$(MKDIR) ${EXE_DIR}
	@echo "push_swap test"
	$(CC) ${CFLAGS} ${IFLAGS} -L${LIB_DIR} ${OBJS} -o $@ -lft

$(OBJ_DIR)/%.o: %.c
	$(MKDIR) ${OBJ_DIR}
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

$(INCLUDE_DIR)/%: ${HEADER_DIR}/%
	$(MKDIR) ${INCLUDE_DIR}
	$(CP) $< $@

$(LIBFT):
	$(MAKE) -C libft

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
tests:
	@$(MKDIR) ${EXE_DIR}
	@$(CC) ${CFLAGS} ${IFLAGSTEST} -L${LIB_DIR} -o ${EXE_DIR}/tests ${SRCS} ${SRCS_TEST} -lft
	@echo "push_swap test"
	@echo "=============="
	@${EXE_DIR}/tests ${ARGS}