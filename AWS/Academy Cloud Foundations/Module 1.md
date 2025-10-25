## Intro

**Temas**
- Introducción a la informática en la nube
- Ventajas de la informática en la nube
- Introducción a Amazon Web Services (AWS)
- Marco de adopción de la nube de AWS (CAF de AWS)

## Sección 1

Cloud computing -> Using another computer to process information

La informática en la nube es la entrega bajo demanda de potencia de cómputo, bases de datos, almacenamiento, aplicaciones y otros recursos a través de internet con un sistema de precios de pago por uso. Se ejecuta en servidores desplegados por todo el mundo.

La informática en la nube permite dejar de considerar la infraestructura como *hardware* y en cambio verla (y usarla) como *software*.

#### Modelo de informática tradicional -> Infraestructura como hardware

Las soluciones de hardware:
- Requieren espacio, personal dedicado, planificación e inversión.
- Tienen un ciclo largo de adquisición de hardware (no montas un servidor de un día para otro).
- Exigen aprovisionar capacidad según los picos máximos teóricos
	- Si es más potente que los picos máximos -> Invertiste en cosas que no rinden beneficios (al menos momentáneamente)
	- Si es menos potente que los picos máximos -> Los clientes no recibirán el servicio que necesitan.
- Es débil frente a cambios (podría decirse que difícil de escalar) ya que requieres tiempo, esfuerzo y dinero para implementar una nueva solución.

#### Modelo de informática en la nube -> Infraestructura como software

Las soluciones de software:
- Son flexibles (permiten seleccionar los servicios necesarios y usarlos según su demanda).
	- Los recursos pueden ser tratados como temporales y desechables.
- Pueden cambiar de forma más rápida, sencilla y rentable.
- Eliminan tareas pesadas innecesarias.
	- Aprovisionamiento, mantenimiento, planificación de capacidad...
- Solo pagas por lo que usas y cuando lo usas.

#### Modelos de servicio en la nube

Hay tres modelos principales:
1. IaaS (Infraestructure as a Service)
	- Por lo general proporciona acceso a las características de redes, equipos (virtuales o dedicados), almacenamiento.
	- Mayor flexibilidad y control sobre los recursos de TI.
	- Similar a las implementaciones ya existentes.
2. PaaS (Platform as a Service)
	- Elimina la necesidad de administrar la infraestructura subyacente (hardware y SO) ya que es automatizado.
	- Permite centrarse en la implementación y administración de las aplicaciones en lugar de su aprovisionamiento.
3. SaaS (Software as a Service)
	- Proporciona un producto completo que el proveedor del servicio ejecuta y administra.
	- En la mayoría de los casos, el SaaS son las aplicaciones de usuario final.
	- No se piensa en el mantenimiento del servicio ni cómo administrar la infraestructura.
	- Solo se piensa en cómo usar ese software en particular.
	- Un ejemplo común es una aplicación de email en la web con la que puedes enviar y recibir emails sin administrar el servidor, ni el producto, ni mantener el SO del sistema.

![[Pasted image 20250829105417.png]]

#### Modelos de implementación de informática en la nube

Hay tres modelos principales de implementación de informática en la nube. Cada uno representa el entorno en la nube en el que se pueden implementar las aplicaciones.
1. Nube -> "Todo en la nube"
	- Aplicación totalmente implementada en la nube.
	- Todas las partes de la aplicación son ejecutadas en la nube.
	- La aplicación *existe en la nube*.
2. Híbrido
	- Se conecta la infraestructura y las aplicaciones existentes a los recursos basados en la nube.
	- La aplicación existe en sus instalaciones físicas.
	- La implementación híbrida más común es entre la infraestructura de la nube y la de las instalaciones.
	- Hace crecer la implementación a la vez que conecta recursos en la nube a sistemas internos.
3. Infraestructura local (nube privada)
	- Implementación en las instalaciones.
	- Uso de herramientas de administración de recursos y virtualización (nube privada).
	- A veces se utiliza por su capacidad de proporcionar recursos dedicados.
	- Es como usar los sistemas "antiguos" a la vez que se utilizan tecnologías de administración de aplicaciones y virtualización para incrementar el uso de recursos.

![[Pasted image 20250829110619.png]]

#### Similitudes entre AWS y TI tradicional

![[Pasted image 20250829111732.png]]

