CC=gcc
PREFIX=/usr/bin
COMMAND=append
all: prod

prod:
	${CC} ${COMMAND}.c -o ${COMMAND} 
dev:
	${CC} -O0 -g ${COMMAND}.c -o ${COMMAND} 
clean:
	rm -rf ${COMMAND} 
install: prod
	cp ${COMMAND} ${PREFIX}/${COMMAND}
