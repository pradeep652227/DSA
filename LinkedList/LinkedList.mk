##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=LinkedList
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Pradeep/OneDrive/DSAMaster/DSAMaster
ProjectPath            :=C:/Users/Pradeep/OneDrive/DSAMaster/DSAMaster/LinkedList
IntermediateDirectory  :=../build-$(ConfigurationName)/LinkedList
OutDir                 :=../build-$(ConfigurationName)/LinkedList
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Pradeep
Date                   :=22/04/2023
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS := -std=c++17 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/LinkedList/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\LinkedList" mkdir "..\build-$(ConfigurationName)\LinkedList"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\LinkedList" mkdir "..\build-$(ConfigurationName)\LinkedList"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/LinkedList/.d:
	@if not exist "..\build-$(ConfigurationName)\LinkedList" mkdir "..\build-$(ConfigurationName)\LinkedList"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(ObjectSuffix): reverseInKGroups.cpp ../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Pradeep/OneDrive/DSAMaster/DSAMaster/LinkedList/reverseInKGroups.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/reverseInKGroups.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(DependSuffix): reverseInKGroups.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(DependSuffix) -MM reverseInKGroups.cpp

../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(PreprocessSuffix): reverseInKGroups.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/LinkedList/reverseInKGroups.cpp$(PreprocessSuffix) reverseInKGroups.cpp


-include ../build-$(ConfigurationName)/LinkedList//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


