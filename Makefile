
############################
#### PREAMBLE ##############
############################


# This makefile is fully optimized for a C project
# allowing you to do following things:
# - all:	assemble the entire project with the
#			eventual library
# - fclean:	remove your project's executable AND
#			object files
# - clean:  remove ONLY the object files, if any
# - re:		clean up and reassemble the project
#			from scratch
# - debug:	reassemble your entire project with
#			debug flag ('-g') and run GDB with custom
#			parameters sent to your program
#			(you can set custom arguments by modifying
#			the 'GDB_ARGV' variable)
# - __%_gc:	this one needs some extra explanation. When
#			you try to 'make __my_src_c' this makefile
#			will:
#				1.	compile all of your
#					source files into objects
#				2.	check for a file named 'my_src.c'
#					in your source folder
#				3.	check for a file named '__my_src.c'
#					in your tests folder
#				4.	recompile this precise source files
#					with coverage flags, without touching
#					the rest
#				5.	run the compiled unit test
#			So in the end, you compile your unit test
#			for the file 'my_src.c' if it's possible.
#			Therefore, if you want to use this ability,
#			you have to name your tests file as following:
#			'__%' where % is your original source file
#			name. Also, once unit tests launched, you can
#			analyze detailed coverage line by line
#			executing gcov (not gcovr)
# - __%:	same as previous, but without generating
#			coverage statistics
# - doc		this target calls doxygen inside of $(OXDOC_DIR)
# The only things that should be modified in this makefile
# are in the 'OPTIONS' and 'SOURCE FILES' sections.
# You have to enter all of your source files manually


############################
#### SUMMARY ###############
############################


# 1. Options
# 2. Source files
# 3. Compiler settings
# 4. Object files
# 5. Make recipies
# 6. File creation section
# 7. Pattern rules


############################
#### OPTIONS ###############
############################


TARGET_NAME			=	istl
SOURCE_DIR			=	sources
OBJECT_DIR			=	objects
HEADER_DIR			=	include
TESTS_DIR			=	tests
DEP_FILE			=	$(SOURCE_DIR)/Makefile.istl_sources
TARBALL				=	istl.tar.gz
GDB_ARGV			=


# Erasing all useless makefile built-in rules
# (needed to avoid automatic *.o build)
.SUFFIXES :

# Telling makefile not to erase *.d files
# automatically
.PRECIOUS : $(OBJECT_DIR)/%.d

vpath %.c $(SOURCE_DIR)
vpath %.c $(SOURCE_DIR)/istl


############################
#### SOURCE FILES ##########
############################


MAIN_SOURCE		=		main.c
STATIC_SOURCES		=		static_astar_1.c \
					static_astar_2.c \
					regex_const.c
SOURCES_LIST		=		list_1.c \
					list_2.c \
					list_3.c \
					list_4.c \
					list_5.c \
					vector_1.c \
					vector_2.c \
					vector_3.c \
					vector_4.c \
					vector_5.c \
					hash_table_1.c \
					hash_table_2.c \
					hash_table_3.c \
					hash_table_4.c \
					utility_1.c \
					utility_2.c \
					utility_3.c \
					utility_4.c \
					cubic_bezier.c \
					iterator_1.c \
					iterator_2.c \
					iterator_3.c \
					iterator_4.c \
					common_types_1.c \
					common_types_2.c \
					shared_ptr.c \
					weak_ptr.c \
					string_1.c \
					string_2.c \
					string_3.c \
					string_4.c \
					string_5.c \
					observable_1.c \
					astar_1.c \
					astar_2.c \
					astar_3.c \
					astar_4.c
LIBRARY			=


############################
#### COMPILER SETTINGS #####
############################


CC			=	gcc
C_FLAGS			=	-W -Wall -Wextra -Werror \
				-I$(HEADER_DIR) \
				-Wno-switch \
				-Wno-unused-variable \
				-Wno-unused-parameter \
				-Wno-unused-but-set-variable \
				-Wno-unused-but-set-parameter \
				-Wno-unused-function \
				$(C_FLAGS_INPUT)
L_FLAGS			=	$(L_FLAGS_INPUT)
COV_FLAGS		=	-fprofile-arcs -ftest-coverage
VALGRIND_FLAGS		=	--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--verbose \
				--log-file=valgrind-out.txt


