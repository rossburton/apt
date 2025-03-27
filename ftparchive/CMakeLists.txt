include_directories(${BERKELEY_INCLUDE_DIRS})

set(sources apt-ftparchive.cc byhash.cc cachedb.cc cachedb.h contents.cc multicompress.cc override.cc sources.cc writer.cc apt-ftparchive.h byhash.h contents.h multicompress.h override.h sources.h writer.h)
add_executable(apt-ftparchive ${sources})

# Link the executables against the libraries
target_include_directories(apt-ftparchive PRIVATE ${BERKELEY_INCLUDE_DIRS})
target_link_libraries(apt-ftparchive apt-pkg apt-private ${BERKELEY_LIBRARIES})

# Install the executables
install(TARGETS apt-ftparchive RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
