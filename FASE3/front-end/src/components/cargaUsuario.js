import react from 'react'
import '../App.css'
import NavAdmin from './navAdmin'

class CargaUsuario extends react.Component{
  constructor(props){
    super(props)
    this.state={
      usuarios :''

    }
    this.capturar=this.capturar.bind(this)
    this.input=this.input.bind(this)
  }
  capturar(event){
    
    
    fetch("/cargaUsuario",{
      method:'post',
      headers: {'Content-Type': 'application/json'},
      body:JSON.stringify(this.state.usuarios)
    }).then(response=> response.text()).then(dato=>{
      alert(dato )
      
    })
    this.setState({usuarios:""})
    event.preventDefault()
   
    
  }
  input(event){
    
      this.setState({usuarios:event.target.value})
    

  }
    render(){
      
      return(
        <div>
                <NavAdmin/>

          <form method="post" onSubmit={this.capturar} id="pensum">
<div class="form-group" >
      <label for="exampleTextarea"   class="form-label mt-4">INGREAR LOS DATOS</label>
      <textarea class="form-control" name="usuario" rows="26" onChange={this.input} value={this.state.usuarios} id="exampleTextarea"></textarea>
      <button type="submit" id="botonn"  class="btn btn-primary">Enviar</button>
</div>
</form>
        </div>

      )
    }
    }
export default CargaUsuario