set(sources apt-ftparchive.cc byhash.cc contents.cc multicompress.cc override.cc sources.cc writer.cc apt-ftparchive.h byhash.h contents.h multicompress.h override.h sources.h writer.h)
add_executable(apt-ftparchive ${sources})

# Link the executables against the libraries
target_link_libraries(apt-ftparchive apt-pkg apt-private)

if (BERKELEY_FOUND)
  list(APPEND sources cachedb.cc cachedb.h)
  target_include_directories(apt-ftparchive PRIVATE ${BERKELEY_INCLUDE_DIRS})
  target_link_libraries(apt-ftparchive ${BERKELEY_LIBRARIES})
else()
  list(APPEND sources cachedb-stub.h)
endif()

# Install the executables
install(TARGETS apt-ftparchive RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
