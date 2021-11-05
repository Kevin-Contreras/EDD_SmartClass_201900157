import react from 'react'
import Nav from './nav'
import '../App.css'
class Registro extends react.Component{
    constructor(props){
      super(props)
      this.state={
        carnet:"",
        dpi:"",
        nombre:"",
        carrera:"",
        correo:"",
        password:"",
        edad:""
      }
      this.capturar = this.capturar.bind(this)
      this.form = this.form.bind(this)

    }
    capturar(event){
      fetch("/registro",{method:'post',
      headers: {'Content-Type': 'application/json'},
    body:JSON.stringify(this.state)})
    event.preventDefault()
    }
    form(event){
      if(event.target.name=="carnet"){
        this.setState({carnet:event.target.value})
      }
      if(event.target.name=="dpi"){
        this.setState({dpi:event.target.value})
      }
      if(event.target.name=="nombre"){
        this.setState({nombre:event.target.value})
      }
      if(event.target.name=="carrera"){
        this.setState({carrera:event.target.value})
      }
      if(event.target.name=="correo"){
        this.setState({correo:event.target.value})
      }
      if(event.target.name=="password"){
        this.setState({password:event.target.value})
      }
      if(event.target.name=="edad"){
        this.setState({edad:event.target.value})
      }

    }

    render(){

      return(
        <div>
         <Nav/>
         <div id="divImgenLogin" class= "animate__animated animate__bounceInUp ">
           <img id="imagen" class="animate__animated animate__pulse animate__infinite animate__slower"  src={process.env.PUBLIC_URL +"/persona.png"}/>
         </div>
         

         <form method="post" onSubmit={this.capturar} class="animate__animated animate__bounceInRight subir">
         <div class="form-group" id="login">
        <div class="form-group" id="logins">
        <label class="form-label mb-4">SIGN UP</label>
        </div>
        <div class="form-floating mb-4">
        <input type="text" name="carnet"value={this.state.carnet} onChange={this.form} class="form-control" id="floatingInput" placeholder="name@example.com"></input>
        <label for="floatingInput ">Carnet</label>
        </div>
        <div class="form-floating ">
        <input type="text" name="dpi" value={this.state.dpi} onChange={this.form} class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">DPI</label>
        </div>
        <div class="form-floating ">
        <input type="text" name="nombre" value={this.state.nombre} onChange={this.form} class="form-control mb-4"  placeholder="nombre"></input>
        <label for="floatingPassword">Nombre</label>
        </div>
        <div class="form-floating ">
        <input type="text" name="carrera" value={this.state.carrera} onChange={this.form} class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Carrera</label>
        </div>
        <div class="form-floating ">
        <input type="email" name="correo" value={this.state.correo} onChange={this.form} class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Correo</label>
        </div>
        <div class="form-floating ">
        <input type="password" name="password" value={this.state.password} onChange={this.form} class="form-control mb-4"  placeholder="Password"></input>
        <label for="floatingPassword">Password</label>
        </div>
        <div class="form-floating ">
        <input type="text" name="edad" value={this.state.edad} onChange={this.form} class="form-control mb-4"  placeholder="Password"></input>
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