$tablero=[["-","-","-"],["-","-","-"],["-","-","-"]]

def comprobar_posicion(x,y)

end

def comprobar_tablero
	chars=["X", "O"]
	chars.each do |sim|
		flag=true
		for i in (0...3)
			for j in (0...3)
				if $tablero[i][j]==sim
					flag=true
				else
					flag=false
					break
				end
			end
			if flag
				puts "Ganador #{sim}"
				return true
			end
		end

		for i in (0...3)
			if $tablero[i][i]==sim
				flag=true
			else
				flag=false
				break
			end
		end
		if flag
			puts "Ganador #{sim}"
			return true
		end
		for i in (0...3)
			if $tablero[i][2-i]==sim
				flag=true
			else
				flag=false
				break
			end
		end
		if flag
			puts "Ganador #{sim}"
			return true
		end
	end
	return false
end

def mostrar_tablero
	$tablero.each do |linea|
		linea.each{ |punto| print punto+" "}
		print "\n"
	end
	print "\n"
end

def validar
	valor=gets.to_i
	while valor<1 or valor>3
		print "Valor fuera de rango\nIngresa uno entre 1 y 3: "
		valor=gets.to_i
	end
	return valor
end

def ingresar(valor)
	puts "Ingresa los valores que se te pidan (1-3)"
	print "Ingresa la posicion en x: "
	x=validar
	x-=1
	print "Ingresa la posicion en y: "
	y=validar
	y-=1
	$tablero[x][y]=valor
end

def entrada_jugador(numero_jugada)
	if not numero_jugada%2==0
		puts "Turno jugador: O"
		ingresar("O")
	else
		puts "Turno jugador: X"
		ingresar("X")
	end
	puts `clear`
	mostrar_tablero
end

for i in (1..9)
	entrada_jugador(i)
	if comprobar_tablero
		break
	end
end
