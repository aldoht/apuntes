# Sistemas Inteligentes [Teo 1 - Viernes 13:10 - 15:20]
## Notas adicionales
### Forma de evaluación
- 3 evaluaciones teóricas (una por módulo, 20% cada una, a papel)
- Trabajo Final Práctico 40% (Informe, código y presentación) (2 a 3 integrantes)
	- ¿Cuál es el problema?
	- ¿Cómo lo resolvimos?
### Módulos
1. Machine Learning
	- Supervisado
		- Regresión
		- Clasificación
	- No Supervisado
		- Clustering
		- Principal Component Analysis
	- Evaluación de modelos
2. Redes Neuronales (Multi-Layer Perceptrons)
	- Perceptrón multicapa
	- Funciones de activación y backpropagation
	- Regularización y Optimización
3. Modelos de Lenguaje Extensos (LLM)
	- Fundamentos de Natural Language Processing y Transformers
	- Prompt Engineering y aplicaciones prácticas
	- Ética y uso responsable de la IA

## 2025-08-15 (Feriado, recuperado)
Aprendizaje supervisado -> Datos con etiquetas (ya damos el patrón).
Aprendizaje no supervisado -> "Aprende" patrones pero no identifica las clasificaciones por la falta de etiquetas.

### Tipos de problemas supervisados
**Regresión**
- Salida continua $$ y \in \mathbb{R} $$
- Predecir el precio de una casa o estimar una temperatura futura
- Predice un número
**Clasificación**
- Salida categórica $$ y \in \set{1, 2, 3, ..., k} $$
- Predice una clase
- Spam, enfermo/sano...

<div style="display: flex; justify-content: center; align-items: center;">
    <img style="width: 60%" src="./Pasted image 20250827164926.png">
</div>

La *regresión lineal* supone una relación unidimensional entre la variable dependiente y la independiente (una linea recta), su objetivo es predecir una variable continua a partir de una o más variables independientes.
$$ \hat{y} = \beta_{0} + \beta_{1}x_{1} + \beta_{2}x_{2} + ... + \beta_{p}x_{p} $$
El aprendizaje en este método consiste en encontrar los coeficientes B que minimicen el MSE (Mean Squared Error) entre las predicciones y los valores reales.
$$ MSE = \frac{1}{N}\sum_{i=1}^{N}{(y_{i}-\hat{y}_i)^2} $$
Se eleva al cuadrado porque si no se hace entonces los positivos se cancelarían con los negativos...