############################
#### OBJECT FILES (auto) ###
############################


NON_M_OBJECTS		=	$(patsubst %.c,$(OBJECT_DIR)/%.o,$(SOURCES_LIST))
OBJECTS			=	$(NON_M_OBJECTS) $(patsubst %.c,$(OBJECT_DIR)/%.o,$(MAIN_SOURCE))


############################
#### RECIPE SECTION ########
############################


.PHONY: all directories re clean fclean debug


all: directories $(LIBRARY) $(TARGET_NAME)


debug:
	@make re C_FLAGS_INPUT=-g\ -g3 --no-print-directory
	@cgdb ./$(TARGET_NAME) -ex "break main" -ex "run $(GDB_ARGV)"

valgrind:
	@make re C_FLAGS_INPUT=-g\ -g3 --no-print-directory
	@valgrind $(VALGRIND_FLAGS) ./$(TARGET_NAME) $(VALGRIND_INJECT)


tarball: $(TARBALL)


directories: | $(SOURCE_DIR) $(OBJECT_DIR)


re:	clean all


clean:
	-@rm -rf ./$(OBJECT_DIR)/*.o
	-@rm -rf ./$(OBJECT_DIR)/*.dp
	-@rm -rf ./*.gc*
	-@rm -rf ./__*


fclean: clean
	-@rm -rf ./$(OBJECT_DIR)
	-@rm -f ./$(TARGET_NAME)
	-@rm -f ./$(TARBALL)
	-@rm -f ./$(DEP_FILE)


###############################
#### FILE CREATION SECTION ####
###############################


$(TARGET_NAME): $(OBJECTS)
	@$(CC) -o $(TARGET_NAME) $^ $(L_FLAGS)
	@echo -e "--- '\e[32mBUILD SUCCESSFULL\e[39m ---"


$(DEP_FILE): $(SOURCES_LIST)
	@echo -e "--- \e[32mCreating dependency file\e[39m : '\e[34m$@\e[39m' ---"
	@touch $(DEP_FILE) && echo "ISTL_DIR = istl" > $(DEP_FILE)
	@echo "ISTL_MODULE = $(SOURCES_LIST)" >> $(DEP_FILE)


$(TARBALL): $(DEP_FILE) $(SOURCES_LIST) $(STATIC_SOURCES) $(HEADER_DIR)
	@echo -e "--- \e[32mCreating ISTL tarball\e[39m : '\e[34m$@\e[39m' ---"
	@tar czf $(TARBALL) $^
	@echo -e "--- \e[32mDone\e[39m ---"


$(OBJECT_DIR):
	@mkdir -p $@


$(SOURCE_DIR):
	@echo "Error: source folder is not detected"


###############################
#### PATTERN RULES SECTION ####
###############################


__% : $(TESTS_DIR)/__%.c %.c $(NON_M_OBJECTS)
	@$(CC) -o __$* $(patsubst %$*.o,, $^) -lcriterion $(C_FLAGS) $(L_FLAGS)
	@./__$*


__%_gc : $(TESTS_DIR)/__%.c %.c $(NON_M_OBJECTS)
	@$(CC) -o __$* $(patsubst %$*.o,, $^) -lcriterion $(C_FLAGS) $(L_FLAGS) $(COV_FLAGS)
	@./__$* && gcov -k $*


$(OBJECT_DIR)/%.d : %.c
	@$(CC) -MT $(OBJECT_DIR)/$*.o -MM -MF $@ $< $(C_FLAGS)


$(OBJECT_DIR)/%.o : %.c $(OBJECT_DIR)/%.d
	@$(CC) -c -o $@ $< $(C_FLAGS)
	@echo -e "--- '\e[34m$@\e[39m'\t\e[32mSUCCESSFULLY COMPILED\e[39m ---"


$(OBJECT_DIR)/%_cov.o : %.c
	@$(CC) -c -o $@ $< $(C_FLAGS) $(COV_FLAGS)
	@echo -e "--- '\e[34m$@\e[39m'\t\e[32mSUCCESSFULLY COMPILED\e[39m ---"


__%.o : __%.c
	@$(CC) -c -o $(OBJECT_DIR)/$@ $< $(C_FLAGS) -lcriterion


include $(wildcard $(OBJECT_DIR)/*.d)
