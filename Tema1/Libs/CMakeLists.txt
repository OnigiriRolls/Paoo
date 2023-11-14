add_library(Character Character.cxx)
add_library(Player Player.cxx)
add_library(Enemy Enemy.cxx)
add_library(AWP AWP.cxx Gun.hpp)
add_library(MP9 MP9.cxx Gun.hpp)

target_include_directories(AWP
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(MP9
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

