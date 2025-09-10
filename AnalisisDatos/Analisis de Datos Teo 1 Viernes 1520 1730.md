# Análisis de Datos [Teo 1 - Viernes 15:20 - 17:30]
## Notas adicionales
- Temario
	1. Análisis Estadístico Unidimensional
	2. Análisis de Regresión Lineal
	3. Métodos de clasificación y agrupamiento
- Evaluaciones
	- Taller individual (tarea) - 30% - 5/sept
	- Taller grupal (caso) - 20% - 10/oct
	- Prueba de desarrollo - 20% - 14/nov
	- Exposición - 25% - 28/nov
	- Autoevaluación - 5% - 28/nov
## 2025-08-22
"Mucha información en colores y un par de ejes"

El análisis de datos puede definirse como un proceso intrincado y multifacético que implica la aplicación sistemática y rigurosa de técnicas matemático-estadísticas, algoritmos computacionales, y metodologías cuantitativas y cualitativas, con el fin de descomponer, examinar y transformar conjuntos de datos, frecuentemente vastos y heterogéneos, en representaciones más manejables y estructuradas, permitiendo así la extracción de información significativa, la identificación de patrones y correlaciones, y la derivación de inferencias que sustenten la toma de decisiones informadas en contextos diversos, ya sean académicos, científicos, industriales o comerciales, siempre teniendo en cuenta las limitaciones inherentes a los datos, la complejidad de los modelos analíticos, y las posibles implicaciones éticas y operativas de las conclusiones obtenidas y bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla

Nuestro cerebro tiene mecanismos para detectar patrones en el mundo que nos rodea; nos ayudan a identificar regularidades y relaciones en los estímulos sensoriales (como reconocer rostros) -> Pareidolia: fenómeno psicológico que implica la percepción de patrones en *estímulos aleatorios o vagos* -> Apofenia: fenómeno psicológico que refiere a la tendencia general de personas a encontrar patrones o conexiones significativos en datos o estímulos aleatorios o sin relación.

La **correlación** indica qué tan fuerte y en qué dirección dos variables están relacionadas, si una cambia ¿cómo cambia la otra?

En el análisis de datos es esencial combinar herramientas estadísticas con el criterio experto:
- Herramientas estadísticas
	- Precisión, reducción de sesgos, cuantificación de incertidumbre.
- Criterio experto
	- Interpretación de resultados en su contexto.

El **CRISP-DM** es una metodología usada para guiar el proceso de análisis y minería de datos: flexible y estructurado.
1. Comprensión del Problema de Negocio
2. Comprensión de los Datos
3. Selección y Preparación de los Datos
4. Modelado de Datos
5. Evaluación
6. Visualización
7. Toma de Decisiones

Leer **Storytelling with Data**.

## 2025-08-29
**Criterio propio** acompañado de herramientas estadísticas. Visión atemperada como expertos.
Los gráficos deben ser sencillos de entender.

#### Combinación de conjuntos de datos de dos o más archivos distintos
Merge (Unión completa) -> FULL OUTER JOIN (SQL)
Join interno -> INNER JOIN (SQL)
Join externo -> LEFT OUTER JOIN, RIGHT OUTER JOIN, FULL OUTER JOIN (SQL)

Tradeoff: ¿Qué tanto problema es tener datos nulos al hacer una unión?

#### Selección de subconjuntos de datos
¿Cómo filtraré los datos? -> Muestras
Ventajas de usar subconjuntos:
- Reducción de complejidad (menos datos)
- Enfoque específico (sin datos irrelevantos)
- Mayor interpretabilidad (contexto definido)

#### Creación, eliminación y transformación de variables
Variables nuevas más valiosas que cualquier columna (i.e. KDA)
Estandarización: Los datos tendrán una media de 0 y desviación estándar de 1, útil cuando las variables tienen distintas unidades y se desean comparar -> Ley de los grandes números
Siempre hay que considerar la *temporalidad* de los datos para tener decisiones más precisas.

Dato mata relato (es cine).

## 2025-09-05

#### Valores nulos
Examen sin nombre, el profesor tiene 3 opciones:
- Eliminarlo y perder la información
- Asignar un nombre al azar
- *Imputar* el dato buscando el nombre en base a pistas (como el tipo de letra)

#### Francis Galton
Se le recuerda especialmente por dos aportes claves en el análisis de datos:
- La regresión a la media
- El diagrama de Galton o gráfico de dispersión
##### Regresión a la media
Observó que cuando se mide (por ejemplo) la altura, los hijos tienden a estar más cerca del promedio de la población que los padres extremos -> Los hijos serán altos pero no tan altos como los padres
##### Outliers
Observó que algunos individuos tenían características que se **desviaban significativamente de la media** -> *datos atípicos*.
Las observaciones pueden deberse a:
- Errores de medición
- Condiciones experimentales inusuales
- Representar fenómenos raros pero significativos
###### Tratamiento
Nota: Solo hacer 1 vez el ajuste de outliers a la media, si siguen habiendo outliers vives con ello
##### Boxplots
Este gráfico es muy común para identificar outliers, muestra la distribución de los datos basándose en cuartiles y destaca explícitamente

OneHotEncoding -> Problema de la dimensionalidad (relacionar con curse of dimensionality)

Nota: revisar cursos aula virtual