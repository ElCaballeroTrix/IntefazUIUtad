# UTAD-UI-FPS-Public
 
## Aspectos Clave
    Para abrir el inventario, se hace a través de la tecla "I", como se puede ver en el Input Mapping Context denominado "IA_Menu". 
    Para obtener puntos de habilidad para el árbol, basta con matar un par de enemigos.
    Los puntos de habilidad del jugador, se encuentran debajo del mapa.
    Por último, la pantalla splash no se puede saltar, dura 3 segundos.

## Barra de Vida:
             	Cada vez que el jugador actualiza su vida en "SetHealth()", se actualiza el porcentaje de la 
             	barra de vida y además, se comprueba si el jugador tienen poca vida. Cuando tiene poca vida
             	en la función "Tick" se utilizan dos temporizadores, uno para detectar cuando a superado
             	el threshold, y otro el tiempo de animación. Cada vez que se supera el threshold, se cambia el
             	color de la barra y la escalad de la misma, y cuando se llega al tiempo de la animación, se vuelve a
             	empezar creando un bucle.
              
## Crosshair Dinámico:
            	Cuando se llama a la función de "Fire" del arma, se accede al widget del crosshair y comienza una
            	animación. En esta animación, producida en el "Tick", el crosshair cambia
            	su ángulo de rotación hacia la derecha. Cuando llega al medio segundo, hace la rotación al revés
            	hasta llegar a su posición original. Esta animación se me ocurrió un día y la hice porque nunca la 
            	he visto en ningún videojuego y es fácil de implementar.
            	Para el cambio de color del crosshair, en el "Tick", se hay un raycast en línea recta
            	desde la posición de la cámara. Si hay colisión con algún elemento y es un enemigo, cambiara el 
            	color a rojo, blanco en caso contrario modificando el "Brush" de la imagen.
             
## Marcador de Daño en Pantalla:
            	Cuando el jugador recibe daño, se actualiza su vida con "SetHealth". Esta función llama al widget
            	"PlayerHitMarker" a través de la función "GotHit()". Cuando se llama a esta función, en el "Tick",
            	cada 0,5 segundos se cambia la opacidad de la imagen que contiene este widget, y cuando haya pasado
            	un segundo, desaparece poniendo la opacidad de la imagen a 0, reseteando las variables usadas.
            	He tomado estas medidas porque considero que con ellas, el jugador puede percibir perfectamente que le
            	dañaron sin afectar demasiado el gameplay.
             
## Pantalla Splash:
            En el personaje, se añade la pantalla de splash al viewport al inicio. Dicha pantalla pausa el 
            juego, y continua el juego después de 3 segundos que se calculan en el "Tick" donde además se 
            elimina el viewport. He tomado esta decisión ya que es fácil de implementar y creo que es mejor
            que cargar un nivel vacío con la pantalla de splash y luego cargar el nivel general.
            
## Árbol de Habilidades:
           	Para el árbol de habilidades, hay un clase widget que representa una habilidad y una clase 
           	que representa el árbol. En la habilidad, "SkillSlot", se vinculan las acciones del botón.
           	Si se pasa el ratón por encima del botón de la habilidad, se accede al árbol para mostrar
           	en texto el nombre y descripción de la habilidad, y cuando se quita el ratón de encima,
           	desaparece dicho texto. Si se presiona sobre la habilidad, durante 2 segundos (detectado en el
           	"Tick", y visualizado en pantalla a través de una "progress bar"), se accede a la función 
           	"UnlockSkill", donde se comprueba si la habilidad está disponible
           	para obtener, si el jugador tiene los suficientes puntos para obtenerla y si el jugador no la
           	obtenido anteriormente. Si no cumple algunas de estas condiciones, se le notifica al jugador, 
           	en cambio, si cumple las condiciones, se cambia la información visible de la habilidad, el jugador
           	pierde puntos de habilidad y los hijos de la habilidad, cambian de color para mostrar al 
           	jugador que ya pueden ser obtenidos. Por último, si el jugador presiona sobre la habilidad y suelta,
           	accederá al árbol de habilidades para que le salga una caja de confirmación siempre y cuando, esa 
           	habilidad esté disponible para desbloquear.
           	
           	Respecto al árbol de habilidades, este se muestra en pantalla cuando el jugador presiona la tecla 
           	"I", se establece como padre de las habilidades, muestra información de las habilidades y maneja 
           	la caja de confirmación mencionada anteriormente en la cual si se confirma la adquisición de 
           	dicha habilidad, accederá a la función "UnlockSkill" de la habilidad en cuestión.