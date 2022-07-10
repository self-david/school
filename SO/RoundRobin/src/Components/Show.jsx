import React, { Fragment, useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import '../media/css/style.css';
import 'bootstrap/dist/css/bootstrap.css';
import { Container, Button, Table, FormGroup,ModalBody, ModalFooter } from "reactstrap";



function Show() {
  const [processes, setProcesses] = useState([]);
  const [quantum, setQuantum] = useState(1);
  const [max, setMax] = useState(0);

  const tope = 180;


  useEffect(() => {
    document.title = 'Round Robin';
    
    let data = []
    let b = 0;
    let m = 0;
    for (let i = 0; i < window.localStorage.length; i++) {
      let k = window.localStorage.key(i);
      let value = window.localStorage.getItem(k);
      data.push(JSON.parse(value));
      b += parseInt(JSON.parse(value).burst);

      if(parseInt(data[i].burst) > m) {
        m = parseInt(data[i].burst);
      }
    }
    
    data = data.sort((a, b) => (a.id - b.id));

    let p = [];
    for (let i = 0; i < data.length; i++) {
      // Crear info del proceso
      let v = {}
      v.name = data[i].name;
      v.id = data[i].id;
      v.arrival = data[i].arrival;
      v.burst = data[i].burst;

      v.TE = 0;
      v.TR = 0;
      v.first=undefined;

      v.height = data[i].burst/m*tope

      p.push(v);
    }

    setMax(m);
    setProcesses(p);

  }, [setProcesses]);

  
  let pos = 0;



  const animation = () => {
    let corte = (tope / max * quantum).toFixed(3);
    let p = [...processes];
    let p2 = [];
    let processBefore = 0;
    let offset = 0;

    let aux = getLong();

    let ee = undefined;
    let eee = undefined;
    let item = undefined;
    let itemB = undefined;
    let time = 0;
    

    aux.map( s => {
      setTimeout(() => {
        let element = document.getElementById(p[0].id);
        if(p[0] != itemB) {
          p[0].TE += time;
        }

        if(processBefore > 0) {
          processBefore = 0;
        }
        
        let abs = quantum - Math.abs(p[0].height) / (tope / max);

        if(abs >= 0) {
          if(p[0].first == undefined) {
            p[0].first = 0;
            console.log(p[0].first);
          }
        }

        if(abs > 0) {
          time += quantum - abs;
        } else {
          time += parseInt(quantum);
          if(p[0].first == undefined) {
            p[0].first = time;
          }
        }

        p[0].TR = time;
        
        p[0].height = (p[0].height - corte).toFixed(3);
        
        if(ee != undefined) {
          ee.parentNode.appendChild(ee);
          ee = undefined;
        }
        if(eee != undefined) {
          eee.parentNode.removeChild(eee);
          eee = undefined;
          itemB = undefined;
          // crear elemento terminado

          document.getElementById('t').appendChild(
            document.getElementById(item.name+item.id)
          );
        }  


        document.getElementById('ej').appendChild(
          document.getElementById(p[0].name+p[0].id)
        );

        if(itemB != undefined) {
          document.getElementById('es').appendChild(
            document.getElementById(itemB.name+itemB.id)
          );
        }
        

        if(p[0].height > 0) {
          element.style.height = p[0].height+'px';
          
          ee = element.parentNode;
          
          itemB = p[0];
          p.push(p.shift());
        } else {
          if(p[0].height < 0) {
            processBefore = Math.abs(p[0].height);
            p[0].height = 0;
          }
          eee = element.parentNode;
          item = p[0];
          // guardar proceso
          p2.push(p[0]);
          // eliminar elemento
          p = p.slice(1);
          element.style.height = '0px';
        }

      }, offset);

      offset += 3000;

    });

    
    setTimeout(() => {
      eee.parentNode.removeChild(eee);
      eee = undefined;
      
      // crear elemento terminado
      document.getElementById('t').appendChild(
        document.getElementById(item.name+item.id)
      );
    }, offset);

    let tep = 0;
    let trp = 0;
    setTimeout(() => {
      p2.map(p => {
        tep += p.TE - p.first;
        trp += p.TR;
        let text = document.createTextNode(p.TE - p.first); 
        document.getElementById(p.id+'TE').appendChild(text);
        
        let text2 = document.createTextNode(p.TR); 
        document.getElementById(p.id+'TR').appendChild(text2);
      });
    }, offset+100);

    setTimeout(() => {
      let text = document.createTextNode(tep/p2.length); 
      document.getElementById('TEP').appendChild(text);
      
      let text2 = document.createTextNode(trp/p2.length); 
      document.getElementById('TRP').appendChild(text2);
    }, offset+200);

    
  }




  const getLong = () => {
    let paux = [...processes];
    let aux = [];
    let processBefore = 0;
    while(paux.length > 0) {
        if(processBefore > 0) {
          processBefore = 0;
        }
        paux[0].burst -= quantum;
        

        if(paux[0].burst > 0) {
          paux.push(paux.shift());
        } else {
          if(paux[0].burst < 0) {
            processBefore = Math.abs(paux[0].burst);
            paux[0].burst = 0;
          }
          paux = paux.slice(1);
        }
        aux.push(0);
    }
    return aux;
  }

  const Q = (event) => { setQuantum(event.target.value); }



  return(
    <Fragment>
        <br />
        <div className="text-center">
          <h1>Round Robin</h1>
        </div>
         <br /> 
        <Container>
        <Link className="btn back" to="/RoundRobin"><strong>Regresar atras</strong></Link>
        
        <div>
          <div className="block">
            {processes.map((process, index) => {
              return (
                <Fragment>
                  <div
                    className="progress_"
                    style={{height: process.height,
                            bottom: 0}}>
                    <div className="progressMove animation" id={process.id}>
                      <div
                        className="processName"
                        id={process.id+'-text'}
                        >
                        {process.name}
                      </div>
                    </div>
                  </div>
                </Fragment>
              )
            })}
            </div>
            <div id="names">
            </div>
        </div>

        <div>
          <div className="p-e-e-t">
            <th>P. Ejecucion</th>
            <th>P. Espera</th>
            <th>P. Terminados</th>
          </div>
          <div className="p-e-e-t">
            <div id="ej" className="element">
            </div>
            <div id="es" className="element">
              {processes.map(process => {
                return (
                  <Fragment>
                    <span id={process.name+process.id}>{process.name}</span>
                  </Fragment>
                )
              })}
            </div>
            <div id="t" className="element">
            </div>
          </div>
        </div>

        <Table>
            <thead>
              <tr>
                <th>Nombre</th>
                <th>Tiempo Espera</th>
                <th>Tiempo Respuesta</th>
              </tr>
            </thead>

            <tbody>
              {processes.map((process) => (
                <tr key={process.id+'-'}>
                  <td>{process.name}</td>
                  <td id={process.id+'TE'}></td>
                  <td id={process.id+'TR'}></td>
                </tr>
              ))}
                <tr>
                  <td>Promedio</td>
                  <td id="TEP"></td>
                  <td id="TRP"></td>
                </tr>
            </tbody>
          </Table>

        <ModalBody>
          <FormGroup>
              <label>
                Quantum: 
              </label>
              <input
                className="form-control"
                name="burst"
                type="number"
                min="1"
                onChange={Q}
                value={quantum}
              />
            </FormGroup>
          </ModalBody>
          <ModalFooter>
            <Button className="btn btn-success" onClick={animation}>Ejecutar</Button>
          </ModalFooter>
        </Container>
    </Fragment>
  );
}


export default Show;