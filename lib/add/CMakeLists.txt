cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)


################################################################################
# Edit these
################################################################################
# Project name. This is the
project(add)

SET (HEADER_FILES
               include/add/add.h
     )

SET(SOURCE_FILES
            src/add.cpp
  )

SET(INCLUDE_FOLDERS
           include/add
   )

SET(PUBLIC_LINKED_TARGETS
       # This library does not publically link with anything else
   )

SET(PRIVATE_LINKED_TARGETS
       # This library does not privately link with anything else.
    )
################################################################################



################################################################################
#
#  DO NOT EDIT ANYTHING BELOW THIS.
#
################################################################################



################################################################################
# Create the library. Do not edit this
################################################################################
add_library(  ${PROJECT_NAME}   ${SOURCE_FILES}   )

# Create an ALIAS for this library. All other
# libraries that list this as a dependency should
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

# Set the target link properties.
target_link_libraries( ${PROJECT_NAME}  PUBLIC  ${PUBLIC_LINKED_TARGETS})
target_link_libraries( ${PROJECT_NAME}  PRIVATE ${PRIVATE_LINKED_TARGETS})

################################################################################




################################################################################
# Properties for this project only.
################################################################################
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

################################################################################


target_include_directories( ${PROJECT_NAME}
                            PUBLIC
                                 ${INCLUDE_FOLDERS})


# Set the install targets.
install( TARGETS  ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets
         LIBRARY  DESTINATION lib
         ARCHIVE  DESTINATION lib
         RUNTIME  DESTINATION bin
         )

install(DIRECTORY
           "${CMAKE_CURRENT_LIST_DIR}/include"
           "${CMAKE_CURRENT_BINARY_DIR}/include"
           DESTINATION .
         FILES_MATCHING PATTERN "*.h")
###################################################
