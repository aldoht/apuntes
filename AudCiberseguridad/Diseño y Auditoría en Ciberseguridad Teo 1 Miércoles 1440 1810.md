# Diseño y Auditoría en Ciberseguridad [Teo 1 - Miércoles 14:40 - 18:10]

## Notas adicionales
3 evaluaciones, en octubre se acaba la materia (#miedo), control de lectura (?) todas las semanas
Hay convenios con Amazon, RedHat y Cisco
Hacer certificaciones (revisar linkedin)
Nos van a inscribir en el primer curso de Amazon con correo universitario, si queremos más solo avisar
Revisar PearsonVue
Revisar cursos AWS, Microsoft, Azure, Nvidia, IBM para Data/ML/IA
## 2025-08-13
Dato personal -> Cualquier información para identificarte
Dato sensible -> Información sobre ti: género, ideología, bancaria, etc.

Objetivo: Entender la ley y las consecuencias
Auditoría: revisión de los procedimientos que se llevan en una empresa para comprobar que se reúne una serie de requisitos establecidos.

Diplomados 27017

"Ese es el mayor de los problemas que van a tener: las personas"

### Tarea 1

#### UNE-ISO / IEC 27001; mayo 2023
La ISO (Organización Internacional de Normalización) es una federación mundial de organismos nacionales de normalización.

Este documento proporciona los requisitos para establecer, implementar, mantener y mejorar continuamente un sistema de gestión de la seguridad de la información. La adopción de este tipo de sistemas es una decisión estratégica para una organización, este sistema preserva la confidencialidad, integridad y disponibilidad de la información mediante un proceso de gestión de riesgos.

La norma ISO/IEC 27001 puede ser usado para evaluar la capacidad de una organización para cumplir con sus propios requisitos de seguridad, además estos requisitos no siguen un orden en particular. Sigue un ciclo PHVA (Planificar, Hacer, Verificar, Actuar).

**¿Qué es la Norma ISO27001?**
Esta norma especifica los requisitos para el establecimiento, implementación, mantenimiento y mejora continua de un sistema de gestión de la seguridad de la información en el contexto de la organización; también incluye los requisitos para la apreciación y tratamiento de los riesgos de seguridad de información a la medida de las necesidades de la organización. Estos requisitos son genéricos y aplicables a todas las organizaciones.

**¿Qué es un SGSI?**
Un Sistema de Gestión de la Seguridad de la Información es un conjunto de políticas de administración de la información. La organización está encargada de establecer, implementar, mantener y mejorar de manera continua este sistema, siguiendo los procesos requeridos e interacciones según los requisitos de la Norma ISO27001.

**Tres requisitos previos para que una organización pueda implementar un SGSI**
1. Contexto y alcance.
	1. La organización debe determinar las cuestiones externas e internas que afectan su capacidad para lograr los resultados previstos de su SGSI.
	2. La organización debe determinar las partes interesadas relevantes para su SGSI, sus requisitos relevantes y decidir cuáles de dichos requisitos serán abordados a través del sistema.
	3. La organización debe determinar los límites y la aplicabilidad del sistema para establecer su alcance considerando lo ya mencionado junto a las interfaces y dependencias entre las actividades hechas por la organización y las que se llevan a cabo por otras organizaciones; esto debe estar disponible como información documentada.
	4. La organización debe establecer, implementar, mantener y mejorar de forma continua el sistema, incluyendo los procesos requeridos y sus interacciones según los requisitos de este documento.
2. Liderazgo y compromiso.
	1. La alta dirección debe demostrar liderazgo y compromiso...
		1. Asegurando el establecimiento de la política y objetivos de seguridad de la información y que estos sean compatibles con la dirección estratégica de la organización.
		2. Asegurando la integración de los requisitos del sistema de gestión en los procesos de la organización.
		3. Asegurando que los recursos necesarios para el sistema estén disponibles.
		4. Comunicando la importancia de una gestión eficaz y conforme los requisistos de la seguridad de la información.
		5. Asegurando que el sistema consigue los resultados previstos.
		6. Dirigiendo y apoyando a las personas para contribuir a la eficacia del sistema.
		7. Promoviendo la mejora continua.
		8. Apoyando a otros roles pertinentes de la dirección a fin de demostrar su liderazgo aplicado a sus áreas de responsabilidad.
	2. La alta dirección debe establecer una política de seguridad de la información que...
		1. Sea adecuada al propósito de la organización.
		2. Incluya objetivos de seguridad de la información o proporcione un marco de referencia para su establecimiento.
		3. Incluya el compromiso de cumplir con los requisitos aplicables a la seguridad de la información.
		4. Incluya el compromiso de mejora continua del sistema de gestión de la seguridad de la información.
	3. La política de seguridad de la información debe...
		1. Estar disponible como información documentada.
		2. Comunicarse dentro de la organización.
		3. Estar disponible para las partes interesadas.
	4. La alta dirección debe asignar la responsabilidad y autoridad para...
		1. Asegurarse que el sistema de la información es conforme con los requisitos del documento.
		2. Informar a la alta dirección sobre el comportamiento del sistema.
3. Planificación y gestión de riesgos.
	1. La organización debe...
		1. Asegurar que el sistema pueda conseguir sus resultados previstos.
		2. Prevenir o reducir efectos indeseados.
		3. Lograr la mejora continua.
		4. Planificar acciones para tratar riesgos y oportunidades.
		5. Planificar cómo integrar e implementar las acciones en los procesos del sistema y evaluar su eficacia.
	2. La organización debe definir y aplicar un proceso de evaluación de los riesgos de seguridad de la información que...
		1. Establezca y mantenga criterios sobre riesgos de seguridad incluyendo los criterios de aceptación de los riesgos y los criterios para llevar a cabo las apreciaciones de los riesgos.
		2. Asegure que las sucesivas apreciaciones de los riesgos generan resultados consistentes, válidos y comparables.
		3. Identifique los riesgos de seguridad de la información (mediante el proceso de evaluación de riesgos asociados a la pérdida de confidencialidad, integridad y disponibilidad) y a sus dueños.
		4. Analice los riesgos de seguridad de la información valorando las posibles consecuencias si los riesgos llegasen a materializarse, valorando realísticamente su probabilidad de ocurrencia y determinando los niveles de riesgo.
		5. Evalúe los riesgos de seguridad de la información comparando los resultados del análisis con los criterios establecidos previamente priorizando el tratamiento de los riesgos analizados.
	3. La organización debe conservar información documentada sobre el proceso de apreciación de riesgos y el tratamiento de la seguridad de la información.
	4. La organización debe definir y efectuar un proceso de tratamiento de los riesgos para...
		1. Seleccionar las opciones adecuadas de tratamiento según los resultados de la apreciación de riesgos.
		2. Determinar todos los controles que sean necesarios para implementar dichas opciones.
		3. Comparar controles para comprobar que no se ha omitido alguno necesario.
		4. Elaborar una "Declaración de Aplicabilidad"
			1. Controles necesarios.
			2. Justifiación de las inclusiones.
			3. Si los controles necesarios están implementados o no.
			4. Justificación de las exclusiones de cualquiera de los controles posibles del anexo.
		5. Formular un plan de tratamiento de riesgos de seguridad de la información.
		6. Obtener la aprobación del plan de tratamiento de riesgos y la aceptación de riesgos residuales por parte de sus dueños.
	5. La organización debe establecer los objetivos de seguridad de la información en las funciones y niveles pertinentes; estos objetivos deben...
		1. Ser coherentes con la política de seguridad de la información.
		2. Ser medibles si es posible.
		3. Tener en cuenta los requisitos de seguridad y lo resultados de la apreciación y tratamiento de los riesgos.
		4. Ser monitorizados.
		5. Ser comunicados.
		6. Ser actualizados según lo apropiado.
		7. Estar disponibles como información documentada.
	6. Para la planificación de la consecución de los objetivos de seguridad de la información, la organización debe determinar...
		1. Lo que se va a hacer.
		2. Qué recursos necesitará.
		3. Quién será responsable.
		4. Cuándo se finalizará.
		5. Cómo se evaluarán los resultados.
	7. Todo cambio en el sistema debe ser planificado.

El documento final se encuentra [aquí](./Control%20de%20Lectura%201%20Unidad%201%20-%20Aldo%20Hernández.pdf).
## 2025-08-20

Ciberseguridad -> Relacionado a tecnología: seguridad en páginas web, bases de datos, etc.
Seguridad de la información -> Tecnología, papel y personas; abarca desde la ciberseguridad hasta incluso el compromiso de personas según sus roles.

La información es un dato que para alguien es importante/significativo/valioso($).

Información + valiosa implica + recursos para protegerla; por eso las empresas pequeñas/medianas tienden a externalizar este servicio.

En la auditoría, una empresa revisa/certifica cómo se lleva a cabo la seguridad en una organización de acuerdo a las ISO (normalmente al ISO 9000).

Calidad = Entregar lo acordado = Responde cuando falla

Activo de la información
- Nombre
	- 10 PCs
- Dueño
	- Responsable TI
- Valor
	- 10.000.000 CLP

- ¿Cuánto gastarías para proteger algo? (Porcentaje, generalmente)
	- ¿Cuánto vale la información que manejamos?
		- El impacto financiero de que la empresa no tenga esa información por día/semana/mes... (costo indirecto)
		- 
	- ¿Cuánto vale una empresa?
	- **Transferencia de riesgo** - Una empresa comparte el riesgo de perder algo conmigo (como un seguro).

*Encriptar es ofuscar.*

Clave compartida (pre-share) -> Es como darle la contraseña de tu wifi a alguien -> Compartir antes de encriptar (?)
RSA -> Al levantar una página, ya está encriptada, protegiendo la información al ser transmitida.

Un humano siempre debe verificar el correcto funcionamiento de un sistema.

## 2025-08-27
Vocabulario -> ISO 27000.
Si una empresa elige ISO 27001 debe tener obligatoriamente control de acceso.
El gestión del riesgo (27005) también es obligatorio.
Auditoría -> Evaluación por un tercero del correcto cumplimiento de las normas.

3. Encuentre la definición de Control de Acceso y cuál es al capítulo que trata el tema en la ISO 27001 2023 y dónde se encontraría el control descrito en la ISO 27002-2022.
	1. Describa los requerimientos específicos para esa materia según la norma ISO 27002
4. ¿En cuál Capítulo se obliga a revisar en forma periódica los permisos de acceso?, ¿Cómo?

Según la ISO 27000, los controles de acceso son "medios para garantizar que el acceso a los activos esté autorizado y restringido según los requisitos comerciales y de seguridad", este tema se trata de cierta forma en el capítulo 7 de la ISO 27001:2023, concretamente en el subcapítulo 7.5.3 ya que habla sobre el control de la información documentada. El control se encuentra descrito en el capítulo 5.15 de la ISO 27002:2022. Este control requiere establecer e implementar reglas de control de acceso físico y lógico a la información y otros activos asociados a fin de garantizar el acceso autorizado y evitar el acceso no autorizado a la información y a otros activos asociados; además, se debe definir una política específica de control de acceso que tengan en consideración lo siguiente:
- qué tipo de acceso a la información y otros activos asociados requiere cada entidad;
- la seguridad de las aplicaciones;
- el acceso físico;
- la diseminación y autorización de la información y los niveles de seguridad y de clasificación de la información;
- la segregación de funciones;
- la legislación y normativas aplicables;
- la segregación de funciones en el control de acceso;
- la autorización formal de las peticiones de acceso;
- la gestión de los derechos de acceso;
- el registro.
De forma general se usan principalmente dos principios en este contexto: "algo que sabes" (acceso a información necesaria a la entidad para realizar sus tareas) y "algo que necesitas" (sólo se asigna a una entidad el acceso en casos de una necesidad clara). A su vez, se debe considerar el establecimiento de reglas basadas en la premisa del menor privilegio: "todo está prohibido a menos que se permita expresamente".

En el capítulo 5.18 (Derechos de acceso) de la ISO 27002:2022 se obliga a revisar en forma periódica los derechos de acceso a la información y otros activos asociados conforme a la política específica de la organización y las reglas sobre control de acceso para garantizar que el acceso a la información y a otros activos asociados es definido y autorizado de acuerdo a los requisitos del negocio. Se sugiere tener en consideración los derechos de acceso de los usuarios después de cualquier cambio dentro de la organización o finalización de empleo y las autorizaciones de derechos de acceso privilegiados.