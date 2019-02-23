cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

#                 +--------------------------+
#                 |     stupid-calculator    |
#                 +--------------------------+
#                    |         |            |
#                    V         |            V
#             +---------+      |         +-------------+
#             | libmult |      |         | libsubtract |
#             +---------+      |         +-------------+
#                  |           V
#                  |        +--------+
#                  +------->| libadd |
#                           +--------+

project(testproject)

add_subdirectory(src/add)
add_subdirectory(src/mult)
add_subdirectory(src/subtract)
add_subdirectory(src/stupid-calculator)
