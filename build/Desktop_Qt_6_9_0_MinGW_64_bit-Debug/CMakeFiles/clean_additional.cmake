# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BusinessLogic\\BusinessLogic_autogen"
  "BusinessLogic\\CMakeFiles\\BusinessLogic_autogen.dir\\AutogenUsed.txt"
  "BusinessLogic\\CMakeFiles\\BusinessLogic_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\project_rpg_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\project_rpg_autogen.dir\\ParseCache.txt"
  "project_rpg_autogen"
  )
endif()
