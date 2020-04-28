# Opción 1. Juego relacionado con mapas

Se debe construir un juego en el que intervengan patrullas de policía y un vehículo lleno de delincuentes, los cuales transitan por las calles de una ciudad  de Guadalajara(o cualquier ciudad cercana). Las patrullas tienen como objetivo desplazarse por sus zonas de influencia previamente determinadas, para detectar y atrapar delincuentes. Los delincuentes deben viajar desde una posición definida al inicio del juego y recorrer la ciudad hasta su guarida sin ser dados de baja o atrapados   por las patrullas, en ambos casos termina el juego.Las patrullas tienen autorización para abrir fuego a los delincuentes cuando los tienen a cierta distancia – esta es configurable – sin embargo a   medida que transitan en las vías, los delincuentes   también podrán encontrar escudos que les restauran en cierta cantidad la salud de su vehículo.

### Requerimientos. 

- Implementar el proyecto utilizando C++/C# como lenguaje de programación orientado a objetos. 
- Cargar el mapa de la ciudad desde archivos JSON, XML, KML, SHP.
- Todos los desplazamientos sobre el mapa deben ser animados gráficamente.
- Cuando una patrulla ha detectado a los delincuentes pero estos ya no están en su área de influencia, ésta debe comunicar por radio a las demás patrullas la última ubicación conocida de los delincuentes.
- Se deben tener dos modos de juego (Humano y Máquina).
- La policía puede bloquear caminos en tiempo de ejecución.
- En cualquier momento, los escudos pueden ponerse   en los caminos.
- El código deberá estar documentado.
- Se debe permitir en tiempo de ejecución, ubicar manualmente escudos de restauración para los delincuentes en las vías.
- Las rutas que siga el vehículo de los delincuentes deberán ser escogidas teniendo en cuenta los siguientes parámetros:
    - La ruta que más escudos de restauración pueda obtener el vehículob. 
    - La ruta más corta desde el origen hacia la guarida.
    - La   ruta   del   ladrón   avaricioso:   en   ésta   ruta   los ladrones   deben   conseguir   el   mayor   botín     recorriendo todos   los   bancos   antes   de   ser   capturados   o   haber llegado a la guarida (si llega a la guarida el botín se   multiplica   por   dos).   Ustedes   definen   las estrategias   (primero   a   los   bancos   más   cercanos   o primero a los bancos con mayor dinero o … etc)

### Consideraciones
- Las zonas de influencia de las patrullas la  definen la posición de las estaciones de policía.
- Para definir las zonas de influencia de las   patrullas se debe utilizar el algoritmo de Voronoi o el algoritmo de Delaunay, a elección del estudiante.
- Al inicio del juego se debe ubicar las   estaciones de policía en el mapa de la ciudad, así como el número de patrullas que hacen recorrido sobre el área de influencia
- Al inicio del juego se indica la ubicación de los bancos y el dinero que tienen guardado.
- Al inicio del juego se indica la ubicación de la guarida.
- Equipos de lo más dos estudiantes.
- Entrega de 1er parte  Jueves 25 de Junio

** Problema original en [universidad-de-caldas](https://www.studocu.com/es/document/universidad-de-caldas/estructuras-de-datos/trabajo-tutorial/proyecto-grafos-2017-2-estructura-de-datos/5181177/view)**