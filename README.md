** pdg2025-fcen-uba-TP-2 **
** 2025 Procesamiento de Geometría Digital (Digital Geometry Processing) **

Los archivos están organizados como en la Tarea 1 y el proceso de
compilación es el mismo.

Antes de compilar la aplicación por primera vez, edite el archivo
src/gui/GuiStrings.hpp o cópielo de la Tarea 1.

Se incluyen instrucciones adicionales como comentarios en los archivos
fuente.

El Trabajo Practico 2 tiene tres tareas

Tarea 1)

- Use la aplicación de línea de comandos test/dgpTest2a.cpp para esta
  tarea. Tenga en cuenta que test/CMakeLists ahora define tres
  aplicaciones de línea de comandos diferentes.

- Extienda LoaderStl y SaverStl para que admitan archivos STL
  binarios. Las partes binarias ya están implementadas. Solo necesita
  copiar y pegar, y probablemente reformatear, parte del código que
  escribió en la Tarea 1.

- Agregue compatibilidad con archivos PLY registrando LoaderPly y
  SaverPly en las fábricas de cargadores y guardadores. Tenga en
  cuenta que, además de LoaderPly y SaverPly, se incluyen dos clases
  nuevas en la carpeta wrl: Ply e IndexedFaceSetPly. No todos los
  objetos geométricos que se pueden describir en archivos PLY se
  pueden representar como IndexedFaceSets. La implementación actual es
  una solución intermedia. La discutiremos en clase.

- Descargue el archivo data-A2.zip del sitio del curso, expándalo a la
  carpeta data-A2 y utilice los archivos de datos de esta carpeta para
  verificar que puede cargar y guardar archivos en cualquiera de los
  formatos de archivo compatibles, en ASCII o BINARIO.

- En el archivo test/dgpTest2a.cpp, utilizando la clase
  SceneGraphTraversal, localice todos los nodos IndexedFaceSet
  contenidos en el gráfico de escena. Para cada archivo encontrado,
  imprima información descriptiva en el formato especificado
  utilizando la función de utilidad definida en los archivos
  dgpPrt.hpp y dgpPrt.cpp.

- Compile la aplicación interactiva y verifique que pueda cargar y
  visualizar todos los archivos contenidos en los archivos data-A1.zip
  y data-A2.zip.

- Busque más archivos PLY y STL en línea y verifique que pueda
  cargarlos en la aplicación.

- Actualmente no es posible especificar formatos de salida
  binarios. Modificaremos la interfaz gráfica de usuario para que esta
  variable sea visible en el futuro. Los formatos ASCII son los
  predeterminados. Mientras tanto, verifique que pueda guardar las
  mallas en formato WRL, STL (ASCII) y PLY (ASCII).

Tarea 2)

- Utilice la aplicación de línea de comandos test/dgpTest2b.cpp para
  esta tarea.

- Cargue un archivo compatible.

- Usando la clase SceneGraphTraversal, localice todos los nodos de
  IndexedFaceSet. Para cada nodo de IndexedFaceSet, elimine las
  normales, los colores y/o las coordenadas de textura, como se
  especifica en la línea de comandos.

- Guarde el gráfico de escena resultante en el formato de archivo de
  salida especificado.  Imprima información.

- Esta operación es importante porque los algoritmos que cambian la
  conectividad de una malla también deben modificar las propiedades
  asociadas para mantener la consistencia de los datos. Al comenzar a
  implementar uno de estos algoritmos, siempre es útil eliminar todas
  las propiedades hasta completar la implementación solo en la
  conectividad y la geometría. En una segunda fase, el algoritmo puede
  extender las propiedades una a una.

Tarea 3)

- Utilice la aplicación de línea de comandos test/dgpTest2c.cpp para
  esta tarea.

- Complete la implementación de las clases HalfEdges, PolygonMesh y
  PolygonMeshTest.

- Encontrará instrucciones adicionales para completar esta tarea en
  los encabezados y archivos fuente.

Información adicional:

- Copie la implementación de la clase Faces de la Tarea 1 a la Tarea
  2.

- En la carpeta test, todos los archivos son nuevos.

- En la carpeta core encontrará implementaciones completas de las
  clases Edges, Graph y Partition.

- Las clases HalfEdges, PolygonMesh y PolygonMeshTest están
  parcialmente implementadas y debe completar la implementación.

Envío:

a) Localiza y elimina los archivos temporales creados por tu editor.
b) Elimina el contenido de los subdirectorios superiores bin y build.
c) Elimina el archivo qt/DGP2025-A2.pro.user creado por QtCreator.
d) Elimina el directorio principal de build creado por QtCreator.
e) Confirma todos tus cambios periódicamente y en los hitos.
f) Sube tus confirmaciones a tu repositorio de GitHub.
g) Sigue las instrucciones de envío de tareas en GitHub Classroom y
   envía la tarea antes de la fecha límite.
