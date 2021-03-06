file (GLOB_RECURSE TEST_SRC *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
set (TEST_BIN ${PROJECT_NAME}_test)
set (TEST_LIBS ${PROJECT_NAME})

# configure the executable
link_directories(${MAINFOLDER}/lib)
include_directories("${CATCH_DIR}/include")
add_executable(${TEST_BIN} ${TEST_SRC})
target_link_libraries(${TEST_BIN} ${TEST_LIBS} gcov)
add_executable(langevin_sim ${MAINFOLDER}/src/langevin_sim.cpp ${MAINFOLDER}/src/langevin.cpp)
#target_link_libraries(${PROJECT_NAME}_test)
#include_directories(${MAINFOLDER}/include ${MAINFOLDER}/src)

# configure unit tests via CTest
add_test(NAME AllTests COMMAND ${TEST_BIN} DEPENDS "${MAINFOLDER}/input.txt")
#add_test(NAME Coverage COMMAND ${TEST_BIN})

# run catch tests directly
file(GLOB TXT_FILES "${MAINFOLDER}/*.txt")
file(COPY ${TXT_FILES} DESTINATION "${MAINFOLDER}/build/test" )
file(COPY ${TXT_FILES} DESTINATION "${MAINFOLDER}/bin")
add_custom_target(catch "${MAINFOLDER}/bin/${TEST_BIN}" DEPENDS ${TEST_BIN} COMMENT "Executing unit tests..." VERBATIM SOURCES ${TEST_SRC} DEPENDS "${MAINFOLDER}/input.txt")
add_custom_target(coverage "${MAINFOLDER}/coverage.sh")
add_custom_target(run "${MAINFOLDER}/bin/langevin_sim" 
  DEPENDS "${MAINFOLDER}/input.txt"
  )

add_custom_target(sim "${MAINFOLDER}/.sim.sh" OUTPUT_QUIET )
#  PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${MAINFOLDER}/input.txt" "${MAINFOLDER}/bin/" 

if(EXISTS "${MAINFOLDER}/build/test/output.dat")
  file(COPY "${MAINFOLDER}/build/test/output.dat" DESTINATION "${MAINFOLDER}/build")
else()
   
endif()

#  POST_BUILD
# COMMAND ${CMAKE_COMMAND} -E copy "${MAINFOLDER}/build/test/output.dat" "${MAINFOLDER}/build")
