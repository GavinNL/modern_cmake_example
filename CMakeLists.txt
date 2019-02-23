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

add_subdirectory(lib/add)
add_subdirectory(lib/mult)
add_subdirectory(lib/subtract)
add_subdirectory(bin/stupid-calculator)
