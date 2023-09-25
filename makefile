INCLUDE_FEC = -Ifec/
INCLUDE_LIBCORRECT = -Ilibcorrect/include/
INCLUDE_LIBCORRECT_CORRECT = -Ilibcorrect/include/correct/
INCLUDE_LIBCORRECT_CORRECT_REED_SOLOMON = -Ilibcorrect/include/correct/reed-solomon/
INCLUDE_LIBCORRECT_CORRECT_UTIL = -Ilibcorrect/include/correct/util/
INCLUDE_COMMON = -Icommon/

INCLUDES = ${INCLUDE_COMMON} ${INCLUDE_FEC} ${INCLUDE_LIBCORRECT} ${INCLUDE_LIBCORRECT_CORRECT} ${INCLUDE_LIBCORRECT_CORRECT_REED_SOLOMON} ${INCLUDE_LIBCORRECT_CORRECT_UTIL}

LIB_FEC = fec
LIB_LIBCORRECT = libcorrect/source/reed-solomon
LIB_SYS_HEAP = libcorrect/source/sys_heap.c

LIBS = ${LIB_FEC}/*.c ${LIB_LIBCORRECT}/*.c ${LIB_SYS_HEAP}

test: test.c ${LIBS}
	gcc test.c -o test ${INCLUDES} libs/*.o -g -O0

libs: ${LIBS}
	gcc -c ${LIBS} ${INCLUDES} -g -O0
	mv *.o libs/

PHONY: clean

clean:
	rm *.o