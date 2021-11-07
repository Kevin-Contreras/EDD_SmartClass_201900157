import logo from './logo.svg';
import './App.css';
import Login from './components/login'
import Registro from './components/register'
import Admin from './components/admin'
import Pensum from './components/pensum'
import CargaUsuario from './components/cargaUsuario'
import InicioUsuarios from './components/usuario'
import Cargacursos from "./components/cargaCursos"
import Apuntes from "./components/apuntes"

import react from 'react'
import {BrowserRouter as Router,Switch,Route,link} from 'react-router-dom';

class App extends react.Component{
   render() {
    return (
      
       <Router>
         <Switch>
         <Route path="/register">
           <Registro/>
          </Route>
          <Route path="/admin">
           <Admin/>
          </Route>
          <Route path="/user">
           <InicioUsuarios/>
          </Route>
          <Route path="/pensum">
           <Pensum/>
          </Route>
          <Route path="/estudiantes">
           <CargaUsuario/>
          </Route>
          <Route path="/cursos">
           <Cargacursos/>
          </Route>
          <Route path="/apuntes">
           <Apuntes/>
          </Route>
           <Route path="/">
            <Login/>
           </Route>
         </Switch>
       </Router>
      
    );
  }
}


export default App;
