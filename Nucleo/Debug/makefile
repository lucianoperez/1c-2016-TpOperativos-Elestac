################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/lib/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Nucleo

dependents:
	-cd /home/utnso/tp-2016-1c-Cazadores-de-cucos/utilidades/Debug && $(MAKE) all

# Tool invocations
Nucleo: $(OBJS) $(USER_OBJS) /home/utnso/tp-2016-1c-Cazadores-de-cucos/utilidades/Debug/libutilidades.so
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/utnso/tp-2016-1c-Cazadores-de-cucos/utilidades/Debug" -o "Nucleo" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Nucleo
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/utnso/tp-2016-1c-Cazadores-de-cucos/utilidades/Debug/libutilidades.so:

-include ../makefile.targets
