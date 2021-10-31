import react from 'react'
import '../App.css'
class Botones extends react.Component{
    pensum(){
      window.location.replace("/pensum")
    }
    estudiante(){
      window.location.replace("/estudiantes")
    }
    cursos(){
      window.location.replace("/cursos")
    }
    apuntes(){
      window.location.replace("/apuntes")
    }
    render(){
      return(
        <div >
          <div id="divImgenLogin3" className="animate__animated animate__fadeInDownBig">
          <img id="imagen3" class="animate__animated animate__pulse animate__infinite animate__slower"  src={process.env.PUBLIC_URL +"/nose.png"}/>
          </div>
          <div id="botones" >
          <button type="submit"  class="btn btn-primary btn-lg botones animate__animated animate__fadeInDownBig" onClick={this.pensum}> Carga Pensum</button>
        <button type="button" class="btn btn-primary btn-lg botones animate__animated animate__fadeInDownBig" onClick={this.estudiante} >Carga Estudiantes </button>
        <button type="button" class="btn btn-primary btn-lg botones animate__animated animate__fadeInDownBig" onClick={this.cursos}>Carga Cursos Estudiante</button>
        <button type="button" class="btn btn-primary btn-lg botones animate__animated animate__fadeInDownBig" onClick={this.apuntes}>Carga Apuntes</button>
          </div>
       
        </div>
        
      )
    }
}
export default Botones