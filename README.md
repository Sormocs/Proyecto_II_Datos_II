# Let´s play

Proyecto 2 del curso algoritmos y estructuras de datos 2.

Consiste en una aplicación donde se puede acceder a 2 video juegos, el primero BP Game el cual consiste en una especie de futbil y el segundo Generics Puzzle el cual consiste en un rompe cabezas el cual se genera a partir de una imagen ingresas por el usuario.

Para el desarrollo de las aplicaciones se utilizaron las biblbiotecas sfml para la parte de la interfaz gráfica, Json for modern desarrollada por Nlohmaan para realizar las comunicaciones entre sockets, <XML>.
  
Para el json basta con descargar el el archivo json.hpp de https://github.com/nlohmann/json/releases y adjuntarlo a los archivos de nuestro proyecto.
  
Para la descarga e instalación de sfml basta con seguir los pasos de la siguiente página, la cual es la documentación de dicha biblioteca, https://www.sfml-dev.org/tutorials/2.5/start-linux.php.
  
El xml se consigue del repositorio de https://github.com/leethomason/tinyxml2, el cual son un header y un cpp que facilitan la creacion de los XML para los proyectos personales, es de libre uso.
  
Para poder ejecutar correctamente la aplicación primero debemos ejecutar el servidor, el cual contiene toda la lógica de los algoritmos y LAS estructuras de datos desarrollas, posteriormente ejecutaremos el cliente, donde nos mostrará un menú con 2 opciones para ambos juegos, empezaremos por el primer juego.
  
BP Gamer:

Al principio nos aparecerá una pantalla para elegir la cantidad de jugadores y si queremos jugar contra otro jugador o contra la computadora, luego procedemos a entrar en la parte del juego, donde la pantalla cambiará a la pantalla de juego, donde estarían los jugadores, el balón y la cancha. El jugador que este en su turno podrá mover el balón, dandole una dirección y una potencia, al parar el balón, cambiará de turno, además se mostrará la ruta más corta entre el balón y la portería, luego de ello. Si estamos contra la computadora se realizará el tiro de la computadora automáticamente mostrando la primera ruta encontrada desde el balón hasta la porteria. El juego terminará cuando se llegue a la cantidad de goles anotados.
  
Generics Puzzle:
  
Al principio nos aparecerá una pantalla para elegir la imagen y la cantidad de partes en que se dividirá, luego se cambiará de pantalla donde aparecerá la imagen cortada y separda en cuadrados, ordenados aletatoriamente, donde el jugador deberá encontrar la solución. El juego terminará cuando termine de de armar la imagen.
