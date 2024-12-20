cmake_minimum_required(VERSION 3.16)

project(Reversalusinglinkedlist LANGUAGES C)

add_executable(Reversalusinglinkedlist main.c)

include(GNUInstallDirs)
install(TARGETS Reversalusinglinkedlist
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
