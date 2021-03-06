import react from 'react'
import '../App.css'

class NavAdmin extends react.Component{
  re(){
    alert("se crearon los reportes")
    fetch("/reporteEstudiantes",{
      method:"get",
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
        
          <a class="navbar-brand  animate__animated animate__backInLeft" href="/admin">Carga<span class="visually-hidden">(current)</span></a>
        
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" href="#">Blockchain</a>
        </li>
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" href="#">Reporte Apuntes Estudiantes</a>
        </li>
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" onClick={this.re} href="/admin">Reporte Estudiantes Registrados</a>
        </li>
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft"  href="#">Reporte Grafo de Prerrequisitos</a>
        </li>
      
        <li class="nav-item">
          <a class="nav-link animate__animated animate__backInLeft" href="#">Reporte Arbol Merkle</a>
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
export default NavAdmin