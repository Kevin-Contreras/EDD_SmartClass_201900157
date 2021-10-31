
import NavAdmin from './navAdmin'
import Botones from './carga'
import '../App.css'
import { Component } from 'react'
class Admin extends Component{
render(){
  return(
    <div>
      <NavAdmin/>
    <Botones/>      
    </div>

  )
}
}
export default Admin