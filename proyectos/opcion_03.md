# Juego virtual "100 mexicanos dijeron"

- Crear clase CJugador
    - Nombre (con su respectivo set/get)
    - Puntaje actual
- Crear clase CEquipo:
    - Nombre del equipo(con su respectivo set/get)
    - Arreglo con arreglo de apuntadores a jugadores
    - Puntaje actual del equipo
- Crear clase CCarta con los siguientes elementos:
    - Tema/Categoria
    - Pregunta
    - Arreglo dinamico con pares `< respuesta, score >`
- Crear clase CJuego
    - Arreglo de CCarta que se leeran desde archivo/base de datos.
    - Apuntador a equipo 1
    - Apuntador a equipo 2
    - Puntaje equipo 1
    - Puntaje equipo 2
    - Contador de intentos fallidos
- Interfaz Grafica del Juego
    - Puede ir desde una simple interfaz en linea de comando a una interfaz usando Qt/Unity/Visual Studio
- Reconocedor de palabras parecidas(PUNTOS EXTRAS)
    - (Opción 1) Crear algoritmos para detectar sinonimos.
    - (Opción 2) Crear diccionario con palabras respuesta y sus sinonimos para almenos unas 30 preguntas, crear estructura de datos adecuada para realizar la comparación.


Proyecto para una persona extendible a dos dependiendo de la dificultad de que tan bien este implementado.