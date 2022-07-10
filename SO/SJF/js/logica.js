$(document).ready(function(){
  $("#agregar").hide();
  var nombresProcesos = ["Nombres","A","B","C","D","E","F","G","H","I","J","K","L"];
  var tiemposRafaga = ["Tiempo Rafaga"];  
  var procesos = ["Proceso"];
  var llegada = ["Tiempo de llegada"];
  var tiempoFinalizacion = ["Tiempo de Finalizacion"];
  var tiempoRetorno = ["Tiempo de Retorno"];
  var tiempoEspera = ["Tiempo de Espera"];
  var tiempoComienzo = ["Tiempo de Comienzo"];
  var nomcolores = ["red","Crimson","blue","green","brown","yellow","purple","magenta","gray","Coral","DarkGreen"];
  var colores = ["red"];
  var alea = 0, intervalo = 10, tamaño = 20, contador = 1;
  var matriz = [procesos,llegada,tiemposRafaga,tiempoComienzo,tiempoFinalizacion,tiempoRetorno,tiempoEspera];

  $("#inicio").click(function(){
	  numeroProcesos();
    rafaga();
    quick_sort(tiemposRafaga);
    rellenarTabla();
    dibujarTabla();
    $("#inicio").hide();
	  $("#reload").show();
    pintar();
		pintar_numeros();
    setInterval(pintar_procesos,1000);                
  });  
  
  $("#reload").click(function(){
    window.location.reload(true);
  });
  //$("#lienzo").css({"background-color":"black"});

  function numeroProcesos(){
	  var numero = Math.round(Math.random()*6+3);	  
	  for(var i=1; i<=numero; i++){
		  procesos.push(nombresProcesos[i]);
		  colores.push(nomcolores[i]);
	  }
	  colores.push("white");
  }
  function rafaga(){
    for(var i=0; i<procesos.length-1; i++){
      if(contador == 1){
        alea = Math.round(Math.random()*6+1);
        tiemposRafaga.push(alea);
      }
    }
  }
  function rellenarTabla(){	  	
    /*RAFAGA
    for(var i=0; i<procesos.length-1; i++){
  	  if(contador == 1){
  		  alea = Math.round(Math.random()*6+1);
        tiemposRafaga.push(alea);
  	  }
    }*/
    //LLEGADA
    for(var i=0; i< (procesos.length-1)*4; i+=4){
      if(contador == 1){
        alea = i+Math.round(Math.random()*3);
        llegada.push(alea);  
      }      
    }
    for(var i=1; i<procesos.length; i++){
      if(llegada[i]>=tiempoFinalizacion[i-1] || i==1){
        tiempoFinalizacion[i] = llegada[i]+tiemposRafaga[i];
      } else{
        tiempoFinalizacion[i] = tiempoFinalizacion[i-1]+tiemposRafaga[i];  
      }
      tiempoRetorno[i] = tiempoFinalizacion[i]-llegada[i];
      tiempoEspera[i] = tiempoRetorno[i]-tiemposRafaga[i];
      tiempoComienzo[i] = llegada[i]+tiempoEspera[i];
    }
  }

  function dibujarTabla(){
    var body = document.getElementById("tabla");
    var tabla   = document.createElement("table");
    var tblBody = document.createElement("tbody");

    tabla.setAttribute("id", "table");
   
    for (var j = 0; j < procesos.length; j++) {
      var hilera = document.createElement("tr");   
      for (var i = 0; i < matriz.length; i++){
        var celda = document.createElement("td");
        var textoCelda = document.createTextNode(matriz[i][j]);
        celda.appendChild(textoCelda);
        hilera.appendChild(celda);
      }   
      tblBody.appendChild(hilera);
    }   
    tabla.appendChild(tblBody);
    body.appendChild(tabla);
    tabla.setAttribute("border", "2");
  }

  function borrarTabla(){
    var tabla = $("#tabla").empty();
  }

  function pintar(){
    var elemento = document.getElementById("lienzo");
    var lienzo = elemento.getContext('2d');          
    // DIBUJAR PROCESOS
    for(var i=1; i<procesos.length; i++){
      lienzo.fillStyle=colores[i];
      lienzo.fillRect(10,i*(tamaño+intervalo),tamaño,tamaño);
      lienzo.fillStyle = "white";
      lienzo.font = "20px Arial";
      lienzo.fillText(procesos[i],13,i*(tamaño+intervalo)+17);
    }    
  }
	function pintar_numeros(){
		var elemento = document.getElementById("lienzo");
    var lienzo = elemento.getContext('2d');     
		for(var i=0; i<=tiempoFinalizacion[tiempoFinalizacion.length-1]; i++){
      lienzo.fillStyle = "black";
      lienzo.font = "20px Arial";
      lienzo.fillText(i, (i+1)*(tamaño+intervalo)+10, procesos.length*(tamaño+intervalo)+100);
    }
  }
  function pintar_procesos(){		
    var elemento = document.getElementById("lienzo");
    var lienzo = elemento.getContext('2d');      
    for(var i=1; i<procesos.length; i++){ 
      if(contador-1 >= tiempoComienzo[i] && contador-1<tiempoFinalizacion[i]){			
        lienzo.fillStyle = colores[i];      
      }
      else{
        if(llegada[i]>contador-1 || contador-1>=tiempoFinalizacion[i]){				
          lienzo.fillStyle = colores[colores.length-1];
        }
        else{
          lienzo.fillStyle = colores[0];
        }
      }
      lienzo.fillRect(contador*(tamaño+intervalo)+10, i*(tamaño+intervalo),tamaño,tamaño);       
    }
    contador++;
  }
});