La *regresión polinomial* es un caso especial de la regresión lineal en el que los predictores se elevan a potencias (polinomios) para capturar relaciones no lineales entre la variable independiente y las variables dependientes.
$$ \hat{y} = \beta_{0} + \beta_{1}X + + \beta_{2}X^{2} + ... + \beta_{d}X^{d} $$
```python
# ============================================

# Clase 2 - Regresión Polinomial (Colab-ready)

# Ejemplo: Fertilizante (kg) -> Rendimiento (ton/ha)

# ============================================

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# 1) Datos (puedes cambiarlos y experimentar)
X = np.array([1, 2, 3, 4, 5, 6], dtype=float).reshape(-1, 1) # fertilizante (kg)
y = np.array([1.2, 1.9, 3.2, 3.8, 4.1, 4.2], dtype=float) # rendimiento (ton/ha)

# 2) Definir modelos: lineal, polinomial grado 2 y grado 3
models = {
	"Lineal (g=1)": Pipeline([
		("poly", PolynomialFeatures(degree=1, include_bias=False)),
		("linreg", LinearRegression())
	]),
	"Polinomial g=2": Pipeline([
		("poly", PolynomialFeatures(degree=2, include_bias=False)),
		("linreg", LinearRegression())
	]),
	"Polinomial g=3": Pipeline([
		("poly", PolynomialFeatures(degree=3, include_bias=False)),
		("linreg", LinearRegression())
	]),
}

# 3) Entrenar y evaluar
results = {}
for name, pipe in models.items():
	pipe.fit(X, y)
	y_hat = pipe.predict(X)
	rmse = np.sqrt(mean_squared_error(y, y_hat))
	r2 = r2_score(y, y_hat)
	results[name] = {
		"model": pipe,
		"rmse": rmse,
		"r2": r2
	}
	
	print(f"{name}: RMSE={rmse:.4f} | R²={r2:.4f}")

# 4) Mostrar coeficientes (para interpretación)
def pretty_coefs(pipe, name):
	# Obtiene coeficientes del modelo lineal dentro del pipeline
	lin = pipe.named_steps["linreg"]
	coefs = lin.coef_
	intercept = lin.intercept_
	
	print(f"\n{name} → Intercepto: {intercept:.4f}")
	
	for i, c in enumerate(coefs, start=1):
		print(f" beta_{i}: {c:.4f}")

for name, info in results.items():
	pretty_coefs(info["model"], name)

# 5) Curvas suaves para graficar
X_plot = np.linspace(X.min()-0.5, X.max()+0.5, 200).reshape(-1, 1)
y_lineal = results["Lineal (g=1)"]["model"].predict(X_plot)
y_poly2 = results["Polinomial g=2"]["model"].predict(X_plot)
y_poly3 = results["Polinomial g=3"]["model"].predict(X_plot)

# 6) Gráfico comparativo
plt.figure(figsize=(8,5))
plt.scatter(X, y, color="black", label="Datos reales")
plt.plot(X_plot, y_lineal, label=f"Lineal (R²={results['Lineal (g=1)']['r2']:.3f})", linewidth=2)
plt.plot(X_plot, y_poly2, label=f"Polinomial g=2 (R²={results['Polinomial g=2']['r2']:.3f})", linewidth=2)
plt.plot(X_plot, y_poly3, label=f"Polinomial g=3 (R²={results['Polinomial g=3']['r2']:.3f})", linewidth=2)

plt.title("Regresión lineal vs polinomial")
plt.xlabel("Fertilizante (kg)")
plt.ylabel("Rendimiento (ton/ha)")
plt.grid(True, alpha=0.25)
plt.legend()
plt.tight_layout()

plt.show()

# 7) Notas rápidas (texto en consola)
print("\nNotas:")
print("- Observa cómo el polinomio g=2 captura la curvatura (aumento inicial y estabilización).")
print("- El g=3 puede ajustarse aún más, pero ten cuidado con el sobreajuste si hubieran ruidos/datos extra.")
print("- En práctica, se debe validar el grado con validación cruzada y/o un set de validación separado.")
```

La *regresión logística* resuelve un problema de **clasificación** usando un método de regresión. Surge de que la regresión lineal no puede ser acotada. Esta regresión usa la función sigmoide que toma cualquier número real y lo convierte en un valor entre 0 y 1. Es bueno escalar los datos antes de aplicar la regresión logística.
$$ P(y=1|x) = \sigma(\beta_{0} + \beta_{1}x_{1} + \beta_{2}x_{2} + ... + \beta_{p}x_{p}) $$
$$ \sigma(z) = \frac{1}{1+e^{-z}} $$
Si P >= 0.5 entonces se clasifica como 1, si P<0.5 como 0. Mapeo.

**Métricas**
El *RMSE* (Root Mean Squared Error) mide el promedio de la magnitud de los errores entre las predicciones y los valores reales; además, está en las mismas unidades que la variable objetivo (+interpretación).
$$ RMSE = \sqrt{\frac{1}{N}\sum_{i=1}^{N}{(y_{i}-\hat{y}_i)^2}}  $$

El *R^{2}* (coeficiente de determinación) mide la proporción de la varianza de la variable dependiente explicada por el modelo. En el numerador está la suma de errores al cuadrado (SSE -> variación no explicada) y en el denominador es la suma total de cuadrados (SST -> variación total de los datos). Mientras más cerca al 1, es mejor.
$$ R2(y, \hat{y}) = 1 - \frac{\sum_{i=1}^{N} (y_i - \hat{y}_i)^2}{\sum_{i=1}^{N} (y_i - \bar{y})^2} $$

