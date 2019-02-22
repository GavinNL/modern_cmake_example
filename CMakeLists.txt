cmake_minimum_required(VERSION 3.8.0)

project(testproject)

#  stupid-calculator +----> libadd
#                    |        ^
#                    |        |
#                    |        |
#                    +----> libmult
#                    +----> libsubtract


####################################################
# Create a library which performs additions.
####################################################
add_library( add
             src/add/add.cpp
             include/add/add.h   # Is this necessary?
            )

# Create an ALIAS for this library. All other
# libraries that list this as a dependency should
add_library(add::add ALIAS add)


target_include_directories( add
                            PUBLIC
                               include/add)

# When `cmake --build . --target install` is called, install:
#  *.so/*.a     -> $CMAKE_INSTALL_PREFIX/lib
#  executables  -> $CMAKE_INSTALL_PREFIX/bin
#  *.h          -> $CMAKE_INSTALL_PREFIX/include   (NOT WORKING)
install( TARGETS  add EXPORT addTargets
         LIBRARY  DESTINATION lib
         ARCHIVE  DESTINATION lib
         RUNTIME  DESTINATION bin
         INCLUDES DESTINATION include
         )
###################################################



####################################################
# The Multiply library which links to the Add library.
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
# The Subtraction Library
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
