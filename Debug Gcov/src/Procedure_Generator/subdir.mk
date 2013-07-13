################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Procedure_Generator/boolean_object_component.cpp \
../src/Procedure_Generator/cards_object_component.cpp \
../src/Procedure_Generator/deck_device_component.cpp \
../src/Procedure_Generator/device_game_entity.cpp \
../src/Procedure_Generator/evaluator_game_entity.cpp \
../src/Procedure_Generator/game_entity.cpp \
../src/Procedure_Generator/game_entity_component.cpp \
../src/Procedure_Generator/game_entity_factory.cpp \
../src/Procedure_Generator/object_game_entity.cpp \
../src/Procedure_Generator/procedure_game_entity.cpp \
../src/Procedure_Generator/rules_content_handler.cpp \
../src/Procedure_Generator/simulation_package_builder.cpp \
../src/Procedure_Generator/simulation_package_object.cpp \
../src/Procedure_Generator/value_object_component.cpp 

OBJS += \
./src/Procedure_Generator/boolean_object_component.o \
./src/Procedure_Generator/cards_object_component.o \
./src/Procedure_Generator/deck_device_component.o \
./src/Procedure_Generator/device_game_entity.o \
./src/Procedure_Generator/evaluator_game_entity.o \
./src/Procedure_Generator/game_entity.o \
./src/Procedure_Generator/game_entity_component.o \
./src/Procedure_Generator/game_entity_factory.o \
./src/Procedure_Generator/object_game_entity.o \
./src/Procedure_Generator/procedure_game_entity.o \
./src/Procedure_Generator/rules_content_handler.o \
./src/Procedure_Generator/simulation_package_builder.o \
./src/Procedure_Generator/simulation_package_object.o \
./src/Procedure_Generator/value_object_component.o 

CPP_DEPS += \
./src/Procedure_Generator/boolean_object_component.d \
./src/Procedure_Generator/cards_object_component.d \
./src/Procedure_Generator/deck_device_component.d \
./src/Procedure_Generator/device_game_entity.d \
./src/Procedure_Generator/evaluator_game_entity.d \
./src/Procedure_Generator/game_entity.d \
./src/Procedure_Generator/game_entity_component.d \
./src/Procedure_Generator/game_entity_factory.d \
./src/Procedure_Generator/object_game_entity.d \
./src/Procedure_Generator/procedure_game_entity.d \
./src/Procedure_Generator/rules_content_handler.d \
./src/Procedure_Generator/simulation_package_builder.d \
./src/Procedure_Generator/simulation_package_object.d \
./src/Procedure_Generator/value_object_component.d 


# Each subdirectory must supply rules for building sources it contributes
src/Procedure_Generator/%.o: ../src/Procedure_Generator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/gbraxton/workspace/CCGSS/cute" -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -fprofile-arcs -ftest-coverage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