**Taller**
Observando la gráfica podemos concluir que un ajuste polinomial es mejor a uno lineal. También podemos notar que no hay tanta diferencia entre los rendimientos de los modelos polinomiales, sin embargo se puede sospechar de un *overfitting* conforme se incrementa el grado del polinomio pero no hay *underfitting* (por las métricas) para los grados 2 y 3. Habría que tener más datos o un conjunto de validación para demostrar estas conjeturas.

```md
Lineal: RMSE=4.8932, R2=0.6059
Polinomial g=2: RMSE=4.3572, R2=0.6876
Polinomial g=3: RMSE=4.3526, R2=0.6882

Lineal → Intercepto: 39.9359
 beta_1: -0.1578

Polinomial g=2 → Intercepto: 56.9001
 beta_1: -0.4662
 beta_2: 0.0012

Polinomial g=3 → Intercepto: 60.6848
 beta_1: -0.5689
 beta_2: 0.0021
 beta_3: -0.0000
```
<div style="display: flex; justify-content: center; align-items: center;">
    <img style="width: 60%" src="./grafica_hp_gpm.png">
</div>

## 2025-08-22
#### **Inteligencia - ¿Qué es?**
No hay un concenso para definir la *inteligencia humana* ya que no tiene una definición única.
Objeto de estudio: Machine Learning.
Los sistemas inteligentes son un conjunto de herramientas para resolver problemas pero no todos los problemas deben ser resueltos con inteligencia artificial.

Los algoritmos convencionales son finitos, deterministas y cerrados (ya que no son estocásticos, no tienen dinamismos, no son probabilísticos); estos se pueden asociar más a un árbol (kinda árbol de decisión).
#### ¿Qué define si un sistema puede ser de inteligencia artificial?
Los problemas de la vida real suelen ser dinámicos, si se tiene un problema determinista entonces el **ENTORNO NO CAMBIA** (por ejemplo en las rutas). Un sistema inteligente **IDENTIFICA EL ENTORNO Y TOMA UNA DECISIÓN**.

<div style="display: flex; justify-content: center; align-items: center;">
    <img style="width: 60%" src="./simple_sketch-8-22-2025_12-05-16_PM.jpg">
</div>

#### Características y áreas
La IA clásica está basada en reglas y lógica, mientras que los SI se basa en datos, patrones y predicciones. Los Sistemas Inteligentes tienen capacidad de aprendizaje, adaptabilidad, autonomía, generalización e interacción.

ML Supervisado y No Supervisado -> Fundamentales
NN incluyen MLP y DL -> Modelos ppotentes
LLM -> Revolución actual
Sistemas híbridos -> Combinación de reglas para mayor aprendizaje
#### ¿Qué es el Machine Learning?
- Aprendizaje automático
	- Permite que las máquinas aprendan y mejoren sin ser programadas explícitamente.
- Entrenamiento de modelos
	- Identifican patrones y los aplican a nuevos datos.
- Reconocimiento de imágenes

**LOS ALGORITMOS NO PIENSAN Y MUCHO MENOS TIENEN CONCIENCIA**; usan técnicas de predicción estadísticas.

"Nosotros traducimos el mundo a matrices y vectores" -> La máquina no ve, no escucha, no habla; la máquina sólo entiende vectores, matrices y tensores.

Algoritmos -> Pensar en matrices y vectores hace más óptimo todo.
#### Tipos de aprendizaje
- Supervisado
	- Datos etiquetados para entrenar
	- Tareas de clasificación
- No supervisado
	- Patrones en datos sin etiquetas
	- Agrupación, segmentación -> clustering
- Por refuerzo
	- Sistema de recompensas y retroalimentación
	- Se usa en robótica y juegos
#### Flujo de trabajo
1. Recolección y preparación de datos
	1. Recopilar
	2. Limpiar
2. Selección y entrenamiento de modelo
	1. Elección
	2. Entrenamiento
3. Evaluación y despliegue
	1. Uso de métricas
	2. Desplegue
