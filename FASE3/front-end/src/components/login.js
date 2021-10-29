import react from 'react'
import Nav from './nav'
import '../App.css'
class Login extends react.Component{
  
    render(){
      return(
        <div>
         <Nav/>
         <div id="divImgenLogin" class= "animate__animated animate__bounceInUp">
           <img id="imagen" class="animate__animated animate__pulse animate__infinite animate__slower"  src={process.env.PUBLIC_URL +"/coete.png"}/>
         </div>
         <form method="post" class="animate__animated animate__bounceInRight">
         <div class="form-group " id="login">
          <label class="form-label mb-5">LOGIN</label>
        <div class="form-floating mb-5">
        <input type="email" class="form-control" id="floatingInput" placeholder="name@example.com"></input>
        <label for="floatingInput ">Usuario</label>
        </div>
        <div class="form-floating ">
        <input type="password" class="form-control mb-5"  placeholder="Password"></input>
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