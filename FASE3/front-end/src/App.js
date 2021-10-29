import logo from './logo.svg';
import './App.css';
import Login from './components/login'
import Registro from './components/register'
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
           <Route path="/">
            <Login/>
           </Route>
         </Switch>
       </Router>
      
    );
  }
}


export default App;
