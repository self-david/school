import React, { Fragment, useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import '../media/css/style.css';
// import 'bootstrap/dist/css/bootstrap.css';
import { Container, Button, Table } from "reactstrap";


function Show() {
  const [processes, setProcesses] = useState([]);

  useEffect(() => {
    document.title = 'FCFS';
    
    let data = []
    let b = 0;
    for (let i = 0; i < window.localStorage.length; i++) {
      let k = window.localStorage.key(i);
      let value = window.localStorage.getItem(k);
      data.push(JSON.parse(value));
      b += parseInt(JSON.parse(value).burst);
    }
    data = data.sort((a, b) => (a.id - b.id));

    let p = [];
    let w = 0;
    let te = 0;
    let t_espera = 0;
    for (let i = 0; i < data.length; i++) {
      // Crear info del proceso
      let v = {}
      v.name = data[i].name;
      v.id = data[i].id;
      v.leftText = parseInt(data[i].arrival) * 100 / b + '%';
      v.width = parseInt(data[i].burst) * 100 / b;
      v.leftBar = w + '%';
      w += v.width;
      v.width += '%';

      // Tiempos
      v.TE = parseInt(te - data[i].arrival);//tiempo espera
      te += parseInt(data[i].burst);

      v.TR = parseInt(data[i].burst) +  t_espera;//tiempo respuesta
      t_espera += parseInt(data[i].burst);


      p.push(v);
    }

    setProcesses(p);

  }, [setProcesses]);

  
  let pos = 0;

  const styleObj = {
    height: processes.length*35,
  }

  const animation = () => {
    processes.map( e => {
        let element = document.getElementById(e.id);
        element.classList.remove('animation');
        element.classList.remove('endAnimate');
    });
    let offset = 0;
    let b = null;
    let t = null;
    processes.map( e => {
        setTimeout(() => {
          if(b !== null) {
            b.classList.add('endAnimate');
          }
          let element = document.getElementById(e.id);
          element.classList.add('animation');
          b = element;

          if(t !== null) {
            t.classList.remove('black');
          }
          let elementT = document.getElementById(e.id+'-text');
          elementT.classList.add('black');
          t = elementT;

        }, offset);
        offset += 4400;
      }
    );
    setTimeout(() => {
      b.classList.add('endAnimate');
      t.classList.remove('black');
    }, offset);
  }

  const TEP = () => {
    let t = 0;

    processes.map(process => { t += process.TE; });

    return (t /= processes.length).toFixed(2);
  }

  const TRP = () => {
    let t = 0;

    processes.map(process => { t += process.TR; });

    return (t /= processes.length).toFixed(2);
  }



  return(
    <Fragment>
        <br />
        <div className="text-center">
          <h1>FCFS</h1>
        </div>
        <Link className="btn back" to="/FCFS"><strong>Regresar atras</strong></Link>
         <br /> 
        <Container>
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
                <tr key={process.id}>
                  <td>{process.name}</td>
                  <td>{process.TE}</td>
                  <td>{process.TR}</td>
                </tr>
              ))}
                <tr>
                  <td>Promedio</td>
                  <td>{TEP()}</td>
                  <td>{TRP()}</td>
                </tr>
            </tbody>
          </Table>

        <div className="block" style={styleObj}>
          <div className="line">
            {processes.map(process => {
              return (
                <Fragment>
                  <div
                    className="process"
                    id={process.id+'-text'}
                    style={{left: process.leftText, top: -133}}>
                      {process.name}
                  </div>
                  <div
                    className="progress"
                    style={{width: process.width,
                            left: process.leftBar,
                            top: (pos++ * 35)}}>
                      <div
                        id={process.id}
                      ></div>
                  </div>
                </Fragment>
              )
            })}
          </div>
        </div>
        <br/><br/>
        <Button className="btn btn-success" onClick={animation}>Ejecutar animacion</Button>
        </Container>
        <br /><br /><br /><br /><br /><br /><br />
    </Fragment>
  );
}


export default Show;