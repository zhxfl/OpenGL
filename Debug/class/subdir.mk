################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../class/Test_1.cpp \
../class/Test_2.cpp \
../class/Test_3.cpp \
../class/Test_4.cpp \
../class/Test_5.cpp \
../class/Test_6.cpp \
../class/Test_8_light.cpp 

OBJS += \
./class/Test_1.o \
./class/Test_2.o \
./class/Test_3.o \
./class/Test_4.o \
./class/Test_5.o \
./class/Test_6.o \
./class/Test_8_light.o 

CPP_DEPS += \
./class/Test_1.d \
./class/Test_2.d \
./class/Test_3.d \
./class/Test_4.d \
./class/Test_5.d \
./class/Test_6.d \
./class/Test_8_light.d 


# Each subdirectory must supply rules for building sources it contributes
class/%.o: ../class/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


