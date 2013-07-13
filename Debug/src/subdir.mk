################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Test.cpp \
../src/procedure_obj_builder.cpp \
../src/rules_content_handler.cpp 

OBJS += \
./src/Test.o \
./src/procedure_obj_builder.o \
./src/rules_content_handler.o 

CPP_DEPS += \
./src/Test.d \
./src/procedure_obj_builder.d \
./src/rules_content_handler.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/gbraxton/workspace/CCGSS/cute" -I/home/gbraxton/xerces-c-3.1.1/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


