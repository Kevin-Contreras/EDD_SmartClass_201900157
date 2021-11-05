import react from 'react'
import NavUsuario from './navUsuario'
import Registro from './register'
import {BrowserRouter as Router,Redirect,Switch,Route,link} from 'react-router-dom';
import '../App.css'
class inicioUsuario extends react.Component{
  state = {
    carnet:"",
    nombre:"",
    carrera:"",
    dpi:"",
    edad:""
  }
  componentDidMount(){
     
      fetch("/usuario",{
        method:'get',
        headers: {'Content-Type': 'application/json'}
       
      }).then(response=> response.json()).then(dato=>{
        this.setState({carnet:dato["carnet"],nombre:dato["nombre"],carrera:dato["carrera"],dpi:dato["DPI"],edad:dato["edad"]})
        
      })
      
      
    }

    render(){
      
      return(
        <div>
         <NavUsuario/>
        <h1>BIENVENIDO</h1>
      <h1>{this.state.carrera}</h1>
      <h1>{this.state.nombre}</h1>
      <h1>{this.state.carnet}</h1>

        </div>
      )
    }
  
}
export default inicioUsuario