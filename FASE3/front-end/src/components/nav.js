import react from 'react'
import '../App.css'

class Nav extends react.Component{
  
    render(){
      return(
        <div>
         <nav class="navbar navbar-expand-lg navbar-dark bg-dark " id="barra" >
  <div class="container-fluid">
    <a class="navbar-brand animate__animated animate__bounceInLeft" href="/">Smart</a>
  
    <div class="collapse navbar-collapse" id="navbarColor02">
      <ul class="navbar-nav me-auto">
        <li class="nav-item">
          <a class="nav-link active animate__animated animate__bounceInLeft" href="/register">Sign up<span class="visually-hidden">(current)</span></a>
        </li>
  
      </ul>
      
    </div>
  </div>
</nav>

        </div>
      )
    }
  
}
export default Nav