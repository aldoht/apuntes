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

## 2025-09-26

Si no hay jerarquía y son muchas clases...
Frequency encoding: crea una columna que combina columnas categóricas, luego se reemplazan los valores combinados por la frecuencia de la clase.

### Gráficos de dispersión

Representa la relación entre dos variables.
Funciona para identificar relaciones (cómo cambia una variable en función de la otra) y detectar patrones (o incluso outliers).
Las variables no siempre cambian de forma independiente; a veces sus variaciones están relacionadas (positiva o negativamente) -> covarianza: medida que indica la dirección de la relación linea entre dos variables.

### Covarianza

Calcula cómo varían conjuntamente dos variables alrededor de sus medias.
- Si $cov(x,y) \gt 0$, cuando $x$ aumenta, $y$ tiende a disminuir.
- Si $cov(x,y) \lt 0$, cuando $x$ disminuye, $y$ tiende a aumentar.
- Si $cov(x,y) \approx 0$, no hay relación lineal clara.
Sin embargo, **la magnitud de la covarianza no dice nada**.

### Correlación de Pearson

Normaliza la covarianza dividiéndola por las desviaciones estándar de cada variable.
- Si $r=1$ hay una relación perfectamente positiva.
- Si $r=-1$ hay una relación perfectamente negativa.
- Si $r=0$ no hay una relación lineal.

Además, hay otros tipos de correlación como el *rho de Spearman* y la *Tau de Kendall*.

### Correlación y causalidad

**La correlación no implica causalidad**.
La *correlación* es una medida de la relación entre dos variables.
La *causalidad* indica que un cambio en una variable directamente provoca un cambio en otra. Para establecer causalidad se necesitan cumplir tres criterios:
- Temporalidad
	- La causa debe preceder al efecto.
- Covariación
	- Las variables deben estar correlacionadas.
- Eliminación de alternativas
	- No deben existir otras variables que expliquen la relación observada.

## 2025-10-02

IA --> Area de la informatica que busca que las maquinas puedan realizar tareas que requieren inteligencia humana, como la toma de decisiones o la comunicacion en lenguaje natural.

ML --> Rama de la IA que se enfoca en que los sistemas aprendan patrones a partir de datos.
- Regresion
- Clasificacion
- Clustering

DL --> Subconjunto del ML que usa ANN con muchas capas, imitando de forma simple el como funcionan las neuronas humanas.

Generative IA --> Crea contenido nuevo que no existia antes.

### Regresion lineal simple

Queremos trazar una linea recta que explique como cambia Y cuando cambia X (Y=mX+b).
Para encontrar esta recta se usa un metodo llamado OLS (Ordinary Least Squares):
- La idea es ajustar la recta para que la diferencia entre los valores reales y los predichos sea la mas pequeña posible.
- Se minimiza la **suma de los cuadrados de los errores**.

**Modelo**
$$
Y_{i} = \beta_0 + \beta_1X_i + \epsilon_i
$$
**Estimación**
$$
\hat{Y}_i = b_0 + b_1X_i
$$

El numerador de $b_1$ mide la covarianza entre X y Y (como se mueven juntas); el denominador mide la varianza de X (que tanto se dispersa). Esto es la tasa de cambio promedio de Y cuando X cambia en una unidad. El $b_0$ es la media de Y menos $b_1$ por la media de X.

**Error**
$$
e_i = Y_i - \hat{Y}_i
$$

El metodo OLS busca valores de $b_0$ y $b_1$ que minimicen la suma de los ${e_i}^2$.

### Métricas de evaluación en regresión

1. MSE
	- Promedio de errores al cuadrado.
2. RMSE
	- Misma idea que el MSE pero con las mismas unidades de Y.
3. MAE
	- Promedio de la magnitud de los errores sin importar el signo, mas robusto que el MSE frente a errores grandes.
4. $R^2$
	- Proporción de variabilidad de Y que el modelo explica con X.

### Separación del dataset

Se separa en train (70%-80%) y test (20%-30%), con el train entrenamos el modelo y con test lo probamos. Logramos lo siguiente:
- Detectamos el sobreajuste.
- Verificamos la generalización del modelo.

## 2025-10-10

### Ética en el análisis de datos

¿Es ético analizar información sin consentimiento de las personas?

### Sesgos

Los *sesgos de percepción* son como trampas mentales que pueden hacer que interpretemos la información de manera incorrecta. A veces inconscientemente nuestro cerebro nos lleva a ver las cosas de una manera que no es del todo objetiva o precisa.

**Sesgo de confirmación** --> Solo escuchas lo que quieres oir.
**Sesgo de disponibilidad** --> Basamos nuestras decisiones en lo que mas facil recordamos.
**Sesgo de autoridad** --> Tendencia natural de las personas a confiar en figuras de autoridad.
**Sesgo de anclaje** --> Te aferras a la primera impresion o dato que recibes.

Algoritmos que predicen y muestran contenido que es probable que interese o con el que interactues (basado en tu comportamiento anterior), llevando a una *cámara de eco* donde los usuarios solo ven y consumen ideas que refuerzan sus creencias existentes --> *polarización social*.

### Principios de Visualización de Edward Tufte

1. Evitar el desorden. Elimina todos los elementos gráficos que no contribuyan directamente a la comprensión del contenido.
2. Muestra comparaciones.
3. Pensar en los gráficos al pasarlos a tinta: ¿es un desperdicio?
4. Integridad. Los gráficos deben representar los datos de forma precisa y sin distorsión.
5. Integración de texto y gráficos.
6. Contexto para la interpretación.

### Business Intelligence

Tecnologías, aplicaciones y prácticas que se utilizan para recolectar, integrar, analizar y presentar datos de manera que apoyen la toma de decisiones en una organización.
- Integración de datos.
- Análisis de datos.
- Visualización de datos
- Reporting (informes).
- Toma de decisiones.

### Proceso de creación de gráficos efectivos

1. Comunicación inicial con el cliente
	- ¿Objetivo principal?
	- ¿Público objetivo?
	- ¿Qué decisiones espera el cliente?
	- ¿Requisitos específicos?
2. Recopilación y comprensión de datos
	- Análisis preliminar.
3. Planificación y diseño inicial
	- Crear un plan y diseño inicial.
	- Selección de gráficos.
	- Borradores.
4. Feedback del cliente y revisión
	- Presentación del borrador.
	- Revisión del feedback.
5. Desarrollo de iteraciones
	- Crear varias versiones del gráfico.
	- Verificación de datos.
6. Detalles finales y diseño estético
	- Estética y claridad.
	- Revisión de coherencia.
7. Presentación y ajustes finales
	- Presentación final.
	- Realizar ajustes finales.
8. Entrega y seguimiento
	- Proporcionar el gráfico.
	- Ofrecer soporte adicional.