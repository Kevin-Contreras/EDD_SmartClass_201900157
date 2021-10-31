import react from 'react'
import '../App.css'
import NavAdmin from './navAdmin'

class Pensum extends react.Component{
  constructor(props){
    super(props)
    this.state={
      pensum :''

    }
    this.capturar=this.capturar.bind(this)
    this.input=this.input.bind(this)
  }
  capturar(event){
    
    
    fetch("/pensum",{
      method:'post',
      headers: {'Content-Type': 'application/json'},
      body:JSON.stringify(this.state.pensum)
    }).then(response=> response.text()).then(dato=>{
      alert(dato )
      
    })
    this.setState({pensum:""})
    event.preventDefault()
   
    
  }
  input(event){
    
      this.setState({pensum:event.target.value})
    

  }
    render(){
      
      return(
        <div>
                <NavAdmin/>

          <form method="post" onSubmit={this.capturar} id="pensum">
<div class="form-group" >
      <label for="exampleTextarea"   class="form-label mt-4">INGREAR LOS DATOS</label>
      <textarea class="form-control" name="pensum" rows="26" onChange={this.input} value={this.state.pensum} id="exampleTextarea"></textarea>
      <button type="submit" id="botonn"  class="btn btn-primary">Enviar</button>
</div>
</form>
        </div>

      )
    }
    }
export default Pensum