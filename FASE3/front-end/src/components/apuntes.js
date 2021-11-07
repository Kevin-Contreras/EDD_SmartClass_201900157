import react from 'react'
import '../App.css'
import NavAdmin from './navAdmin'

class Apuntes extends react.Component{


    render(){
      
      return(
        <div>
                <NavAdmin/>

          <form method="post" id="pensum">
<div class="form-group" >
      <label for="exampleTextarea"   class="form-label mt-4">INGREAR LOS APUNTES</label>
      <textarea class="form-control" name="usuario" rows="26"  id="exampleTextarea"></textarea>
      <button type="submit" id="botonn"  class="btn btn-primary">Enviar</button>
</div>
</form>
        </div>

      )
    }
    }
export default Apuntes