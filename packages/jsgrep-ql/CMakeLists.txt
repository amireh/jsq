# embed jsgrep-ql
ADD_CUSTOM_COMMAND(
  OUTPUT ${CMAKE_BINARY_DIR}/jsgrep-ql.cpp
  # references:
  # - https://stackoverflow.com/questions/13660850/is-it-possible-to-store-binary-files-inside-an-exe
  # - https://stackoverflow.com/questions/4864866/c-c-with-gcc-statically-add-resource-files-to-executable-library
  # - https://stackoverflow.com/questions/5316152/store-data-in-executable
  COMMAND xxd -i -u jsgrep-ql.js ${CMAKE_BINARY_DIR}/jsgrep-ql.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/dist/jsgrep-ql.js
  COMMENT "Generating jsgrep-ql.cpp"
)

ADD_LIBRARY(jsgrep-ql STATIC ${CMAKE_BINARY_DIR}/jsgrep-ql.cpp)
