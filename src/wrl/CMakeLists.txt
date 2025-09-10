set(NAME wrl)

set(HEADERS
  Node.hpp
  SceneGraph.hpp
  SceneGraphTraversal.hpp
  SceneGraphProcessor.hpp
  Group.hpp
  Transform.hpp
  Rotation.hpp
  Shape.hpp
  Appearance.hpp
  Material.hpp
  PixelTexture.hpp
  ImageTexture.hpp
  IndexedLineSet.hpp
  IndexedFaceSet.hpp
  Ply.hpp
  IndexedFaceSetPly.hpp
) # HEADERS    

set(SOURCES
  Node.cpp
  SceneGraph.cpp
  SceneGraphTraversal.cpp
  SceneGraphProcessor.cpp
  Group.cpp
  Transform.cpp
  Rotation.cpp
  Shape.cpp
  Appearance.cpp
  Material.cpp
  PixelTexture.cpp
  ImageTexture.cpp
  IndexedLineSet.cpp
  IndexedFaceSet.cpp
  Ply.cpp
  IndexedFaceSetPly.cpp
) # SOURCES

add_library(${NAME}
    ${HEADERS}
    ${SOURCES}
) # add_library

target_compile_features(${NAME} PRIVATE cxx_lambdas)

target_link_libraries(${NAME} ${LIB_LIST})

