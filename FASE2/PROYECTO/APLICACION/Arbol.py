import os
class Node:
    
    def __init__(self, carnet,DatosNodo):
        self.DatosNodo = DatosNodo
        self.carnet = carnet
        self.para = None
        self.izquierda = None
        self.derecha = None
        self.cll = 0
        self.id=1;
       
     

  
    def derecha(self):
        return self.derecha

    
    def derecha(self, node):
        if node is not None:
            node.para = self
            self.derecha = node

    
    def izquierda(self):
        return self.izquierda

    
    def izquierda(self, node):
        if node is not None:
            node.para = self
            self.izquierda = node

    
    def para(self):
        return self.para

    
    def para(self, node):
        if node is not None:
            self.para = node
            self.cll = self.para.cll + 1
        else:
            self.cll = 0

    def interno(self) :
        eti="";
        if(self.izquierda==None and self.derecha==None):
            eti="nodo"+str(self.id)+" [ label =\""+self.DatosNodo+", INGENIERIA"+"\"];\n";
        else:
            eti="nodo"+str(self.id)+" [ label =\"<C0>|"+self.DatosNodo+", INGENIERIA|<C1>\"];\n";
        
        if(self.izquierda!=None):
            eti=eti + self.izquierda.interno() +"nodo"+str(self.id)+":C0->nodo"+str(self.izquierda.id)+"\n";
        
        if(self.derecha!=None):
            eti=eti + self.derecha.interno() +"nodo"+str(self.id)+":C1->nodo"+str(self.derecha.id)+"\n";                    
        
        return eti;
    def graficarArbolAVL(self):
        file = open("ArbolAVL.dot","w",encoding='utf-8')
        file.write("digraph grafica{\n" +"rankdir=TB;\n" +"node [shape = record, style=filled];\n"+self.interno()+"}\n")
        file.close()
        
        path_desktop = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        os.system('dot -Tsvg ArbolAVL.dot -o '+path_desktop+"/reportes_F3/ARBOLAVL.svg")
class AVL:

    def __init__(self):
        self.root = None
        self.tamaño = 0
        self.carnet =0;
        self.nodoNuevo2=None
        self.nodoNuevo3=None
        self.carnetEliminar = 0;
        

    def insert(self, carnet,value):
        node = Node(carnet,value)
        node.id=carnet
        if self.root is None:
            self.root = node
            self.root.cll = 0
            self.tamaño = 1
        else:
            dad_node = None
            nodoNuevo = self.root

            while True:
                if nodoNuevo is not None:

                    dad_node = nodoNuevo

                    if node.carnet < nodoNuevo.carnet:
                        nodoNuevo = nodoNuevo.izquierda
                    else:
                        nodoNuevo = nodoNuevo.derecha
                else:
                    node.cll = dad_node.cll
                    dad_node.cll += 1
                    if node.carnet < dad_node.carnet:
                        dad_node.izquierda = node
                    else:
                        dad_node.derecha = node
                    self.valance(node)
                    self.tamaño += 1
                    break

    def valance(self, node):
        n = node

        while n is not None:
            cll_derecha = n.cll
            cll_izquierda = n.cll

            if n.derecha is not None:
                cll_derecha = n.derecha.cll

            if n.izquierda is not None:
                cll_izquierda = n.izquierda.cll

            if abs(cll_izquierda - cll_derecha) > 1:
                if cll_izquierda > cll_derecha:
                    izquierda_child = n.izquierda
                    if izquierda_child is not None:
                        h_derecha = (izquierda_child.derecha.cll
                                    if (izquierda_child.derecha is not None) else 0)
                        h_izquierda = (izquierda_child.izquierda.cll
                                    if (izquierda_child.izquierda is not None) else 0)
                    if (h_izquierda > h_derecha):
                        self.rotacionIzquierda(n)
                        break
                    else:
                        self.DoblerotacionDerecha(n)
                        break
                else:
                    derecha_child = n.derecha
                    if derecha_child is not None:
                        h_derecha = (derecha_child.derecha.cll
                            if (derecha_child.derecha is not None) else 0)
                        h_izquierda = (derecha_child.izquierda.cll
                            if (derecha_child.izquierda is not None) else 0)
                    if (h_izquierda > h_derecha):
                        self.DoblerotacionIzquierda(n)
                        break
                    else:
                        self.rotacionDerecha(n)
                        break
            n = n.para

    def rotacionIzquierda(self, node):
        aux = node.para.DatosNodo
        node.para.DatosNodo = node.DatosNodo
        node.para.derecha = Node(aux)
        node.para.derecha.cll = node.para.cll + 1
        node.para.izquierda = node.derecha


    def rotacionDerecha(self, node):
        aux = node.para.DatosNodo
        node.para.DatosNodo = node.DatosNodo
        node.para.izquierda = Node(aux)
        node.para.izquierda.cll = node.para.cll + 1
        node.para.derecha = node.derecha

    def DoblerotacionIzquierda(self, node):
        self.rotacionDerecha(node.getderecha().getderecha())
        self.rotacionIzquierda(node)

    def DoblerotacionDerecha(self, node):
        self.rotacionIzquierda(node.getizquierda().getizquierda())
        self.rotacionDerecha(node)

    def falsoVerda(self):
        if self.root is None:
            return True
        return False

    def preShow(self, nodoNuevo):
        if nodoNuevo is not None:
            self.preShow(nodoNuevo.izquierda)
            print(nodoNuevo.DatosNodo)
            
            self.preShow(nodoNuevo.derecha)
    def iterar(self, nodoNuevo):
        
        if nodoNuevo is not None:
          
          
          self.iterar(nodoNuevo.izquierda)
          
          if(nodoNuevo.carnet == self.carnet):
            
            self.nodoNuevo3= nodoNuevo.DatosNodo
            print(nodoNuevo.DatosNodo)
          self.iterar(nodoNuevo.derecha)
          
    def actualizar(self, nodoNuevo,dato):
        if nodoNuevo is not None:
          self.actualizar(nodoNuevo.izquierda,dato)
          
          if(nodoNuevo.carnet == self.carnet):
           
            nodoNuevo.DatosNodo=dato
            
            print(nodoNuevo.DatosNodo + "ESTA ES UNA PRUEBA PORNO")
          self.actualizar(nodoNuevo.derecha,dato)       

    def buscar(self,carnet):
       
           self.carnet=carnet
    def buscar2(self,carnet):
       
           self.carnet=carnet
  
            
    def pre_orden(self, nodoNuevo):
        if nodoNuevo is not None:
            self.preShow(nodoNuevo.izquierda)
            self.preShow(nodoNuevo.derecha)
            print(nodoNuevo.DatosNodo, end=" ")

    def getRoot(self):
        return self.root
    
    def graficar(self):
        self.root.graficarArbolAVL()
    
    
 