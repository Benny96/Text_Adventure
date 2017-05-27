# Text Adventure

## Spanish:

Este proyecto consiste en un prototipo de **videojuego de aventuras de texto** que puede ser moldeable al gusto del consumidor.

Los integrantes del grupo somos los siguientes: <br>

Garikoitz Bereciartua (garibere13) <br>
Imanol Echeverría (Echever) <br>
y yo, Beñat Galdós (Benny96). <br>

Para que la aplicación ejecute correctamente, debemos hacer estas 2 compilaciones: <br>

<pre> gcc Persistencia/sqlite3.c Personaje.c -c </pre>
<pre> g++ main.cpp Personaje.o sqlite3.o Persistencia/DBConnector.cpp Enemigo.cpp clsPersonaje.cpp Persona.cpp -o main </pre>

En Linux (probado con Ubuntu v.16.0.4), los comandos a aplicar no varían mucho:

<pre> gcc Persistencia/sqlite3.c Personaje.c -c </pre>
<pre> g++ main.cpp Personaje.o sqlite3.o Persistencia/DBConnector.cpp Enemigo.cpp clsPersonaje.cpp Persona.cpp -o main - pthread -ldl </pre>

Decimos que es _moldeable_, ya que:

1) Si se modifica la constante **TABLERO**, definida en _PERSONAJE.H_.
2) Si se modifica el fichero **historia.txt**, añadiendo en el fichero de texto (sin los {}):
* {coord_x}
* {coord_y}
* {mensaje_en_dichas_coordenadas}

Se conseguirá ampliar o reducir (exceptuando un TABLERO 1X1, el cual no hemos cubierto en nuestro desarrollo por carecer de sentido) el espacio del juego.

Por ello, hay que recompilar la aplicación, y sería hasta recomendable borrar los ficheros que guardan datos en nuestra aplicación: **datos.bd** y **personajes.dat**, generados en la carpeta de nivel superior.

## English:

This project consists on a prototype for **Text Adventure** games, which can be altered on demand. 

It has been created by the following group: <br>

Garikoitz Bereciartua (garibere13) <br>
Imanol Echeverría (Echever) <br>
and me, Beñat Galdós (Benny96). <br>

To run the application correctly, we have to do 2 compilations: <br>

<pre> gcc Persistencia/sqlite3.c Personaje.c -c </pre>
<pre> g++ main.cpp Personaje.o sqlite3.o Persistencia/DBConnector.cpp Enemigo.cpp clsPersonaje.cpp Persona.cpp -o main </pre>

In Linux OS (tested with Ubuntu v.16.0.4), the commands to use don't differ too much:

<pre> gcc Persistencia/sqlite3.c Personaje.c -c </pre>
<pre> g++ main.cpp Personaje.o sqlite3.o Persistencia/DBConnector.cpp Enemigo.cpp clsPersonaje.cpp Persona.cpp -o main - pthread -ldl </pre>

This prototype can be _altered_:

1) If the constant **TABLERO**, defined in _PERSONAJE.H_ gets modified. This will define the X and Y maximum lengths of the board.
2) If we modify **historia.txt**, adding the following information (without the {}):
* {coord_x}
* {coord_y}
* {position_message}

So that we can extend or shorten (except TABLERO = 1, which we haven't considered in our development because of being nonsensical) the game board.

To do so, we have to recompile the application, and it would be advisable to remove the files that save the data of the application: **datos.bd** and **personajes.dat**, generated in the top-level folder.
