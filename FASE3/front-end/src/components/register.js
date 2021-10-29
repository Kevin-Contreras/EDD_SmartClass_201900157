import react from 'react'
import Nav from './nav'
import '../App.css'
class Registro extends react.Component{
  
    render(){
      return(
        <div>
         <Nav/>
         <div id="divImgenLogin" class= "animate__animated animate__bounceInUp ">
           <img id="imagen" class="animate__animated animate__pulse animate__infinite animate__slower"  src={process.env.PUBLIC_URL +"/persona.png"}/>
         </div>
         

         <form method="post" class="animate__animated animate__bounceInRight subir">
         <div class="form-group" id="login">
        <div class="form-group" id="logins">
        <label class="form-label mb-4">SIGN UP</label>
        </div>
        <div class="form-floating mb-4">
        <input type="email" class="form-control" id="floatingInput" placeholder="name@example.com"></input>
        <label for="floatingInput ">Carnet</label>
        </div>
        <div class="form-floating ">
        <input type="text" class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">DPI</label>
        </div>
        <div class="form-floating ">
        <input type="text" class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Nombre</label>
        </div>
        <div class="form-floating ">
        <input type="text" class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Carrera</label>
        </div>
        <div class="form-floating ">
        <input type="email" class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Correo</label>
        </div>
        <div class="form-floating ">
        <input type="password" class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Password</label>
        </div>
        <div class="form-floating ">
        <input type="text" class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Edad</label>
        </div>
        <button type="submit" id="boton" class="btn btn-primary">sign up</button>
          </div>
         </form>

        </div>
      )
    }
  
}
export default Registro