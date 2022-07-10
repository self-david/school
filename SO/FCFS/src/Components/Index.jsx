import React from 'react';
import '../media/css/App.css';
import "bootstrap/dist/css/bootstrap.min.css";
import { Link } from 'react-router-dom';
import {
  Table,
  Button,
  Container,
  Modal,
  ModalHeader,
  ModalBody,
  FormGroup,
  ModalFooter,
} from "reactstrap";


const data = [];

class App extends React.Component {

  constructor(props) {
    super(props)
    
    var lista = this.state.data = [];
    
    for(let i=0; i < window.localStorage.length; i++) {
      let k = window.localStorage.key(i);
      let r = window.localStorage.getItem(k);

      var valorNuevo= JSON.parse(r);
      lista.push(valorNuevo);
      lista = lista.sort((a, b) => (a.id - b.id));
    }
    
  }
  


  state = {
    data: data,
    modalActualizar: false,
    modalInsertar: false,

    form: {
      id: "",
      name: "",
      arrival: "",
      burst: "",
    },
  };

  mostrarModalActualizar = (dato) => {
    this.setState({
      form: dato,
      modalActualizar: true,
    });
  };

  mostrarModalInsertar = () => {
    for(let i=0; i < window.localStorage.length; i++) {
      let k = window.localStorage.key(i)
      let r = window.localStorage.getItem(k)
      console.log(JSON.parse(r))
    }
    
    this.setState({ modalInsertar: true });
  };

  cerrarModalInsertar = () => {
    this.setState({ modalInsertar: false });
  };

  eliminar = (dato) => {
    var opcion = window.confirm("Estás Seguro que deseas Eliminar el procceso "+dato.name);
    if (opcion === true) {
      var contador = 0;
      var arreglo = this.state.data;
      arreglo.map((registro) => {
        if (dato.id === registro.id) {
          arreglo.splice(contador, 1);
        }
        contador++;
      });
      this.setState({ data: arreglo, modalActualizar: false });
      window.localStorage.removeItem(dato.id);
    }
  };

  insertar= ()=>{
    var valorNuevo= {...this.state.form};
    valorNuevo.id=this.state.data.length+1;
    var lista= this.state.data;
    
    if (lista.length > 0 && parseInt(valorNuevo.arrival) <= parseInt(lista[lista.length-1].arrival) ||
      lista.length === 0 && parseInt(valorNuevo.arrival) < 0) {
      var opcion = window.alert("El valor de llegada es muy pequeño");
    } else if(parseInt(valorNuevo.burst) < 1) {
      var opcion = window.alert("La rafaga no puede ser inferior a 1");
    } else {
      lista.push(valorNuevo);
      window.localStorage.setItem(valorNuevo.id, JSON.stringify(valorNuevo));
      this.setState({ modalInsertar: false, data: lista });
    }
  }

  validMinNumber = () => {
    if(data.length > 0) {
      return parseInt(data[data.length-1].arrival) + 1;
    } else {
      return 0;
    } 
  }

  handleChange = (e) => {
    this.setState({
      form: {
        ...this.state.form,
        [e.target.name]: e.target.value,
      },
    });
  };

  Clear = () => {

    var opcion = window.confirm("Estás Seguro que deseas Eliminar todos los proccesos");
    if (opcion === true) {
      var arreglo = this.state.data;
      arreglo.splice(0, arreglo.length);
      window.localStorage.clear();
      this.setState({ data: arreglo, modalActualizar: false });
    }

  }


  render() {
    return (
      <>
        <br />
        <div className="text-center"><h1>FCFS</h1></div>
        <Container>
          <br />
          <div className="btns">
          <Button color="success" onClick={()=>this.mostrarModalInsertar()}>Crear</Button>
          <Button color="danger" onClick={()=>this.Clear()}>Eliminar todo</Button>
          </div>
          <br />
          <br />
          <Table>
            <thead>
              <tr>
                <th>Nombre</th>
                <th>Llegada</th>
                <th>Rafaga</th>
                <th>Eliminar</th>
              </tr>
            </thead>

            <tbody>
              {this.state.data.map((dato) => (
                <tr key={dato.id}>
                  <td>{dato.name}</td>
                  <td>{dato.arrival}</td>
                  <td>{dato.burst}</td>
                  <td>
                    <Button color="danger" onClick={()=> this.eliminar(dato)}>Eliminar</Button>
                  </td>
                </tr>
              ))}
            </tbody>
          </Table>
          <br /> <br />
          <Link className="btn btn-primary" to="/FCFS/Show">Ejecutar</Link>
        </Container>

        <Modal isOpen={this.state.modalInsertar}>
          <ModalHeader>
           <div><h3>Insertar Procceso</h3></div>
          </ModalHeader>

          <ModalBody>
            <FormGroup>
              <label>
                Nombre: 
              </label>
              
              <input
                className="form-control"
                name="name"
                type="text"
                onChange={this.handleChange}
              />
            </FormGroup>
            
            <FormGroup>
              <label>
                Llegada: 
              </label>
              <input
                className="form-control"
                name="arrival"
                type="number"
                min={this.validMinNumber()}
                onChange={this.handleChange}
              />
            </FormGroup>
            
            <FormGroup>
              <label>
                Rafaga: 
              </label>
              <input
                className="form-control"
                name="burst"
                type="number"
                min="1"
                onChange={this.handleChange}
              />
            </FormGroup>
          </ModalBody>

          <ModalFooter>
            <Button
              color="primary"
              onClick={() => this.insertar()}
            >
              Agregar
            </Button>
            <Button
              className="btn btn-danger"
              onClick={() => this.cerrarModalInsertar()}
            >
              Cancelar
            </Button>
          </ModalFooter>
        </Modal>
      </>
    );
  }
}
export default App;