import react from 'react'
import Nav from './nav'
import Registro from './register'
import {BrowserRouter as Router,Redirect,Switch,Route,link} from 'react-router-dom';
import '../App.css'
class Login extends react.Component{
    constructor(props){
      super(props)
      this.state={
        usuario :'',
        password:'',
        stado:''
      }
      this.capturar=this.capturar.bind(this)
      this.input=this.input.bind(this)
    }
    capturar(event){

      fetch("/login",{
        method:'post',
        headers: {'Content-Type': 'application/json'},
        body:JSON.stringify(this.state)
      }).then(response=> response.text()).then(dato=>{
        if(dato!="admin"){
        window.location.replace("/user/"+dato)
        }else{
          window.location.replace("/admin")
        }
        
      })
      
      event.preventDefault()
    }
    input(event){
      if(event.target.name=="usuario"){
        this.setState({usuario:event.target.value})
      }
      else{
        this.setState({password:event.target.value})
      }

    }
    render(){
      
      return(
        <div>
         <Nav/>
         <div id="divImgenLogin" class= "animate__animated animate__bounceInUp">
           <img id="imagen" class="animate__animated animate__pulse animate__infinite animate__slower"  src={process.env.PUBLIC_URL +"/coete.png"}/>
         </div>
         <form method="post"  onSubmit={this.capturar} class="animate__animated animate__bounceInRight">
         <div class="form-group " id="login">
          <label class="form-label mb-5">LOGIN</label>
        <div class="form-floating mb-5">
        <input type="text" class="form-control" name="usuario" onChange={this.input} value={this.state.usuario} id="floatingInput" placeholder="name@example.com"></input>
        <label for="floatingInput ">Usuario</label>
        </div>
        <div class="form-floating ">
        <input type="password" class="form-control mb-5" name="password" onChange={this.input} value={this.state.password} placeholder="Password"></input>
        <label for="floatingPassword">Password</label>
        <button type="submit" id="boton" class="btn btn-primary">Sign in</button>
          
        
        </div>
  
  </div>
         </form>

        </div>
      )
    }
  
}
export default Login