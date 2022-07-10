import React, { Fragment } from 'react';
import { Link } from 'react-router-dom';
import { Container } from "reactstrap";


function Show() {
  return(
    <Fragment>
        <br />
        <div className="text-center"><h1>FCFS</h1></div>
        <Container>
        <Link className="btn btn-success" to="/">Regresar al inicio</Link>
        <br /><br /><br /><br /><br /><br /><br />
        <h2 className="text-center">Error 404, pagina no encontrada</h2>

        </Container>
    </Fragment>
  );
}


export default Show;