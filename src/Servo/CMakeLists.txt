
add_library(ServoControl
	ServoControl.cc
	ServoControl.h
	${EXTRA_SRC}
)

target_link_libraries(ServoControl
	PUBLIC
		qgc
)

target_include_directories(ServoControl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

