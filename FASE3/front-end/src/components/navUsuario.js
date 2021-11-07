import react from 'react'
import '../App.css'

class navUsuario extends react.Component{

  re2(){
    alert("se creo el reporte")
    fetch("/mostrarCursos",{
      method:"post",
      headers: {'Content-Type': 'application/json'}
    })
  }
    render(){
      return(
        <div>
         <nav class="navbar navbar-expand-lg navbar-dark bg-dark " id="barra" >
  <div class="container-fluid">
    
  
    <div class="collapse navbar-collapse" id="navbarColor02">
      <ul class="navbar-nav me-auto">
        
          <a class="navbar-brand  animate__animated animate__backInLeft" href="/user">HOME<span class="visually-hidden">(current)</span></a>
        
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" href="#">Asignarse cursos del pensum</a>
        </li>
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" onClick={this.re2}  href="/user">Reporte Cursos Asignados</a>
        </li>
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft"   href="/user">Reporte Cursos Previos</a>
        </li>
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" href="#">Realizar Apunte</a>
        </li>
       
        <li class="nav-item dropdown">
          <a class="nav-link animate__animated animate__backInLeft" id="cerrar" data-bs-toggle="dropdown" href="/" role="button" aria-haspopup="true" >Sign off</a>
        </li>
      </ul>
      
    </div>
  </div>
</nav>

        </div>
      )
    }
  
}
export default navUsuario