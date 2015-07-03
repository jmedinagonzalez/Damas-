# 
# Variables de Entorno
# Usadas principalmente para encontrar los comandos
# 
MKDIR=mkdir
CP=cp
GREP=grep
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

#
# Variables que definen las carpetas que deben usarse
# 
INSTALACION=dist
COMPILACION=build


#
# Variables del compilador (depende de cada uno)
# Para gcc
#
CFLAGS=-Wall -DDEBUG -g3

#
# Variables para g++
#
CCFLAGS=-Wall -DDEBUG -g3
CXXFLAGS=-Wall -DDEBUG -g3

#
# Variables para Fortran
#
FFLAGS=

#
# Variables para Asembler
#
ASFLAGS=

# 
# Variables usadas para enlazar el archivo ejecutable
#
LDLIBSOPTIONS=-lm

#
# Construcción del programa
# (Versión muy fácil)
#
${INSTALACION}/Cuadrado: 
	${MKDIR} -p ${COMPILACION}
	${MKDIR} -p ${INSTALACION}
	${CXX} -c Damas.cpp -o ${COMPILACION}/Damas.o
	${CXX} -o ${INSTALACION}/cuadrado ${COMPILACION}/Damas.o ${LDLIBSOPTIONS} 
	${RM} -fr ${COMPILACION}
	${RM} -fr core


# Limpiar instalación
clean:
	${RM} -fr ${COMPILACION}
	${RM} -fr ${INSTALACION}
	${RM} -fr salida.log
	${RM} -fr core