## Sección 2

### Ventajas de la informatica en la nube

1. Sustituir inversion de capital por gastos variables (pagas por lo que usas)
2. Adaptarse rapidamente a las necesidades de las aplicaciones
3. Bajos precios en AWS
4. Evitar asumir estimaciones sobre capacidad
5. Aumenta la velocidad y agilidad al obtener recursos
6. Menos dinero en la ejecucion y mantenimiento de datacenters --> Mas dinero para proyectos
7. Escala mundial facilmente

## Seccion 3

### Introduccion a AWS

Un servicio web es una aplicacion que se provee a traves de internet usando un formato estandar para la entrada y salida de datos (xml, json) para la interaccion con el servidor a traves de una API.

AWS es una plataforma en la nube que ofrece varios productos globales basados en la nube, proporciona acceso bajo demanda a recursos informaticos (almacenamiento, red, bdd, etc); ofrece flexibilidad y solo se paga por lo consumido. 

**Son como bloques que se arman juntos para proporcionar soluciones y que despues pueden ser ajustados.**

Hay distintas categorias para los servicios que proporciona AWS, la seleccion depende de los objetivos empresariales y requisitos tecnologicos.

#### Formas de interactuar con AWS

1. Consola de administracion de AWS usando un navegador
2. AWS CLI permite acceso a los servicios mediante scripts y comandos
3. SDK permite acceso a los servicios directamente desde el codigo (como Java, Python, etc)

Todas funcionan como una REST API.

## Seccion 4

### Migracion a la nube de AWS - Marco de adopcion de la nube (CAF de AWS)

Personas, procesos y tecnologias deben estar en la misma pagina. Los lideres en tecnologia deben comprender estas tres cosas:
1. El estado actual de la organizacion
2. El estado objetivo de la organizacion
3. La transicion necesaria para lograr el estado objetivo

El CAF de AWS ofrece orientacion y buenas practicas a fin de ayudar a las organizaciones a crear un enfoque para la informatica en la nube para acelerar la adopcion satisfactoria de la nube. El CAF se organiza en seis perspectivas, y estas se componen en capacidades (responsabilidades, que areas requieren atencion?):
1. Enfoque en capacidades empresariales
	1. Negocio
		- Asegurarse de que los objetivos empresariales se alinean con sus estrategias y objetivos de TI.
		- Finanzas de TI
		- Estrategia de TI
		- Realizacion de beneficios
		- Administracion de riesgos empresariales
	2. Gente
		- Evaluar las estructuras y roles de la organizacion para identificar areas de oportunidad, ayudando a generar cambios en la organizacion para hacerla mas agil.
		- Administracion de recursos
		- Administracion de incentivos
		- Administracion de la carrera profesional
		- Administracion de la formacion tecnica
		- Administracion de los cambios en la organizacion
	3. Gobernanza
		- Centrarse en que las habilidades y procesos ajusten la estrategia y objetivos de la TI con la estrategia y objetivos empresariales, maximizando el valor de negocio de inversion y minimizando los riesgos comerciales.
		- Administracion de portafolios
		- Administracion de proyectos y programas
		- Mencion del rendimiento empresarial
		- Administracion de licencias
2. Enfoque en capacidades tecnicas
	1. Plataforma
		- Entender y comunicar la naturaleza de los sistemas de TI y sus relaciones. Describir la arquitectura del entorno objetivo detalladamente.
		- Aprovisionamiento de informatica
		- Aprovisionamiento de red
		- Aprovisionamiento de almacenamiento
		- Aprovisionamiento de bases de datos
		- Arquitectura de sistemas y soluciones
		- Desarrollo de aplicaciones
	2. Seguridad
		- Garantizar que la organizacion cumpla sus objetivos de seguridad.
		- Administracion de identidad y acceso
		- Control de deteccion
		- Seguridad de la infraestructura
		- Proteccion de datos
		- Respuesta a incidentes
	3. Operaciones
		- Definir como se realizaran los negocios diarios, trimestrales y anuales.
		- Monitoreo de servicios
		- Monitoreo del rendimiento de la aplicacion
		- Administracion de inventario de recursos
		- Administracion de versiones/cambios
		- Informes y analisis
		- Continuidad empresarial (recuperacion de desastres)
		- Catalogo de servicios de TI

