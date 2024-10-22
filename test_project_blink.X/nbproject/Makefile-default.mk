#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=config/Adc_Lcfg.c config/Gpio_Lcfg.c config/Spi.c src/gpio.c src/Adc.c src/Spi.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/config/Adc_Lcfg.p1 ${OBJECTDIR}/config/Gpio_Lcfg.p1 ${OBJECTDIR}/config/Spi.p1 ${OBJECTDIR}/src/gpio.p1 ${OBJECTDIR}/src/Adc.p1 ${OBJECTDIR}/src/Spi.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/config/Adc_Lcfg.p1.d ${OBJECTDIR}/config/Gpio_Lcfg.p1.d ${OBJECTDIR}/config/Spi.p1.d ${OBJECTDIR}/src/gpio.p1.d ${OBJECTDIR}/src/Adc.p1.d ${OBJECTDIR}/src/Spi.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/config/Adc_Lcfg.p1 ${OBJECTDIR}/config/Gpio_Lcfg.p1 ${OBJECTDIR}/config/Spi.p1 ${OBJECTDIR}/src/gpio.p1 ${OBJECTDIR}/src/Adc.p1 ${OBJECTDIR}/src/Spi.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=config/Adc_Lcfg.c config/Gpio_Lcfg.c config/Spi.c src/gpio.c src/Adc.c src/Spi.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=12F675
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/config/Adc_Lcfg.p1: config/Adc_Lcfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/config" 
	@${RM} ${OBJECTDIR}/config/Adc_Lcfg.p1.d 
	@${RM} ${OBJECTDIR}/config/Adc_Lcfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config/Adc_Lcfg.p1 config/Adc_Lcfg.c 
	@-${MV} ${OBJECTDIR}/config/Adc_Lcfg.d ${OBJECTDIR}/config/Adc_Lcfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config/Adc_Lcfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/config/Gpio_Lcfg.p1: config/Gpio_Lcfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/config" 
	@${RM} ${OBJECTDIR}/config/Gpio_Lcfg.p1.d 
	@${RM} ${OBJECTDIR}/config/Gpio_Lcfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config/Gpio_Lcfg.p1 config/Gpio_Lcfg.c 
	@-${MV} ${OBJECTDIR}/config/Gpio_Lcfg.d ${OBJECTDIR}/config/Gpio_Lcfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config/Gpio_Lcfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/config/Spi.p1: config/Spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/config" 
	@${RM} ${OBJECTDIR}/config/Spi.p1.d 
	@${RM} ${OBJECTDIR}/config/Spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config/Spi.p1 config/Spi.c 
	@-${MV} ${OBJECTDIR}/config/Spi.d ${OBJECTDIR}/config/Spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config/Spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/gpio.p1: src/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.p1.d 
	@${RM} ${OBJECTDIR}/src/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/src/gpio.p1 src/gpio.c 
	@-${MV} ${OBJECTDIR}/src/gpio.d ${OBJECTDIR}/src/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/Adc.p1: src/Adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Adc.p1.d 
	@${RM} ${OBJECTDIR}/src/Adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/src/Adc.p1 src/Adc.c 
	@-${MV} ${OBJECTDIR}/src/Adc.d ${OBJECTDIR}/src/Adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/Adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/Spi.p1: src/Spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Spi.p1.d 
	@${RM} ${OBJECTDIR}/src/Spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/src/Spi.p1 src/Spi.c 
	@-${MV} ${OBJECTDIR}/src/Spi.d ${OBJECTDIR}/src/Spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/Spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/config/Adc_Lcfg.p1: config/Adc_Lcfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/config" 
	@${RM} ${OBJECTDIR}/config/Adc_Lcfg.p1.d 
	@${RM} ${OBJECTDIR}/config/Adc_Lcfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config/Adc_Lcfg.p1 config/Adc_Lcfg.c 
	@-${MV} ${OBJECTDIR}/config/Adc_Lcfg.d ${OBJECTDIR}/config/Adc_Lcfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config/Adc_Lcfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/config/Gpio_Lcfg.p1: config/Gpio_Lcfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/config" 
	@${RM} ${OBJECTDIR}/config/Gpio_Lcfg.p1.d 
	@${RM} ${OBJECTDIR}/config/Gpio_Lcfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config/Gpio_Lcfg.p1 config/Gpio_Lcfg.c 
	@-${MV} ${OBJECTDIR}/config/Gpio_Lcfg.d ${OBJECTDIR}/config/Gpio_Lcfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config/Gpio_Lcfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/config/Spi.p1: config/Spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/config" 
	@${RM} ${OBJECTDIR}/config/Spi.p1.d 
	@${RM} ${OBJECTDIR}/config/Spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/config/Spi.p1 config/Spi.c 
	@-${MV} ${OBJECTDIR}/config/Spi.d ${OBJECTDIR}/config/Spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/config/Spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/gpio.p1: src/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.p1.d 
	@${RM} ${OBJECTDIR}/src/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/src/gpio.p1 src/gpio.c 
	@-${MV} ${OBJECTDIR}/src/gpio.d ${OBJECTDIR}/src/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/Adc.p1: src/Adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Adc.p1.d 
	@${RM} ${OBJECTDIR}/src/Adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/src/Adc.p1 src/Adc.c 
	@-${MV} ${OBJECTDIR}/src/Adc.d ${OBJECTDIR}/src/Adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/Adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/src/Spi.p1: src/Spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/Spi.p1.d 
	@${RM} ${OBJECTDIR}/src/Spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/src/Spi.p1 src/Spi.c 
	@-${MV} ${OBJECTDIR}/src/Spi.d ${OBJECTDIR}/src/Spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/src/Spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib -std=c90 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -v -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mno-default-config-bits -mc90lib -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/test_project_blink.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
