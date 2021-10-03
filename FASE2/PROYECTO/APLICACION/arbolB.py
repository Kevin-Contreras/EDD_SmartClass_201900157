import graphviz
import os
class Nodo:
    def __init__(self, hoja=False):
        self.hoja = hoja
        self.llaves = []
        self.ss = []
        


class BTree:
    def __init__(self, t):
        self.root = Nodo(True)
        self.t = t
        self.contador=0
        self.arreglo=[]
        self.estructuras = ""
        self.graficaContador=0
    def insert(self, k):
        root = self.root
        if len(root.llaves) == (2 * self.t) - 1:
            temporal = Nodo()
            self.root = temporal
            temporal.ss.insert(0, root)
            self.separar(temporal, 0)
            self.lleno(temporal, k)
        else:
            self.lleno(root, k)

    def lleno(self, x, k):
        i = len(x.llaves) - 1
        if x.hoja:
            x.llaves.append((None, None))
            while i >= 0 and k[0] < x.llaves[i][0]:
                x.llaves[i + 1] = x.llaves[i]
                i -= 1
            x.llaves[i + 1] = k
        else:
            while i >= 0 and k[0] < x.llaves[i][0]:
                i -= 1
            i += 1
            if len(x.ss[i].llaves) == (2 * self.t) - 1:
                self.separar(x, i)
                if k[0] > x.llaves[i][0]:
                    i += 1
            self.lleno(x.ss[i], k)

    def separar(self, x, i):
        t = self.t
        y = x.ss[i]
        z = Nodo(y.hoja)
        x.ss.insert(i + 1, z)
        x.llaves.insert(i, y.llaves[t - 1])
        z.llaves = y.llaves[t: (2 * t) - 1]
        y.llaves = y.llaves[0: t - 1]
        if not y.hoja:
            z.ss = y.ss[t: 2 * t]
            y.ss = y.ss[0: t - 1]

    def borrar(self, x, k):
        t = self.t
        i = 0
        while i < len(x.llaves) and k[0] > x.llaves[i][0]:
            i += 1
        if x.hoja:
            if i < len(x.llaves) and x.llaves[i][0] == k[0]:
                x.llaves.pop(i)
                return
            return

        if i < len(x.llaves) and x.llaves[i][0] == k[0]:
            return self.borrarNodo(x, k, i)
        elif len(x.ss[i].llaves) >= t:
            self.borrar(x.ss[i], k)
        else:
            if i != 0 and i + 2 < len(x.ss):
                if len(x.ss[i - 1].llaves) >= t:
                    self.bsg(x, i, i - 1)
                elif len(x.ss[i + 1].llaves) >= t:
                    self.bsg(x, i, i + 1)
                else:
                    self.bmar(x, i, i + 1)
            elif i == 0:
                if len(x.ss[i + 1].llaves) >= t:
                    self.bsg(x, i, i + 1)
                else:
                    self.bmar(x, i, i + 1)
            elif i + 1 == len(x.ss):
                if len(x.ss[i - 1].llaves) >= t:
                    self.bsg(x, i, i - 1)
                else:
                    self.bmar(x, i, i - 1)
            self.borrar(x.ss[i], k)

    def borrarNodo(self, x, k, i):
        t = self.t
        if x.hoja:
            if x.llaves[i][0] == k[0]:
                x.llaves.pop(i)
                return
            return

        if len(x.ss[i].llaves) >= t:
            x.llaves[i] = self.Bprede(x.ss[i])
            return
        elif len(x.ss[i + 1].llaves) >= t:
            x.llaves[i] = self.Bsucessor(x.ss[i + 1])
            return
        else:
            self.bmar(x, i, i + 1)
            self.borrarNodo(x.ss[i], k, self.t - 1)

    def Bprede(self, x):
        if x.hoja:
            return x.pop()
        n = len(x.llaves) - 1
        if len(x.ss[n].llaves) >= self.t:
            self.bsg(x, n + 1, n)
        else:
            self.bmar(x, n, n + 1)
        self.Bprede(x.ss[n])

    def Bsucessor(self, x):
        if x.hoja:
            return x.llaves.pop(0)
        if len(x.ss[1].llaves) >= self.t:
            self.bsg(x, 0, 1)
        else:
            self.bmar(x, 0, 1)
        self.Bsucessor(x.ss[0])

    def bmar(self, x, i, j):
        cnode = x.ss[i]

        if j > i:
            rsnode = x.ss[j]
            cnode.llaves.append(x.llaves[i])
            for k in range(len(rsnode.llaves)):
                cnode.llaves.append(rsnode.llaves[k])
                if len(rsnode.ss) > 0:
                    cnode.ss.append(rsnode.ss[k])
            if len(rsnode.ss) > 0:
                cnode.ss.append(rsnode.ss.pop())
            new = cnode
            x.llaves.pop(i)
            x.ss.pop(j)
        else:
            lsnode = x.ss[j]
            lsnode.llaves.append(x.llaves[j])
            for i in range(len(cnode.llaves)):
                lsnode.llaves.append(cnode.llaves[i])
                if len(lsnode.ss) > 0:
                    lsnode.ss.append(cnode.ss[i])
            if len(lsnode.ss) > 0:
                lsnode.ss.append(cnode.ss.pop())
            new = lsnode
            x.llaves.pop(j)
            x.ss.pop(i)

        if x == self.root and len(x.llaves) == 0:
            self.root = new

    def bsg(self, x, i, j):
        cnode = x.ss[i]
        if i < j:
            rsnode = x.ss[j]
            cnode.llaves.append(x.llaves[i])
            x.llaves[i] = rsnode.llaves[0]
            if len(rsnode.ss) > 0:
                cnode.ss.append(rsnode.ss[0])
                rsnode.ss.pop(0)
            rsnode.llaves.pop(0)
        else:
            lsnode = x.ss[j]
            cnode.llaves.insert(0, x.llaves[i - 1])
            x.llaves[i - 1] = lsnode.llaves.pop()
            if len(lsnode.ss) > 0:
                cnode.ss.insert(0, lsnode.ss.pop())

    def print_tree(self, x, l=0):
        print("Level ", l, " ", len(x.llaves), end=":")
        for i in x.llaves:
            print(list(i)[1], end=" ")
        print()
        l += 1
        if len(x.ss) > 0:
            for i in x.ss:
                self.print_tree(i, l)

    def ConcatenarArbolB(self, x, l=0):
        contador2=0
        
        for i in x.llaves:
            contador2=contador2+1
            self.estructuras= self.estructuras+"<f"+str(contador2)+">"+list(i)[1]+"|"
       
        l += 1
        self.arreglo.append(str(self.contador)+ "[shape=record,label="+'"'+self.estructuras+'"'+"]\n")
        self.contador=self.contador+1
        self.estructuras=""
        if len(x.ss) > 0:
            for i in x.ss:
                self.ConcatenarArbolB(i, l)
        
        
        


    def graficar(self,contadorGraf):
        file = open("ArbolB.dot","w",encoding='utf-8')
        file.write("digraph structs {")
        file.write("node [shape=record];")
        contador=0
        for dato in self.arreglo:
            file.write(dato)
        for struct in self.arreglo:
           
            if(contador !=0):
                file.write("0 -> "+str(contador)+"\n")
            contador=contador+1
        contador=0
        file.write("}")
        file.close()
        self.graficaContador = self.graficaContador+1
        path_desktop = os.path.join(os.path.join(os.environ['USERPROFILE']), 'Desktop')
        os.system('dot -Tsvg ArbolB.dot -o '+path_desktop+"/reportes_F2/ARBOLB_"+str(contadorGraf)+".svg")
        