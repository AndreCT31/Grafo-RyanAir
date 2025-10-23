import math
import csv




#Calculo la distancias entre dos coordenadas (lat y lon) usando la formula de Haversine. 
def distancias(coord1, coord2):
    R = 6371  # Radio de la Tierra en km
    lat1, lon1 = map(math.radians, coord1)
    lat2, lon2 = map(math.radians, coord2)
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    a = math.sin(dlat / 2) ** 2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2) ** 2
    return round(R * (2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))))



# Cargo todas las coordenadas desde el file que se genero en coords.py
coordenadas = {}
with open("destinosFinal.csv", newline='', encoding='utf-8') as file:
    reader = csv.reader(file)
    next(reader)  # Saltar encabezado si existe
    for fila in reader:
        if len(fila) < 3:
            continue
        nombre, lat, lon = fila[0], float(fila[1]), float(fila[2])
        coordenadas[nombre] = (lat, lon)
ciudades = list(coordenadas.keys())




# Genero el grafo siguiendo la estructura que uso en el codigo c++. Especificamente en el archivo grafo.cpp en la funcion cargar; la cual lee linea a linea todo el .txt hasta toparse con el delimitador "#", ya ahi comienza a establecer las aristas con sus respectivas distancias.
with open("grafo.txt", "w", encoding="utf-8") as f:
    # Escribir vértices
    for i, ciudad in enumerate(ciudades):
        f.write(f"{i} {ciudad}\n")
    f.write("#\n")

    # Escribir aristas con distancias
    for i in range(len(ciudades)):
        for j in range(i + 1, len(ciudades)):
            dist = distancias(coordenadas[ciudades[i]], coordenadas[ciudades[j]])
            f.write(f"{i} {j} {dist}\n")
