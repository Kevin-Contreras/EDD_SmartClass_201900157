class Archivo:
  def lectura(ruta):
    archivo = open(ruta)
    for d in archivo.readlines():
      if(d.find("\n")!=-1):
         m = d.rstrip()
         print(m);
        
      else:
        print(d)
        print("hola a todos los maricas")
        

      
        
