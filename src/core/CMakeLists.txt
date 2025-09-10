set(NAME core)

set(HEADERS
  Faces.hpp
  Edges.hpp
  Graph.hpp
  HalfEdges.hpp
  PolygonMesh.hpp
  PolygonMeshTest.hpp
) # HEADERS    

set(SOURCES
  Faces.cpp
  Edges.cpp
  Graph.cpp
  HalfEdges.cpp
  Partition.cpp
  PolygonMesh.cpp
  PolygonMeshTest.cpp
) # SOURCES

add_library(${NAME}
    ${HEADERS}
    ${SOURCES}
    ${FORMS}
    ${ASSETS}
) # add_library

target_compile_features(${NAME} PRIVATE cxx_lambdas)

target_link_libraries(${NAME} ${LIB_LIST})


