import csv



#Saco las coordenadas de las ciudades usando esta libreria gratis que tope por internet. Aqui busco y extraigo por numero de columna y saltando la primer file (cabecera), toda la info la meto a este diccionario "coordenadas = {}"

coordenadas = {}
with open('worldcities.csv', newline='', encoding='utf-8') as file:
    reader = csv.reader(file)
    next(reader)  
    for fila in reader:
        if len(fila) < 4:
            continue
        nombre, lat, lon = fila[1].strip(), fila[2].strip(), fila[3].strip()
        coordenadas[nombre.lower()] = (float(lat), float(lon))




#Aqui extraigo del csv que me toco arreglar a mano las unicas dos columnas, las cuales son; [0] = origen y [1] = destino. Todo lo meto a una lista "destinos = []"
destinos = []
with open('destinos.csv', newline='', encoding='utf-8') as file:
    reader = csv.reader(file)
    next(reader)
    for fila in reader:
        if len(fila) < 2:  
            continue
        origen, destino = fila[0].strip(), fila[1].strip()
        if origen:
            destinos.append(origen.lower())
        if destino:
            destinos.append(destino.lower())

        
#Finalmente aqui junto todo y genero un nuevo csv con las ciudades que si encontre en el primer csv (worldcities.csv) y sus respectivas coordenadas latitud y longitud.
with open('destinosFinal.csv', 'w', newline='', encoding='utf-8') as outfile:
    writer = csv.writer(outfile)
    writer.writerow(['nombre', 'latitud', 'longitud'])
    encontrados = 0
    for ciudad in destinos:
        if ciudad in coordenadas:
            lat, lon = coordenadas[ciudad]
            writer.writerow([ciudad, lat, lon])
            encontrados += 1
    print(f'Se encontraron {encontrados} ciudades de {len(destinos)} destinos.')
