# Módulo 1
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
