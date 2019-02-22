cmake_minimum_required(VERSION 3.8.0)

project(testproject)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)


#stupid-calculator +----> libadd
#                  |        ^
#                  |        |
#                  |        |
#                  +----> libmult
#                  +----> libsubtract


####################################################
# Add a library
####################################################
add_library( add
             src/add/add.cpp 
             include/add/add.h
            )

# Create an ALIAS for this library. All other
# libraries that list this as a dependency should 
add_library(add::add ALIAS add)


target_include_directories( add 
                            PUBLIC
                               include/add)


target_include_directories(add 
                             INTERFACE
                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/add>  
                                $<INSTALL_INTERFACE:include/>  # <prefix>/include/mylib
)


#install(DIRECTORY include/add DESTINATION include/add
#        FILES_MATCHING PATTERN "*.h")

install( TARGETS  add EXPORT addTargets
         LIBRARY  DESTINATION lib
         ARCHIVE  DESTINATION lib
         RUNTIME  DESTINATION bin
         INCLUDES DESTINATION include
         )

install(EXPORT addTargets
        FILE addTargets.cmake
        NAMESPACE add::
        DESTINATION lib/cmake/add)
###################################################



####################################################
# Add another library that links to add:add
####################################################
add_library( mult 
             src/mult/mult.cpp 
            )
# Create an ALIAS for this library. All other
# libraries that list this as a dependency should 
add_library(mult::mult ALIAS mult)

target_include_directories( mult 
                            PUBLIC
                                include/mult)

# Tell the mult library that we will be using the add::add library
# this will automatically set the proper include paths:
#   ie: -I"include/add" because that path was set as  PUBLIC include directory
#       in add::add
target_link_libraries( mult  PUBLIC add::add)

####################################################


####################################################
# Add another library that links to add:add
####################################################
add_library( subtract 
             src/subtract/subtract.cpp 
            )
# Create an ALIAS for this library. All other
# libraries that list this as a dependency should 
add_library(subtract::subtract ALIAS subtract)

target_include_directories( subtract 
                            PUBLIC
                                include/subtract)
####################################################




####################################################
# Add another library that links to add:add
####################################################
add_executable( stupid-calculator
             src/stupid-calculator/stupid-calculator.cpp 
            )

# Tell the mult library that we will be using the add::add library
# this will automatically set the proper include paths:
#   ie: -I"include/add" because that path was set as  PUBLIC include directory
#       in add::add
target_link_libraries( stupid-calculator  PUBLIC mult::mult  subtract::subtract)
####################################################

