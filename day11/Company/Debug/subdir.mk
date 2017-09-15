################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Boss.cpp \
../Company.cpp \
../DataSet.cpp \
../Employee.cpp \
../FileOpe.cpp \
../SaleManager.cpp \
../SalePartTime.cpp \
../TecManager.cpp \
../TecPartTime.cpp \
../main.cpp 

OBJS += \
./Boss.o \
./Company.o \
./DataSet.o \
./Employee.o \
./FileOpe.o \
./SaleManager.o \
./SalePartTime.o \
./TecManager.o \
./TecPartTime.o \
./main.o 

CPP_DEPS += \
./Boss.d \
./Company.d \
./DataSet.d \
./Employee.d \
./FileOpe.d \
./SaleManager.d \
./SalePartTime.d \
./TecManager.d \
./TecPartTime.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