#### Definiciones
- Sistemas Inteligentes
	- Sistema computacional capaz de percibir su entorno, procesar información y tomar decisiones autónomas (o semi) con el fin de resolver problemas.
	- Sistemas que buscan replicar procesos cognitivos en máquinas.
	- Aprenden de la experiencia a través de datos y mejoran su rendimiento con el tiempo.
- Determinista
	- Mismas entradas implica mismas salidas.
- Features
	- Atributos observados por el modelo relevantes para el análisis.
- Label
	- Valor objetivo que el modelo busca predecir.
- Estructura de dataset
	- En aprendizaje supervisado, el dataset contiene tanto los features como labels para entrenar modelos.

### Taller
**K-NEAREST NEIGHBOURS**
Primero se calcula la distancia del nuevo punto con respecto a los demás puntos en el espacio vectorial, luego se ordena la distancia de menor a mayor y finalmente se eligen los *k* puntos más cercanos para la clasificación del nuevo punto.
<div style="display: flex; justify-content: center; align-items: center;">
    <img style="width: 60%" src="./simple_sketch-8-22-2025_12-55-06_PM.jpg">
</div>

Accuracy: Comparación entre lo predicho y lo real.
El modelo KNN tiene 2 problemas principales:
1. El modelo no se auto-entrena porque el hiperparámetro *k* se le tiene que dar.
2. Es muy lento con demasiados datos porque tiene que hacer *n-1* cálculos por y para cada punto.

Actividad Final: https://colab.research.google.com/drive/1qKkQ27kTGw0JlJ_AXglPLya4cYh5lATM?usp=sharing

## 2025-05-09
Un **hiperplano óptimo** hace referencia a la recta que separa dos espacios (muetras) en 2 o más dimensiones.

#### Árboles de decisión (clasificación)
Tiene 3 tipos de nodos: raíz, intermedios y hojas; en el nodo raíz se ingresan los datos (input) para después irse filtrando mediante los nodos intermedios para llegar finalmente a un nodo hoja con una salida (output). Un **random forest** ocupa varios árboles de decisión.

Los *criterios de partición* se usan para decidir las divisiones que se usarán y el orden según una categoría o característica del conjunto de datos, así un dato seguirá un determinado camino según sus características.

#### Medidas de pureza
##### Entropía de Shannon
Mide la impureza o *desorden* de un conjunto $S$. Mide el orden de un conjunto y el desorden se sabe con respecto a la probabilidad de que salga un dato sobre otro. Cuando la mitad del conjunto es del tipo A y la otra mitad del tipo B (50% de obtener cualquier tipo), entonces se habla del mayor nivel de entropía. Este criterio siempre elige la **característica con menos entropía** (la entropía va de menos certidumbre a mayor certidumbre).
$$
H(S) = - \sum_{i=1}^{k}{p_{i}\log_{2}(p_i)}
$$
##### Ganancia de información
Mide la reducción de entropía después de dividir el conjunto según un atributo.
$$
IG(S, A) = H(S) - \sum_{v \in Values(A)}{\frac{|S_{v}|}{|S|}}H(S_{v})
$$
Donde $S_{v}$ es el subconjunto de datos donde el atributo $A$ toma el valor $v$. Un $IG$ alto implica que la división reduce mucho la incertidumbre (buena división), mientras que un valor bajo significa que no ayuda mucho a dividir las clases.
##### Índice Gini
Mide el nivel de entropía pero a una escala distinta.
$$
Gini(S) = 1 - \sum_{i=1}^{k}{{p_{i}}^2}
$$
##### Varianza reducida (para regresión)
Usa la varianza para buscar la calidad de la partición según el que tenga menor nivel de varianza.
$$
Var(S) = \frac{1}{|S|}\sum_{i=1}^{|S|}{(y_{i} - \bar{y})^{2}}
$$
Donde la métrica de división es la disminución de la varianza tras separar el nodo.

#### Máquinas de Soporte Vectorial (SVM)
El SVM es un algoritmo que busca los mejores planos (superplanos óptimos) para hacer la mejor clasificación. Se busca la **mejor recta** que separe los grupos.

El *truco de Kernel* amplia los conjuntos de datos con una nueva dimensión que sí permite un hiperplano claro, una recta.