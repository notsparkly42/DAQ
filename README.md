Actividaad de Reclutamiento – DAQ
Nombre: Morales Paredes Eric Aaron

Este repositorio contiene las dos actividades que realicé para Adquisición de Datos (DAQ). El objetivo es demostrar cómo proteger los sistemas del monoplaza y cómo analizar los datos que junta mientras esta en la pista.
1. Protección del Acelerador (APPS)
En los coches de carreras, si el cable del acelerador se rompe o falla un sensor, el coche podría quedarse acelerado a fondo. Para evitar accidentes, la regla FSAE T.4.2 exige poner dos sensores en el pedal del acelerador, armé la simulación usando un Arduino Uno y dos potenciómetros alimentados a 5V, leí las señales por los pines A0 y A1 del Arduino. El código convierte las lecturas de los dos sensores a un porcentaje de 0% a 100%, si hay un chispazo o falso contacto rápido, el coche no se apaga pero si los dos potenciómetros dan valores diferentes por más de 100 ms continuos, el sistema detecta la falla y activa el apagado de seguridad.
<img width="1369" height="607" alt="image" src="https://github.com/user-attachments/assets/396124b2-c82c-4c04-aaa2-b087c8736f30" />
<img width="1399" height="678" alt="image" src="https://github.com/user-attachments/assets/9e1a26af-1bd7-4679-afc9-e76698b3a91e" />

2. Análisis de Datos de Telemetría
Analicé el archivo con datos reales de la computadora del monoplaza (data.csv) para encontrar errores en los sensores y ver cómo se comporta el vehículo en la pista.
Le apliqué un filtro a la señal para quitar las vibraciones del motor sin alterar el tiempo real de los datos, seguido calculé cuánta fuerza de aceleración y curva soporta el coche combinando los ejes X e Y.
Hice un diagrama para ver el límite de agarre de las llantas al frenar y dar vuelta y finalmente el programa avisó automáticamente si el piloto pisó el freno y el acelerador al mismo tiempo por más de 100 ms. 
