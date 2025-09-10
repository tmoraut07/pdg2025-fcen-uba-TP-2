set(NAME io)

set(HEADERS
  AppLoader.hpp
  AppSaver.hpp
  StrException.hpp
  Loader.hpp
  LoaderPly.hpp
  LoaderStl.hpp
  LoaderWrl.hpp
  Saver.hpp
  SaverPly.hpp
  SaverStl.hpp
  SaverWrl.hpp
  Tokenizer.hpp
  TokenizerFile.hpp
  TokenizerString.hpp
) # HEADERS    

set(SOURCES
  AppLoader.cpp
  AppSaver.cpp
  LoaderPly.cpp
  LoaderStl.cpp
  LoaderWrl.cpp
  SaverPly.cpp
  SaverStl.cpp
  SaverWrl.cpp
  Tokenizer.cpp
  TokenizerFile.cpp
  TokenizerString.cpp
) # SOURCES

add_library(${NAME}
    ${HEADERS}
    ${SOURCES}
) # add_library

target_compile_features(${NAME} PRIVATE cxx_lambdas)

target_link_libraries(${NAME} ${LIB_LIST})

