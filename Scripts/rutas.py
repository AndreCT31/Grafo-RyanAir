import requests
from bs4 import BeautifulSoup
import csv

# url cuyo sitio contiene los destinos de Ryanair
url = "https://brilliantmaps.com/flight-maps/ryanair-routes/"
r = requests.get(url)
soup = BeautifulSoup(r.text, "html.parser")

# despues de parsear inspecciono todos los <li> para piratear las ciudades
items = soup.find_all("li")
ciudades = []
for it in items:
    text = it.get_text().strip()
    if text:
        ciudades.append(text)

# quito duplicados
ciudades = list(set(ciudades))  

# guardo en un csv segun. pero pura vrg, no usa comas, me tooc hacer el jale a mano
with open("rutas_Ryan.csv", "w", newline='', encoding="utf-8") as f:
    writer = csv.writer(f)
    writer.writerow(["nombre"])
    for ciudad in sorted(ciudades):
        writer.writerow([ciudad])

print("Guardados", len(ciudades), "destinos.")