from os import system

tablero=[["-","-","-"],["-","-","-"],["-","-","-"]]

def comprobar_posicion(x,y):
	if tablero[x][y]!="-":
		print("casilla ocupada")
		return False
	return True

def comprobar_tablero():
	chars=["X","O"]
	for sim in chars:
		flag=True
		for i in range(0,3):
			for j in range(0,3):
				if tablero[i][j]==sim:
					flag=True
				else:
					flag=False
					break
			if flag:
				print(f"Ganador {sim}")
				return True
		for i in range(0,3):
			for j in range(0,3):
				if tablero[j][i]==sim:
					flag=True
				else:
					flag=False
					break
			if flag:
				print(f"Ganador {sim}")
				return True
		for i in range(0,3):
			if tablero[i][i]==sim:
				flag=True
			else:
				flag=False
				break
		if flag:
			print(f"Ganador {sim}")
			return True
		for i in range(0,3):
			if tablero[i][2-i]==sim:
				flag=True
			else:
				flag=False
				break
		if flag:
			print(f"Ganador #{sim}")
			return True
	return False

def mostrar_tablero():
	for linea in tablero:
		for punto in linea:
			print(f"{punto} ",end="")
		print()
	print()

def validar():
	valor=0
	flag=False
	while valor<1 or valor>3:
		try:
			valor=int(input())
		except:
			print("Valor fuera de rango\nIngresa uno entre 1 y 3: ", end="")
	return valor

def ingresar(valor):
	print("Ingresa los valores que se te pidan (1-3)")
	print("Ingresa la posicion en x: ",end="")
	x=validar()
	x-=1
	print("Ingresa la posicion en y: ",end="")
	y=validar()
	y-=1
	while not comprobar_posicion(x,y):
		print("Ingresa la posicion en x: ",end="")
		x=validar()
		x-=1
		print("Ingresa la posicion en y: ",end="")
		y=validar()
		y-=1
	tablero[x][y]=valor

def entrada_jugador(numero_jugada):
	if not numero_jugada%2==0:
		print("Turno jugador: O")
		ingresar("O")
	else:
		print("Turno jugador: X")
		ingresar("X")
	system("clear")
	mostrar_tablero()

for i in range(1, 10):
	entrada_jugador(i)
	if comprobar_tablero():
		break
	if i==9:
		print("No hay ganador")